#include <bits/stdc++.h>

using namespace std;

int main(){
	int soldiers, attacks, l, r; 

	cin >> soldiers >> attacks;

	while (soldiers or attacks){
		vector <int> buddy_l(soldiers + 2);
		vector <int> buddy_r(soldiers + 2);

		iota(buddy_l.begin() + 1, buddy_l.end(), 0);
		iota(buddy_r.begin(), buddy_r.end(), 1);

		buddy_l[0] = -1;
		buddy_r[soldiers+1] = -1;

		while(attacks--){
			cin >> l >> r;
			buddy_l[buddy_r[r]] = buddy_l[l];
			buddy_r[buddy_l[l]] = buddy_r[r];

			if(buddy_l[buddy_l[l]] == -1) cout << "* ";
			else cout << buddy_l[l] << " ";

			if(buddy_r[buddy_r[r]] == -1) cout << "*\n";
			else cout << buddy_r[r] << "\n";
		}
		cout << "-\n";
		cin >> soldiers >> attacks;
	}

	return 0;
}
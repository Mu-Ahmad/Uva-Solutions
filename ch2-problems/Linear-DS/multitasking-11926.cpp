#include <bits/stdc++.h>

using namespace std;

#define SIZE 1000001

int main(){

	int n, m;
	int x = 1;
	while(cin >> n >> m and (n or m)){
		// cout << x++ << ". " << n << ' ' << m << '\n';
		bitset <SIZE> interval(0); 

		int s, e, rep;
		bool conflict = false;

		while(n--){
			cin >> s >> e;

			if(!conflict)
			for (int i=s; i<e; i++)
				if(interval[i] == 1){
					// cout << i << '\n';
					conflict = true;
					break;
				}
				else	interval[i] = 1;
		}

		while(m--){
			cin >> s >> e >> rep;

			if(!conflict)
			for (;s<SIZE; s+=rep, e+=rep){
				for (int i=s; i<e and i<SIZE; i++)
					if(interval[i] == 1){
						conflict = true;
						break;
					}
					else	interval[i] = 1;
			}
		}

		if (conflict) cout << "CONFLICT\n";
		else cout << "NO CONFLICT\n";
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool checkConstraint(vector<int> seatings, int constraint[3]){
	int diff = abs ( find(seatings.begin(), seatings.end(), constraint[0]) -
					 find(seatings.begin(), seatings.end(), constraint[1]));

	// cout << diff << '\n';
	if (constraint[2] < 0) return diff >= abs(constraint[2]);
	return diff <= constraint[2];
}

int main(){
	int n, m;
	while(cin >> n >> m and (n or m)){
		int constraints[m][3];
		for (int i=0; i<m; i++)
			cin >> constraints[i][0] >> constraints[i][1] >> constraints[i][2];

		vector<int> seatings(n);
		iota(seatings.begin(), seatings.end(), 0);
		int ans = 0;
		do {
			ans++;
			for (int i=0; i<m; i++)
				if (!checkConstraint(seatings, constraints[i])) {
					ans--;
					break;
				}

		} while (next_permutation(seatings.begin(), seatings.end()));
	
		cout << ans << "\n";
	}
	return 0;
}




#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, idx, t; cin >> t;

	while (t--){
		cin >> n >> m;
		vector <bool> teams(1 << n, 1);

		for (int i=0; i < m; i++) {
			cin >> idx;
			teams[idx - 1] = false; 
		}

		vector <bool> temp;
		int ans = 0;
		while(teams.size() != 1){
			for (int i=0; i<teams.size(); i+=2)
				if (teams[i] and teams[i+1])
					temp.push_back(true);
				else if (teams[i] or teams[i+1]){
					temp.push_back(true);
					ans++;
				}
				else temp.push_back(false);

			teams = temp;
			temp.clear();
		}
		cout << ans << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;

	while(n--){
		int t ; cin >> t;

		unordered_map<char, int> costTable;
		char ch; int val;

		while(t--){
			cin >> ch >> val;
			costTable[ch] = val;
		}

		long long cost = 0;

		string line;
		cin >> t;
		cin.ignore();
		while(t--){
			getline(cin, line);
			// cout << line << '\n';
			for (auto& ch: line)
				cost += costTable[ch];
		}
		cout << fixed << setprecision(2) << cost / 100.0 << "$\n";
		// break;
	}

	return 0;
}
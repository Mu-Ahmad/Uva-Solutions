#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	int x = 1;
	while (t--){
		int n; cin >> n;
		vector<char> field(n);

		for (int i=0; i<n; i++)
			cin >> field[i];	

		int ans = 0;
		for (int i=1; i<n-1; i++)
			if (field[i-1] == '.') {
				ans++;
				field[i-1] = field[i] = field[i+1] = '#';
			}

		if (field[n-1] == '.' or field[n-2] == '.') ans++;
		printf("Case %d: %d\n", x++, ans);
	}

	return 0;
}
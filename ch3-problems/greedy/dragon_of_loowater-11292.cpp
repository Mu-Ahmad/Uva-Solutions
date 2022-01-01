#include <bits/stdc++.h>
#define each const auto&

using namespace std;

int main(){
	int n, m;

	while(cin >> n >> m and (n or m)){
		vector<int> dragons(n), knights(m);

		for(int i=0; i<n; i++) cin >> dragons[i];
		for(int i=0; i<m; i++) cin >> knights[i];

		sort(knights.begin(), knights.end());

		long long ans = 0;
		bool doomed = false;
		for (each dragon: dragons) {
			auto it = lower_bound(knights.begin(), knights.end(), dragon);

			if (it == knights.end()) {doomed = true; break;}

			ans += *it;
			knights.erase(it);
		}

		if (doomed) printf("Loowater is doomed!\n");
		else printf("%d\n", ans);
	}
	return 0;
}
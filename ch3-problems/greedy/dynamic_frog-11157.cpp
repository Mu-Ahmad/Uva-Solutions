#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, x = 1; cin >> t;
	while(t--){
		int n, d;
		cin >> n >> d;

		char symbol, ignore;
		int dist;
		vector <pair<char, int>> stones;
		stones.push_back({'B', 0}); // insert start
		for(int i=0; i<n; i++) {
			cin >> symbol >> ignore >> dist;
			stones.push_back({symbol, dist});
		}
		stones.push_back({'B', d}); // insert end

		int ans = 0, last = 0;
		for(int i=1; i<stones.size(); i++)
			if (stones[i].first == 'B'){
				ans = max(ans, stones[i].second - last);
				last = stones[i].second;
			} else if (stones[i-1].first != 'X'){
				ans = max(ans, stones[i].second - last);
				last = stones[i].second;
				stones[i].first = 'X';
			}
		

		last = (stones.end()-1)->second;
		for(int i=stones.size()-2; i>=0; i--){	
			if (stones[i].first == 'X') continue;

			ans = max(ans, last-stones[i].second);
			last = stones[i].second;
		
		}

		printf("Case %d: %d\n", x++, ans);
	}
}
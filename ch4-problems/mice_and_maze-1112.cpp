#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int nodes, source, T, edges, to, from, weight, _weight;
vector<int> d(105);

void dijkstra(vector<vector<pii>>& adj_list, int s){
	priority_queue <pii, vector<pii>, greater<pii>> Q;
	d[s] = 0, Q.push({0, s});

	while(!Q.empty()) {
		tie(weight, from) = Q.top(), Q.pop();

		for (auto u : adj_list[from]){
			tie(_weight, to) = u;

			if (weight + _weight < d[to])
				d[to] = weight + _weight, Q.push({d[to], to});
		}
	}

}

int main(){
	int t; cin >> t;
	bool first = true;
	while(t--){
		cin >> nodes >> source >> T >> edges; source--;
		vector<vector<pii>> adj_list(nodes);

		while(edges--){
			cin >> from >> to >> weight;
			adj_list[from-1].push_back({weight, to-1});
		}	

		int ans = 0;
		for (int i=0; i<nodes; i++){
			d.assign(105, 999999);
			dijkstra(adj_list, i);
			if (d[source]<=T) ans++;
		}

		if(!first) puts(""), first = false;
		printf("%d\n", ans);
	}

	return 0;
}
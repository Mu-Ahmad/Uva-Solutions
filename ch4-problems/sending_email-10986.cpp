#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int n, e;
vector<int> d(20005);

void dijkstra(vector<vector<pii>> adj_list, int s){
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	d[s] = 0;
	Q.push({0, s});
	int t, f, w1, w2;

	while(!Q.empty()){
		tie(w1, f) = Q.top(), Q.pop();

		for (auto u : adj_list[f]){
			tie(w2, t) = u;
			if (w1+w2 < d[t]){
				d[t] = w1 + w2;
				Q.push({d[t], t});
			}
		}
	}
}

int main(){
	int a, b, w, t, source, destination; cin >> t;
	int x = 1;
	while(t--){
		cin >> n >> e >> source >> destination;
		vector<vector<pii>> adj_list(n);

		while(e--){
			cin >> a >> b >> w;
			adj_list[a].push_back({w, b});
			adj_list[b].push_back({w, a});
		}

		d.assign(20005, 999999);

		dijkstra(adj_list, source);

		printf("Case #%d: ", x++);
		if (d[destination] == 999999) puts("unreachable");
		else printf("%d\n", d[destination]);
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, w;

	int nodes, edges;
	int x = 1;
	while(cin >> nodes >> edges and (nodes or edges)){
		

		vector < vector< pair<int, int> > > adj_list(nodes);

		for (int i=0; i<edges; i++){
			cin >> a >> b >> w;
			a--, b--;
			adj_list[a].push_back({b, w-1});
			adj_list[b].push_back({a, w-1});
		}

		double total;
		cin >> a >> b >> total;
		a--, b--;

		vector <int> flow(nodes, -100), visited(nodes, 0);

		queue<int> q;

		q.push(a);
		flow[a] = 1000000;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (auto u : adj_list[v]){
					if (flow[u.first] < min(flow[v], u.second)){
						q.push(u.first);
						flow[u.first] = min(flow[v], u.second);
					}
				}
		}

		cout << "Scenario #" << x++
			 << "\nMinimum Number of Trips = ";

			cout << ceil (total / flow[b])  << "\n\n";
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > adj_list;
vector<int> d;
vector<bool> visited;
int E;

void bfs(int source){
	d.assign(E, -1);
	visited.assign(E, false);

	queue<int> Q;
	Q.push(source);
	d[source] = 0;
	visited[source] = true;

	while(!Q.empty()){
		int v = Q.front(); Q.pop();

		for (auto u : adj_list[v])
			if(!visited[u]) {
				visited[u] = true;
				d[u] = d[v] + 1;
				Q.push(u);
			}
	}
}

int main(){
	int temp, n; cin >> E;
	adj_list = vector <vector <int>> (E);
	d = vector <int>(E, -1);
	visited = vector <bool>(E, 0);

	for (int i=0; i<E; i++){
		cin >> n;
		while(n--) cin >> temp, adj_list[i].push_back(temp);
		
	}

	int source, t; cin >> t;
	while(t--){
		cin >> source;
		bfs(source);
		int maxDays = *max_element(d.begin(), d.end());
		if (maxDays == 0) cout << "0\n";
		else {
			vector <int> freq(maxDays+1, 0);
			for (const auto& di: d) if (di > 0) freq[di]++;
			int maxBoom = *max_element(freq.begin(), freq.end());

			int i = 0;
			for (; i<=maxDays; )if (freq[++i] == maxBoom) break;

			cout << maxBoom << " " << i << "\n"; 
		}
	}


	return 0;
}
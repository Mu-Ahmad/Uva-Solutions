#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > neighbours;

void dfs(bool* visited, int curr){
	visited[curr] = true;

	for (auto& neighbour : neighbours[curr])
		if(!neighbour[visited])
			dfs(visited, neighbour);

	return;
}

int main(){
	int t; cin >> t;
	string line;

	while(t--){
		char last; cin >> last; cin.ignore();
		int size = last - 'A' + 1;
		neighbours = vector < vector<int> > (size, vector<int>());
		
		while(1){
			getline(cin, line);
		
			if (line.size() < 1) break;
			
			neighbours[line[0] - 'A'].push_back(line[1] - 'A');
			neighbours[line[1] - 'A'].push_back(line[0] - 'A');
		}

		bool visited[size] = {0};
		int count = 0;
		for (int i=0; i<size; i++)
			if (!visited[i]){
				count++;
				dfs(visited, i);
			}
		
		printf("%d\n", count);
		if(t) puts("");
	}

	return 0;
}
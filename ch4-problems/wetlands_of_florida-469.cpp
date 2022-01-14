#include <bits/stdc++.h>

using namespace std;

vector< string > grid;

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int dfs(int x, int y){ 
	if (x < 0 or x >=grid.size() or y < 0 or y >=grid[0].size()) return 0;
	if (grid[x][y] == 'L') return 0;

	grid[x][y] = 'L';
	int ans = 0;
	for (int i=0; i<8; i++)
		ans += dfs(x+dx[i], y+dy[i]);

	return ans + 1;
}

int main(){
	int t, x, y; cin >> t; cin.ignore(); cin.ignore();
	string line;

	while(t--){
		char last;
		grid = vector < string >(0);
		
		while(1){
			getline(cin, line);

			if (line[0] != 'L' and line[0] != 'W') 
				break;
				
			grid.push_back(line);
		}

		istringstream in(line);

		while(1){
			in >> x >> y;

			auto tempGrid = grid;			
			printf("%d\n", dfs(x-1, y-1));
			grid = tempGrid;

			getline(cin, line);
			if (line.size() < 1) break;
			in = istringstream(line);
		}
		if(t) puts("");
	}
	return 0;
}
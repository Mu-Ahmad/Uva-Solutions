#include <bits/stdc++.h>

using namespace std;
int R, C;

vector <vector <int>> grid;

int bfs(int r1, int c1, int r2, int c2){
	queue < pair<int, int> > Q;

	Q.push({r1, c1});
	int r, c;
	while (!Q.empty()) {
		tie (r, c) = Q.front(); Q.pop();

		if (r == r2 and c == c2) return grid[r][c];

		// move Upward
		if (r > 0 and grid[r-1][c] == 0){
			grid[r-1][c] = grid[r][c] + 1;
			Q.push({r-1, c});
		}

		// move Downward
		if (r < R - 1 and grid[r+1][c] == 0){
			grid[r+1][c] = grid[r][c] + 1;
			Q.push({r+1, c});
		}


		// move forward
		if (c < C-1 and grid[r][c+1] == 0){
			grid[r][c+1] = grid[r][c] + 1;
			Q.push({r, c+1});
		}

		// move backward
		if (c > 0 and grid[r][c-1] == 0){
			grid[r][c-1] = grid[r][c] + 1;
			Q.push({r, c-1});
		}
	}

	return grid[r2][c2];

}

int main(){
	while(cin >> R >> C and (R or C)){
		grid = vector <vector <int>>(R, vector<int>(C, 0));

		int rowNo, colNo, bombCount, bombedRows; 
		cin >> bombedRows;
		while(bombedRows--){
			cin >> rowNo >> bombCount;
			while(bombCount--) cin >> colNo, grid[rowNo][colNo] = -1;
		}

		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		cout << bfs(r1, c1, r2, c2) << '\n';
	}
}
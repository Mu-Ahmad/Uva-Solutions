#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int grid[2001][2001];
queue <pii> Q;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int bfs(){
	int y, x, _y, _x;
	while(!Q.empty()){
		tie(_y, _x) = Q.front(); Q.pop();

		for (int i=0; i<4; i++){
			y = _y + dy[i];
			x = _x + dx[i];

			if (y>=0 and y<=2000 and x>=0 and x<=2000){
				if (grid[y][x] == -1){
					grid[y][x] = grid[_y][_x] + 1;
					Q.push({y, x});
				} else if (grid[y][x] == -69) return grid[_y][_x] + 1;
			}
		}
	}

	return -1;
}

int main(){
	int p, y, x;
	while(cin >> p and p){
		memset(grid, -1, 2001*2001*4);
		Q = queue<pii>();

		while(p--) {
			cin >> y >> x;
			grid[y][x] = 0;
			Q.push({y, x});
		} cin >> p;
		while (p--){
			cin >> y >> x;
			grid[y][x] = -69;
		}

		cout << bfs() << '\n';
	}
	return 0;
}
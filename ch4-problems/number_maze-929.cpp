#include <bits/stdc++.h>
#define pii pair<int, pair<int, int>>

using namespace std;

int R, C;
int grid[1000][1000];
int d[1000][1000];

void dijkstra() {
	d[0][0] = grid[0][0];
	priority_queue <pii, vector<pii>, greater<pii>> Q;
	Q.push({d[0][0], {0, 0}});

	int y, x, currDistance;
	while(!Q.empty()) {
		auto u = Q.top(); Q.pop();

		currDistance = u.first;
		tie(y, x) = u.second;

		// move down
		if (y>0 and currDistance + grid[y-1][x] < d[y-1][x]){
			d[y-1][x] = currDistance + grid[y-1][x];
			Q.push({d[y-1][x], {y-1, x}});
		}

		// move up
		if (y<R-1 and currDistance + grid[y+1][x] < d[y+1][x]){
			d[y+1][x] = currDistance + grid[y+1][x];
			Q.push({d[y+1][x], {y+1, x}});
		}

		// move left
		if (x>0 and currDistance + grid[y][x-1] < d[y][x-1]){
			d[y][x-1] = currDistance + grid[y][x-1];
			Q.push({d[y][x-1], {y, x-1}});
		}

		// move right
		if (x<C-1 and currDistance + grid[y][x+1] < d[y][x+1]){
			d[y][x+1] = currDistance + grid[y][x+1];
			Q.push({d[y][x+1], {y, x+1}});
		}
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> R >> C;
		for (int i=0; i<R; i++)
			for (int j=0; j<C; j++){
				cin >> grid[i][j];
				d[i][j] = 99999;
			}
		dijkstra();
		cout << d[R-1][C-1] << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int R, C;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int grid[50][50];
bool visited[55][55][4];

struct Node {
	int r, c, dir, time;

	Node(int r, int c, int dir, int time) 
		: r(r), c(c), dir(dir), time(time) 
		{}
};

bool isValid(int r, int c){
	if (r<=0 or r>=R or c<=0 or c>=C) return false;

	if (grid[r-1][c-1]) return false;
	if (grid[r-1][c]) return false;
	if (grid[r][c-1]) return false;
	if (grid[r][c]) return false;

	return true;
}

int bfs(int r1, int c1, int r2, int c2, int dir){
	queue<Node> Q;

	if (isValid(r1, c1)) Q.push(Node(r1, c1, dir, 0));
	visited[r1][c1][dir] = true;

	while (!Q.empty()){
		auto curr = Q.front(); Q.pop();

		if (curr.r == r2 and curr.c == c2) return curr.time;

		// Take turns
		if (!visited[curr.r][curr.c][(curr.dir+1) % 4]) {
			Q.push(Node(curr.r, curr.c, (curr.dir+1) % 4, curr.time+1));
			visited[curr.r][curr.c][(curr.dir+1) % 4] = true;
		} 

		if (!visited[curr.r][curr.c][(curr.dir+3) % 4]) {
			Q.push(Node(curr.r, curr.c, (curr.dir+3) % 4, curr.time+1));
			visited[curr.r][curr.c][(curr.dir+3) % 4] = true;
		}

		//Try Visiting all three points in same direction
		for (int i=1; i<=3; ++i){
			if (isValid(curr.r + dr[curr.dir]*i, curr.c + dc[curr.dir]*i)){
				if (!visited[curr.r + dr[curr.dir]*i][curr.c + dc[curr.dir]*i][curr.dir]){
					visited[curr.r + dr[curr.dir]*i][curr.c + dc[curr.dir]*i][curr.dir] = true;
					Q.push(Node(curr.r + dr[curr.dir]*i, curr.c + dc[curr.dir]*i, curr.dir, curr.time+1));
				}
			} else break;
		}
	}

	return -1;
}

int main(){
	while(cin >> R >> C and (R or C)){
		bool temp;
		for (int i=0; i<R; i++)
			for (int j=0; j<C; j++){
				cin >> grid[i][j];
				for (int k=0; k<4; k++) visited[i][j][k] = false;
			}

		int r1, c1, r2, c2, dir;
		cin >> r1 >> c1 >> r2 >> c2;

		string direction; cin >> direction;

		switch (direction[0]) {
			case 'n' : dir = 0; break;
			case 'e' : dir = 1; break;
			case 's' : dir = 2; break;
			default  : dir = 3;
		}

		cout << bfs(r1, c1, r2, c2, dir) << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};

bool valid(int y, int x, int r, int c){
	return (y >=0 and y<r and x>=0 and x<c);
}

int main(){
	int r, c, n;
	int y, x, t=1;
	while(cin >> r >> c >> n and (r or c or n)){
		vector<bool> rows(r, true), cols(c, true);

		while(n--){
			cin >> y >> x;
			rows[y] = false;
			cols[x] = false;
		}

		cin >> y >> x;

		bool ans = false;

		for (int i=0; i<5; i++){
			int _x = x+dx[i];
			int _y = y+dy[i];

			if (valid(_y, _x, r, c))
				ans |= (rows[_y] and cols[_x]);
			
		}

		if (ans) cout << "Case "<< t++ <<": Escaped again! More 2D grid problems!\n";
		else cout << "Case "<< t++ <<": Party time! Let's find a restaurant!\n";
	}

	return 0;
}
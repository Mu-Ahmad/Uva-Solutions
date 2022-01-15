#include <bits/stdc++.h>

using namespace std;

int H, W; 
char hexChar;
int grid[215][215];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int x = 1;

void dfs(int y, int x, int validSymbol, int replaceWith){
	grid[y][x] = replaceWith;

	for (int i=0; i<4; i++){
		int newY = y + dy[i];
		int newX = x + dx[i];

		if (newY < 0 or newY >= H or newX < 0 or newX >= W)
			continue;
		if (grid[newY][newX] != validSymbol) continue;

		dfs(newY, newX, validSymbol, replaceWith);
	}
}

int main(){
	unordered_map<char, string> bin;
	bin['0'] = "0000";
	bin['1'] = "0001";
	bin['2'] = "0010";
	bin['3'] = "0011";
	bin['4'] = "0100";
	bin['5'] = "0101";
	bin['6'] = "0110";
	bin['7'] = "0111";
	bin['8'] = "1000";
	bin['9'] = "1001";
	bin['a'] = "1010";
	bin['b'] = "1011";
	bin['c'] = "1100";
	bin['d'] = "1101";
	bin['e'] = "1110";
	bin['f'] = "1111";

	while (cin >> H >> W and (W or H)){
		// Reset the grid
		for (int i=0; i<215; i++)
			for (int j=0; j<215; j++)
				grid[i][j] = 0;

		// Picture is encoded sp first decode it
		for (int i=0; i<H; i++)
			for (int j=0; j<W; j++){
				cin >> hexChar;
				for (int k=0; k<4; k++)
					grid[i+1][j*4 + k + 1] = bin[hexChar][k] - '0';
			}

		// New Height and Width, also added frame ensuring the background
		W = W*4 + 2;
		H += 2;
		// Separating the background whitespace from white holes
		dfs(0, 0, 0, -8);

		// 0 is white 1 is black so starting from 2
		int shapeNo = 2;
		for (int i=0; i<H; i++)
			for (int j=0; j<W; j++)
				if (grid[i][j] == 1) {
					dfs(i, j, 1, shapeNo);
					shapeNo++;
				}

		int whiteHoles[shapeNo] = {0};
		for (int i=0; i<H; i++)
			for (int j=0; j<W; j++)
				if (grid[i][j] == 0){
					dfs(i, j, 0, -5);
					whiteHoles[grid[i][j-1]]++;
				}

		vector<char> ans;
		string code = "WAKJSD";
		for (int i=2; i<shapeNo; i++)
			ans.push_back(code[whiteHoles[i]]);

		sort(ans.begin(), ans.end());

		printf("Case %d: ", x++);
		for (auto ch : ans)
			printf("%c", ch);
		puts("");
	}

	return 0;
}

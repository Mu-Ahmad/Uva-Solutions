#include <bits/stdc++.h>
#define isSafe(x) x < n and x >=0

using namespace std;
int m, n; 
vector<string> largeBlock, smallBlock;


bool mapIt(int a, int b, int y, int x){
	int offSetX = b - x;

	for (int i=y; i<m; i++, a++)
		for (int j=0; j<m; j++)
			if (smallBlock[i][j] == '*'){
				if(isSafe(j+offSetX) and smallBlock[i][j] == largeBlock[a][j + offSetX]) 
					largeBlock[a][j + offSetX] = '.';
				else 
					return false;
			}
	
	return true;
}

int main(){
	while(cin >> n >> m and (n and m)){
		int y = -1, x = -1;
		bool sol = true;
		largeBlock.resize(n);
		smallBlock.resize(m);
		for (int i=0; i<n; i++) cin >> largeBlock[i];
		for (int i=0; i<m; i++) cin >> smallBlock[i];

		bool found = false;
		for (int i=0; i<m; i++){
			for (int j=0; j<m; j++){
				if (smallBlock[i][j] == '*'){					
					y = i; x = j;
					found = true;
					break;
				}
			}
			if (found) break;
		}

		int count = 2;
		for (int i=0; i<n and count; i++)
			for (int j=0; j<n and count; j++)
				if (largeBlock[i][j] == '*') 
					if (count--) sol = mapIt(i, j, y, x);
					else {
						// cout << i << " : " << j << "\n";
						sol = false;
					}

		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (largeBlock[i][j] == '*') sol = false;

		cout << (sol ? "1\n" : "0\n");
	}
	return 0;
}
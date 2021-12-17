#include <bits/stdc++.h>

using namespace std;

int n, r, c, battles;

bool valid(int i, int j){
	return (i>=0 and i<r
		and j>=0 and j<c);
}

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
	
	// reading in the test case
	while(cin >> n >> r >> c >> battles and (n and r and c and battles)){
		vector < vector<int> > kingdom(r, vector<int>(c));
		
		// reading in the initial state
		for (int i=0; i<r; i++)
			for (int j=0; j<c; j++)
				cin >> kingdom[i][j];

		auto previousState = kingdom;

		// simulting all the battles
		while(battles--){
			for (int i=0; i<r; i++)
				for (int j=0; j<c; j++){
					for (int k=0; k<4; k++)
						if (valid(i + d[k][0], j + d[k][1]) 
							and previousState[i + d[k][0]][j + d[k][1]] == (previousState[i][j] + 1) % n)
							kingdom[i + d[k][0]][j + d[k][1]] = previousState[i][j];
			}
			previousState = kingdom;
		}

		// printing the last state
		for (int i=0; i<r; i++){
			for (int j=0; j<c; j++){
				if (j) cout << ' ';
				cout << kingdom[i][j];
			}
			cout << "\n"; 
		}

	}
	return 0;
}
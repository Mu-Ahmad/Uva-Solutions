#include <bits/stdc++.h>

using namespace std;

template<typename Matrix>
void rotateMatrix(Matrix& matrix){
	Matrix tempMatrix = matrix;
	int n = matrix.size();

	for(int col=0;col<n;col++){
        int x=0;
        for(int row=n-1;row>=0;row--){
            tempMatrix[col][x] = matrix[row][col];
            x++;
        }
    }
	matrix = tempMatrix;
}

template<typename Matrix>
int matchMatrix(Matrix& smallMatrix, Matrix& largeMatrix, int offsetX, int offsetY){
	for(int i=0; i<smallMatrix.size(); i++)
		for(int j=0; j<smallMatrix.size(); j++)
			if (smallMatrix[i][j] != largeMatrix[i+offsetX][j+offsetY])
				return 0;

	return 1;
}

int main(){
	int N, n; cin >> N >> n; cin.ignore();
	int x = 4;
	bool first = true;
	while (N or n){
		// Read in the input
		vector <vector <char>> largeMatrix(N, vector <char>(N));
		vector <vector <char>> smallMatrix(n, vector <char>(n));

		string line;
		for (int i=0; i<N; i++){
			getline(cin, line);
			for (int j=0; j<N; j++)
				largeMatrix[i][j] = line[j];
		}

		for (int i=0; i<n; i++){
			getline(cin, line);
			for (int j=0; j<n; j++)
				smallMatrix[i][j] = line[j];
		}

		// Rotate and test
		int ans = 0;
		for (int i=0; i<4; i++){
			if(i)
				cout << ' ';

			for (int i=0; i<=N-n; i++)
				for (int j=0; j<=N-n; j++)
					ans += matchMatrix(smallMatrix, largeMatrix, i, j);

			cout << ans;
			ans = 0;
			rotateMatrix(smallMatrix);
		} 
		cout << '\n';

		cin >> N >> n; cin.ignore();
	}
	return 0;
} 
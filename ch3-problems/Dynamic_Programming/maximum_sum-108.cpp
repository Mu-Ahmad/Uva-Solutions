#include <bits/stdc++.h>

using namespace std;
int n;
int grid[101][101];

int maxSubArraySum(int* arr) {

	int ans = INT_MIN, a = 0;
	for (int i=0; i<n; i++) {
		a += arr[i];
		ans = max(ans, a);
		a = max(a, 0);
	}

	return ans;
}


int main(){

	while(cin >> n){
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				cin >> grid[i][j];
	

		int rectSum, maxRectSum = INT_MIN;
		for (int l=0; l<n; l++){
			int runningArray[n] = {0}; 
			for (int r=l; r<n; r++){
	
				for (int i=0; i<n; i++)
					runningArray[i] += grid[i][r];
				
				rectSum = maxSubArraySum(runningArray);
				
				maxRectSum = max(rectSum, maxRectSum);
			}
		}
	
		printf("%d\n", maxRectSum);
	}
	return 0;
}
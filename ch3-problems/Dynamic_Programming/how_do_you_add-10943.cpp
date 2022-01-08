#include <bits/stdc++.h>
#define MOD 1000000

using namespace std;

vector<vector<int>> dp(105, vector<int>(105, 0));

int solve(int k, int n){
	if (k == 1) return 1;

	if (dp[k][n]) return dp[k][n];

	int ans = 0;
	for (int i=0; i<=n; i++)
		(ans += solve(k-1, n-i)) %= MOD;

	return dp[k][n] = ans;
}

int main(){
	int n = 101, k = 101;

	vector<vector<int>> dp1(105, vector<int>(105, 0));
	for (int j=0; j<=n; j++)
		dp1[1][j] = 1;

	for (int i = 2; i<=k; i++){
		dp1[i][0] = 1;
		for (int j = 1; j<=n; j++)
			for (int k=0; k<=j; k++)
				(dp1[i][j] += dp1[i-1][j-k]) %= MOD;
		
	}
	while(cin >> n >> k and (n or k)){
		// printf("%d\n", solve(k, n));
		printf("%d\n", dp1[k][n]);
	}
	

	return 0;
}
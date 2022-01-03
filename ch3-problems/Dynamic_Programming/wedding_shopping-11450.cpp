#include <bits/stdc++.h>
#define each const auto&

using namespace std;

vector<vector<int>> dp;
int m, c;

template <class T>
int shop(const T& garments, int money, int curr){
	// out of budget
	if (money < 0) return -9999999;

	// selected all solutions
	if (curr == garments.size()) return m - money;

	// dp case
	if (dp[money][curr]) return dp[money][curr];

	int ans = -9999999;
	for (each itemPrice: garments[curr])
		ans = max(ans, shop(garments, money-itemPrice, curr+1));

	return dp[money][curr] = ans;
}

int main(){
	int n, temp; cin >> n;
	while(n--){
		cin >> m >> c;
		vector < vector<int> > garments(c, vector<int>());

		dp = vector <vector<int> > (m+5, vector<int>(c, 0));


		for (int i=0; i<c; i++){
			int k; cin >> k;
			while (k--){
				cin >> temp;
				garments[i].push_back(temp);
			}
		}

		int ans = shop(garments, m, 0);

		if (ans>0) printf("%d\n", ans);
		else puts("no solution");
	}
	return 0;
}
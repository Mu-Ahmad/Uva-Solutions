#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > ans;
set <int> divisors;

void getFactorization(int n, set<int>::iterator it, vector<int> vi){
	// Base Case
	if (n==1){
		ans.push_back(vi);
		return;
	}

	// Recursive Case
	for (; it!=divisors.end(); it++)
		if(n % *it == 0){
			vi.push_back(*it);
			getFactorization(n/(*it), it, vi);
			vi.pop_back();
		}
	return;
}

int main(){
	int n;
	while(cin >> n and n){
		ans.clear();
		divisors.clear();

		// List All divisors
		for (int i=2; i*i <= n; i++)
			if (n % i == 0){
				divisors.insert(i);
				divisors.insert(n/i);
			}
		

		if (n>1)
			getFactorization(n, divisors.begin(), vector<int>());

		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)
			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << (j + 1 == ans[i].size()?"\n":" ");
		
	}

	return 0;
}
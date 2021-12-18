#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;

	while(cin >> n){
		vector<int> corners(1 << n);

		for (int i=0; i < (1<<n); i++)
			cin >> corners[i];

		vector<long long> potency(1 << n, 0);

		for (int i=0; i < (1<<n); i++)
			for (int j=0; j<n; j++)
				potency[i] += corners[i ^ (1<<j)];

		long long maxPotency = 0;
		for (int i=0; i < (1<<n); i++)
			for (int j=0; j<n; j++)
				maxPotency = max(maxPotency, potency[i]+potency[i ^ (1<<j)]);
	
		cout << maxPotency << '\n';
	}

	return 0;
}
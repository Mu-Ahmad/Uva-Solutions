#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, d, r;

	while(cin >> n >> d >> r and (n or d or r)){
		vector<int> mor(n), aft(n);

		for (int i=0; i<n; i++) cin >> mor[i];
		for (int i=0; i<n; i++) cin >> aft[i];

		sort(mor.begin(), mor.end());
		sort(aft.begin(), aft.end(), greater<int>());

		for (int i=0; i<n; i++)
			mor[i] += aft[i];

		long long overTime = 0;

		for (int i=0; i<n; i++)
			if (mor[i]>d) overTime += (mor[i] - d)*r;

		cout << overTime << '\n';
	}

	return 0;
}
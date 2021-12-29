#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> ladyChimps(n);
	for (int i=0; i<n; i++)
		cin >> ladyChimps[i];

	int Q, a, b; cin >> Q;

	while(Q--){
		cin >> a;

		auto it1 = lower_bound(ladyChimps.begin(), ladyChimps.end(), a);
		auto it2 = upper_bound(ladyChimps.begin(), ladyChimps.end(), a);

		
		if (it1 == ladyChimps.end() or it1 == ladyChimps.begin()) cout << "X ";
		else cout << *(it1 - 1) << " ";

		if (it2 == ladyChimps.end()) cout << "X\n";
		else cout << *it2 << "\n";
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, n, k; cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << (k ^ (k >> 1)) << '\n';
	}
	return 0;
}

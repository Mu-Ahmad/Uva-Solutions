#include <bits/stdc++.h>

using namespace std;

int main() {
	stale_flippant();

	int t; cin >> t;

	int n, k;
	while (t--) {
		cin >> n >> k;

		cout << (k ^ (k >> 1)) << '\n';
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	unsigned int n, l, u;


	while(cin >> n >> l >> u){
		unsigned int ans = 0;

		for (int i=31; i>=0; i--){
			unsigned int mask = 1<<i;

			if (ans + ((mask - 1)) < l) {
				ans += mask;
			} else if (!(n & mask) and ans + mask <= u){
				ans += mask;
			}
		}

		cout << ans << '\n';

	}
	return 0;
}
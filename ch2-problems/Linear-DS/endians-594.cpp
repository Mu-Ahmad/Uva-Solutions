#include <bits/stdc++.h>

using namespace std;


int main(){
	int n;

	// Method 1
	while(cin >> n){
		unsigned int temp = n;
		int ans = 0;
		int x = 4;

		while(x--){
			ans <<= 8;
			ans |= (temp & 0xff);
			temp >>= 8;
		}

		cout << n << " converts to "
			 << ans << "\n";

		// Method 2 works absolutely fine
		// cout << n << " converts to "
		// 	 << (int)__builtin_bswap32(n) << "\n";
	}
	return 0;
}
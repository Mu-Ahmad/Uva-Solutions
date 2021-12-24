#include <bits/stdc++.h>

using namespace std;

int main(){

	int n; 	
	while (cin >> n and n){
		int ans[2] = {0};
		int idx = 0, bitLength = 0;
		while (n){
			if (n & 1){
				ans[idx] |= (1 << bitLength);
				idx ^= 1;
			}
			bitLength++;
			n = (n >> 1);
		}

		cout << ans[0] << ' '
			 << ans[1] << '\n';
	}


	return 0;
}
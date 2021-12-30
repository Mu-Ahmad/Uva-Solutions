#include <iostream>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int c; cin >> c;
		int coins[c];

		for (int i=0; i<c; i++) cin >> coins[i];

		int ans = 1, sum = 0;
		for (int i=0; i<c-1; i++) 
			if (sum + coins[i] < coins[i+1]) {
				ans++;
				sum += coins[i];
			}

		printf("%d\n", ans);
	}
	return 0;
}
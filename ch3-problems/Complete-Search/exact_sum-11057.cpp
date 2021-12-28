#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, x, target;

	while(cin >> n){
		multiset<int> prices;

		for (int i=0; i<n; i++){
			cin >> x;
			prices.insert(x);
		}

		cin >> target;
		int diff = 999999999, a, b;
		for (int price: prices){
			if (prices.count(target - price) > (2*price == target)) 
				if (abs(target - 2 * price) < diff){
					diff = abs(target - 2 * price);
					a = min(price, target-price);
					b = max(price, target-price);
				}
			
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	int x = 1;
	while(t--){
		int n; cin >> n;
		n;

		int s, e, t_s = 1, sum = 0, temp, bestAns = 0;
		for (int i=2; i<=n; i++){
			cin >> temp;

			sum += temp;

			if (sum < 0) {
				sum = 0;
				t_s = i;
			} else if (sum > bestAns) {
				bestAns = sum;
				s = t_s;
				e = i;
			} else if (sum == bestAns and (i - t_s) > (e - s)){
				s = t_s;
				e = i;
			}
		}

		if (bestAns)
			printf("The nicest part of route %d is between stops %d and %d\n", x++, s, e);
		else
			printf("Route %d has no nice parts\n", x++);

	}
	return 0;
}
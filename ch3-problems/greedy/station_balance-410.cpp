#include <bits/stdc++.h>

using namespace std;

int main(){
	int c, s, t = 1;
	while (cin >> c >> s){
		vector <int> arr(2*c, 0);

		while(s--) cin >> arr[s];

		sort(arr.begin(), arr.end());

		double imbalance = 0, avg = accumulate(arr.begin(), arr.end(), 0) / (double) c;

		int lo = 0, hi = arr.size() - 1;

		printf("Set #%d\n", t++);

		int i=0;
		while (lo < hi){
			printf(" %d:",i++);

			if (arr[lo]) printf(" %d", arr[lo]);
			if (arr[hi]) printf(" %d", arr[hi]);

			imbalance += fabs(arr[hi]+arr[lo] - avg);
			puts("");
			lo++, hi--;
		} 
		printf("IMBALANCE = %.5lf\n\n", imbalance);
	}
	return 0;
}
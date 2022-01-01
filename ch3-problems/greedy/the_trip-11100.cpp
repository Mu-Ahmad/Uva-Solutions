#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	bool first = true;
	while(cin >> n and n){
		if (!first) puts("");
		first = false;

		vector<int> arr(n);

		for (int i=0; i<n; i++)
			cin >> arr[i];

		// count the occurance of the most occuring size
		int k = 0;
		map <int, int> frequency;
		for (int i=0; i<n; i++){
			frequency[arr[i]]++;

			k = max(frequency[arr[i]], k);
		}

		sort(arr.begin(), arr.end());
		
		printf("%d\n", k);
		for (int i=0; i<k; i++){
			printf("%d", arr[i]);
			
			for (int j=i+k; j<n; j+=k)
				printf(" %d", arr[j]);

			puts("");
		}
	}
	return 0;
}
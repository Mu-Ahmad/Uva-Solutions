#include <bits/stdc++.h>

using namespace std;

struct Array {
	int base, dimension, size, c0;
	int u[10], l[10], c[10];
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	string name;
	vector<Array> arrays;
	unordered_map<string, int> indexMap;

	for (int i=0; i< n; i++){
		// Reading in the input
		cin >> name;
		Array arr;
		cin >> arr.base >> arr.size >> arr.dimension;

		for (int j=0; j < arr.dimension; j++)
			cin >> arr.l[j] >> arr.u[j];

		// Calculating the constants
		arr.c[arr.dimension - 1] = arr.size;
		arr.c0 = arr.base - (arr.c[arr.dimension - 1]*arr.l[arr.dimension - 1]);
		
		for (int j=arr.dimension-2; j>=0; j--){
			arr.c[j] = arr.c[j+1] * (arr.u[j+1] - arr.l[j+1] + 1);
			arr.c0 -= (arr.c[j]*arr.l[j]);
		}

		// Some book keeping
		indexMap[name] = i;
		arrays.push_back(arr);
	}

	for (int i=0; i<m; i++){
		cin >> name;
		int idx, index = indexMap[name];

		cout << name << '[';
		
		long long ans = arrays[index].c0;

		for (int j=0; j<arrays[index].dimension; j++){
			cin >> idx;
			ans += arrays[index].c[j]*idx;
			cout << idx;

			if (j+1 == arrays[index].dimension)
				cout << "] = ";
			else 
				cout << ", ";
		}
		cout << ans << '\n';
	}

	
	return 0;
}
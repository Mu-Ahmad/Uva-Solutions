#include <iostream>

using namespace std;

int main(){
	int n, target, p; cin >> n;

	while(n--){
		cin >> target >> p;

		int arr[p];

		for (int i=0; i<p; i++)
			cin >> arr[i];


		int ans;
		bool found = false;
		for (int i=0; i<(1<<p) and !found; i++){
			ans = 0;
			for (int b=0; b<p ; b++)
				if (i & (1 << b))
					ans += arr[b];

			if (ans == target) found = true;
		}

		cout << ((found) ? "YES\n" : "NO\n");
	}

	return 0;
}
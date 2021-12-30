#include <bits/stdc++.h>

using namespace std;

vector<int> vessels;

bool canSolve(int c, int capacity){
	int i = 0, curr = capacity;
	while (i < vessels.size()){
		if (vessels[i] <= curr) {
			curr -= vessels[i];
			i++;
		} else if (--c) curr = capacity;
		else return false;
	}
	return true;
}

int main(){	
	int vessel, containers;

	while(cin >> vessel >> containers){
		vessels.resize(vessel);

		for (int i=0; i<vessel; i++) cin >> vessels[i];

		int hi = 1000000000, lo = 1;

		int itr = 50, ans;
		while(itr--){
			int mid = (lo + hi) / 2;
			if (canSolve(containers, mid)) {
				hi = mid;
				ans = mid;
			}
			else lo = mid;
		}
		cout << ans << '\n';
	}

	return 0;
}
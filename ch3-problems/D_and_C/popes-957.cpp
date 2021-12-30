#include <bits/stdc++.h>

using namespace std;

int main(){
	int y, p;
	while(cin >> y){
		cin >> p;
		vector <int> popes(p);

		for (int i=0; i<p; i++) cin >> popes[i];
		
		int ans = 0, start = 0, end = 0;
		for (auto startItr = popes.begin(); startItr != popes.end(); startItr++){
			auto endItr = upper_bound(startItr, popes.end() ,*startItr + y - 1);

			if (endItr - startItr > ans){
				ans = endItr-startItr;
				start = *startItr;
				end = *(endItr-1);
			}
		}

		printf("%d %d %d\n", ans, start, end);
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	bool first = true;
	while(cin >> n and n){
		if (!first) printf("\n");

		bool found = false;
		first = false;
		for (int fghij=1234; fghij<=98765 / n; fghij++){
			set <int> ans;
			int abcde = fghij*n;

			if (fghij < 10000) ans.insert(0);
			
			int temp = fghij;
			while (temp) {ans.insert(temp % 10); temp /= 10;}
			temp = abcde;
			while (temp) {ans.insert(temp % 10); temp /= 10;}

			if (ans.size() == 10){
				printf("%0.5d / %0.5d = %d\n", abcde, fghij, n);
				found = true;
			}
		}

		if (!found)
			printf("There are no solutions for %d.\n", n);
	}
	return 0;
}
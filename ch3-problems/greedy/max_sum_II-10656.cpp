#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, temp; 
	while(cin >> n and n){
		vector <int> numbers;

		while(n--) {
			cin >> temp;
			if (temp) numbers.push_back(temp);
		}

		if (numbers.size() > 0) {
			for (auto number: numbers)
				printf("%d ", number);
			puts("");
		} else {puts("0");}

		
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	int num, count = 0;
	multiset <int> arr;
	while(cin >> num){
		arr.insert(num);
		count++;
		int half = count / 2;

		auto itr = arr.begin();

		if (count % 2){
			advance(itr, half);
			cout << *itr << '\n';
		} else {
			advance(itr, half);
			cout << (*itr + *(--itr)) / 2 << '\n';
		}
	}
	return 0;
}
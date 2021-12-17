#include <bits/stdc++.h>

using namespace std;

int main(){
	string line;
	while(cin >> line and line != "#"){
		if (next_permutation(line.begin(), line.end()))
			cout << line << '\n';
		else 
			cout << "No Successor\n";
	}

	return 0;
}
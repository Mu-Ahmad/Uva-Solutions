#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(1){
		cin >> n;
		if (n==0) break;
		vector<int> spaces(n, 0);

		cin.ignore();
		for (int i=0; i<n; i++){
			string line;
			getline(cin, line, '\n');
			for (char ch: line)
				if (ch == ' ')
					spaces[i]++;
		}

		int min = *min_element(spaces.begin(), spaces.end());

		cout << accumulate(spaces.begin(), spaces.end(), min*-n) << '\n';
	}	
	return 0;
}

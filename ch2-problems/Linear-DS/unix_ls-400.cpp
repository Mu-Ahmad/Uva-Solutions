#include <bits/stdc++.h>

using namespace std;

int ascii(const string& str){
	int value = 0;
	for (const char& ch: str)
		value += ch;

	return value;
}

bool compare(string s1, string s2){
	return ascii(s1) < ascii(s2);
}

int main(){
	int n;

	while(cin >> n){
		cout << "------------------------------------------------------------\n";
		vector<string> files(n);

		int maxLength = -1;
		for (int i=0; i<n; i++) {
			cin >> files[i];
			maxLength = max(maxLength, (int)files[i].length());
		}

		sort(files.begin(), files.end());

		int col = 62 / (maxLength + 2);
		int row = ceil(n / (double) col);

		for (int i=0; i<row; i++){
			for (int j=i; j<n; j+=row)
				cout << left << setw(maxLength+2) << files[j];

			cout << endl;
		}
	}


	return 0;
}
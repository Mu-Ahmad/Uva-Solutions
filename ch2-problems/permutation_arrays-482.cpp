#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	cin.ignore();
	bool first = true;

	while(t--){
		cin.ignore();

		if (!first)
            cout << "\n";
        first = false;

		string line;
		getline(cin, line);

		istringstream in(line);

		vector<int> positions;
		int position;
		while( in >> position ) positions.push_back(position);

		// setting up the reverse reference

		vector <int> idx(positions.size());

		for(int i=0; i < positions.size(); i++)
			idx[positions[i] - 1] = i;

		getline(cin, line);

		istringstream in1(line);

		vector<string> values;
		string value;

		while( in1 >> value ) values.push_back(value);

		for(int i=0; i < positions.size(); i++)
			cout << values[idx[i]] << '\n';

		cout << '\n';
	}

	return 0;
}
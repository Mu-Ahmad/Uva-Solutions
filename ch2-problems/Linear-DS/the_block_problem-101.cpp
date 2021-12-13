// Incomplete Solution

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> position(n);
	iota(position.begin(), position.end(), 0);

	string line;
	while(getline(cin, line)){
		if (line[0] == 'q') break;
		istringstream in(line);

		string move, action;
		int a, b;

		in >> move >> a >> action >> b;

		if (move == "move" and action == "onto"){
			int idx = position[a];
			while()
		} else if (move == "move" and action == "over"){

		} else if (action == "onto"){

		} else {

		}
	}

	return 0;
}
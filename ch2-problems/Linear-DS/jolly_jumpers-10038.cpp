#include <bits/stdc++.h>

using namespace std;

int main(){
	string line;
	int i=0;
	while (getline(cin, line)){
		vector <int> values;
		int value;

		istringstream in(line);

		int size; in >> size;

		vector<int> occurred(size, 0);
		occurred[0] = 2;

		while(in >> value)
			values.push_back(value);
		
		bool jolly = true;
		for (int i=1; i<size; i++){
			int idx = abs(values[i] - values[i-1]);
			if (idx >= size  or idx < 1) {
				continue;
				jolly = false;
			}
			occurred[idx] = 1;
		}

		if (!jolly) {
			cout << "Not jolly\n";
			continue;
		}

		for (auto& val: occurred)
			if (val == 0) jolly = false;

		if(jolly) cout << "Jolly\n";
		else cout << "Not jolly\n";


	}
	return 0;
}
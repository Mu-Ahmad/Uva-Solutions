#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> sequence[258];

	string line, query; cin >> line;
	for (int i=0; i<line.length(); i++)
		sequence[line[i]].push_back(i);

	int q; cin >> q;
	while(q--){
		cin >> query;
		bool found = true;
		int start = -1, end = -1;

		for (auto ch: query){
			auto it = upper_bound(sequence[ch].begin(), sequence[ch].end(), end);
			if (it == sequence[ch].end()){
				found = false;
				break;
			}
			end = *it;
			if (start == -1) start = end;
		}
		if (found) printf("Matched %d %d\n", start, end);
		else printf("Not matched\n");
	}
	return 0;
}
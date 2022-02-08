#include <bits/stdc++.h>

using namespace std;

bool diffIs1(string s1, string s2){
	if (s1.size() != s2.size()) return false;

	int count = 0;

	for (int i=0; i<s1.size(); ++i)
		count += (s1[i] != s2[i]);

	return (count == 1); 
}

int main(){
	int t; cin >> t; cin.ignore(); cin.ignore();
	string line;
	bool first = true;
	while(t--){
		if (!first) cout << '\n';
		first = false;

		// Just for mapping back and forth
		unordered_map <string, int> toIndex;
		vector<string> toString;

		int idx = 0;
		while(getline(cin, line)){
			if (line == "*") break;
			toIndex[line] = idx++;
			toString.push_back(line);
		}

		// Building an Adjacency matrix
		// Each word is a vertex, connect 2 words with an edge if differ by 1 letter
		int d[idx][idx];
		for (int i=0; i<idx; i++)
			for (int j=0; j<idx; j++)
				if (i==j) d[i][j] = 0;
				else if (diffIs1(toString[i], toString[j])) d[i][j] = 1;
				else d[i][j] = 99999;

		// Warshall’s Algorithm
		for (int k=0; k<idx; k++)
			for (int i=0; i<idx; i++)
				for (int j=0; j<idx; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

		// Answering all queries from pre-computed matrix
		while(getline(cin, line)) {
			if (line.size() == 0) break;

			istringstream in(line);
			string w1, w2; in >> w1 >> w2;
			cout << w1 << " " 
				 << w2 << " "
				 << d[toIndex[w1]][toIndex[w2]] << '\n';
		}
	}
	return 0;
}
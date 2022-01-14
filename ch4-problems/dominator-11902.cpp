#include <bits/stdc++.h>

using namespace std;

bool adj_matrix[105][105];
char answer[105][105];
int n;

void dfs(bool* visited, int curr, int toSkip){
	if (toSkip == curr) return;
	visited[curr] = true;

	for (int i=0; i<n; i++)
		if(adj_matrix[curr][i] and visited[i] != true)
			dfs(visited, i, toSkip);
}

int main(){
	int t; cin >> t;
	int x = 1;
	while(t--){
		cin >> n;
		
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				cin >> adj_matrix[i][j];

		// without blocking any outgoing
		bool firstVisit[105] = {0}; 
		dfs(firstVisit, 0, -1);

		for (int i=0; i<n; i++){
			bool visited[105] = {0};
			dfs(visited, 0, i);

			//check for possible domination
			for (int j=0; j<n; j++)
				answer[i][j] = (firstVisit[j] == visited[j]) ? 'N' : 'Y';	
		}

		// formatting and printing as describred 
		string line = "+";
		for (int i=1; i<n+n; i++)
			line += "-";
		line += "+";

		printf("Case %d:\n", x++);
		for (int i=0; i<n; i++){
			cout << line << "\n|";
			for (int j=0; j<n; j++)
				printf("%c|", answer[i][j]);
			puts("");
		}

		cout << line << '\n';
	}
	return 0;
}
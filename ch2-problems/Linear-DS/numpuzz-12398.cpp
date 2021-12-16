#include <bits/stdc++.h>

using namespace std;

bool valid(pair<int, int> p){
	return (p.first >= 0 and p.first < 3
		and p.second >= 0 and p.second < 3);
}

pair<int,int> operator+(const pair<int,int> &a ,const  pair<int,int> &b ){
        return {a.first+b.first,a.second+b.second};
    }

int main(){
	map <char, pair<int, int>> index;
	index['a'] = {0, 0};
	index['b'] = {0, 1};
	index['c'] = {0, 2};
	index['d'] = {1, 0};
	index['e'] = {1, 1};
	index['f'] = {1, 2};
	index['g'] = {2, 0};
	index['h'] = {2, 1};
	index['i'] = {2, 2};
	string line;

	pair<int, int> dx[] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	int x = 1;
	while(getline(cin, line)){
		vector <vector <int> > grid(3, vector <int>(3, 0));
		
		for (auto block: line){

			for (int i=0; i<5; i++){
				auto p = index[block];
				p = p + dx[i];
				if(valid(p)){
					// cout << p.first << " : " << p.second << '\n';
					(grid[p.first][p.second] = grid[p.first][p.second] + 1) %= 10;
				}
			}
		}

		cout << "Case #" << x++ << ":\n";
		for (int i=0; i<3; i++){
			for (int j=0; j<3; j++){
				if (j) cout << ' ';
				cout << grid[i][j];
			}
			cout << '\n';
		}

	}

	return 0;
}
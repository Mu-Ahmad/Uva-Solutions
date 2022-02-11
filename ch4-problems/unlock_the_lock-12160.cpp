#include <bits/stdc++.h>

using namespace std;

int L, U, R;
vector<int> buttons, d(10000, -1);

int solve() {
	d[L] = 0;
	queue <int> Q;
	Q.push(L);

	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for (auto button : buttons){
			int next = (curr + button) % 10000;
			if (next == U) return d[curr] + 1;
			if (d[next] == -1){
				d[next] = d[curr] + 1;
				Q.push(next);
			}
		}
	}

	return -1;
}

int main(){
	int x = 1;
	while (cin >> L >> U >> R and (L or U or R)){
		d.assign(10000, -1);
		buttons = vector<int>(R);

		while(R--)	cin >> buttons[R];

		int ans = solve();
		if (ans == -1)	printf("Case %d: Permanently Locked\n", x++);
		else	printf("Case %d: %d\n", x++, ans);
	}
	return 0;
}
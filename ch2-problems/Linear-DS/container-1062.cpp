#include <bits/stdc++.h>

using namespace std;

int main(){
	string containers;
	int x = 1;
	while (cin >> containers and containers != "end"){
		stack<char> stacks[30];

		int ans = 0;
		for (auto container : containers)
			for (int i=0; i<26; i++)
				if (stacks[i].empty() or container <= stacks[i].top()){
					stacks[i].push(container);
					ans = max(ans, i+1);
					break;
				}	

		cout << "Case " << x++ << ": "<< ans << '\n';
	}
	return 0;
}



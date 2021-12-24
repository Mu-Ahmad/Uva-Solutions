#include <bits/stdc++.h>

using namespace std;

int main(){
	string line;

	while (cin >> line){
		list <char> l;
		auto it = l.begin();
		for (const auto& ch: line){
			if (ch == '[')
				it = l.begin();
			else if (ch == ']')
				it = l.end();
			else
				l.insert(it, ch);
		}

		for (const auto& ch: l)
			cout << ch;
		cout << '\n';
	}

	return 0;
}
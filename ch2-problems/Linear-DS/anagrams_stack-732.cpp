#include <bits/stdc++.h>

using namespace std;

string word1, word2;
vector <string> ans;

void getPairs(string word1, string word, stack<char> s, string str){
	if (word != word2.substr(0, word.length())) return;
	
	// base case
	if (word1 == ""){
		while (!s.empty()){
			word += s.top();
			s.pop();
			str+='o';
		}
		if (word == word2) ans.push_back(str);

		return;
	}

	//recursive case
	s.push(word1[0]);
	getPairs(word1.substr(1), word, s, str+'i');
	s.pop();
	if (!s.empty()){
		char temp = s.top();
		s.pop();
		getPairs(word1, word + temp, s, str+'o');
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while(cin >> word1 >> word2){
		ans.clear();
		getPairs(word1, "", stack<char>(), "");

		cout << "[\n";
		for (int i=0; i<ans.size(); i++)
			for (int j=0; j<ans[i].length(); j++)
				cout << ans[i][j] << ((j+1 == ans[i].length())? '\n' : ' ');
		cout << "]\n";

	}
	return 0;
}
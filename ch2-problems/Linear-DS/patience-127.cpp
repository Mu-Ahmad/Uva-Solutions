#include <bits/stdc++.h>

using namespace std;

bool valid(string c1, string c2){
	return c1[0] == c2[0] or c1[1] == c2[1];
}

int main(){
	string line1, line2;
	while(1) {
		getline(cin, line1), getline(cin, line2);

		if (line1 == "#") break;

		istringstream in1(line1), in2(line2);
		vector< stack<string> >  piles(52, stack<string>());

		int i = 0;
		while (in1 >> line1) piles[i++].push(line1);
		while (in2 >> line1) piles[i++].push(line1);

		bool keepGoing = true;

		while(keepGoing){
			keepGoing = false;

			for (int i=1; i<piles.size(); i++){
				string currentCard = piles[i].top();					

				if (i>2 and valid(currentCard, piles[i - 3].top())){
					piles[i - 3].push(currentCard);
					piles[i].pop();
					if (piles[i].empty()) piles.erase(piles.begin()+i);

					keepGoing = true;
					break;
				} else if (valid(currentCard, piles[i-1].top())){
					piles[i-1].push(currentCard);
					piles[i].pop();
					if (piles[i].empty()) piles.erase(piles.begin()+i);

					keepGoing = true;
					break;
				} 

			}
		}

		if (piles.size() == 1)
			cout << piles.size() << " pile remaining:";
		else
			cout << piles.size() << " piles remaining:";
		
		for (int i=0; i<piles.size(); i++)
			cout << ' ' << piles[i].size();
		cout << '\n';

	}
	return 0;
}

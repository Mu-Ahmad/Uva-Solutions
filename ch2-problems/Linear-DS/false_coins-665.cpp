#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	cin.ignore();

	while(t--){
		cin.ignore();
		
		int coins, weightings; cin >> coins >> weightings;
		set <int> coinset;
		
		for (int i = 1; i<=coins; i++)
			coinset.insert(i);

		while(weightings--){
			int size; cin >> size;

			vector <int> groups(size+size);

			for(int i=0; i<size+size; i++)
				cin >> groups[i];

			char symbol; cin >> symbol;

			if (symbol == '=')
				for (auto& coin : groups)
					if (coinset.count(coin))
						coinset.erase(coin);
		}

		if (coinset.size() == 1)
			cout << *coinset.begin() << '\n';
		else 
			cout << "0\n";

		if(t) cout << "\n";
	}

	return 0;
}
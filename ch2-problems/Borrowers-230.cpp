#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line;
	// author, title
	vector < pair<string, string> > shelf;
	unordered_map<string, int> books;

	// Read the books
	while(getline(cin, line) and line[0] != 'E'){
		string title, author;

		istringstream in(line);

		//ignore the first quotation 
		in.ignore(1, '"');

		getline(in, title, '"');

		//ignore " by "
		in.ignore(4, '"');


		getline(in, author);

		shelf.push_back({author, title});
	}

	// sort the shelf
	sort(shelf.begin(), shelf.end());

	for (int i=0; i<shelf.size(); i++)
		books[shelf[i].second] = i;


	vector<bool> borrowed(shelf.size(), false), returned(shelf.size(), false);


	while(getline(cin, line) and line[0] != 'E'){
		string title;
		int previousBook = -1;

		if (line[0] != 'S'){
			istringstream in(line);
			in.ignore(8, '"');
			getline(in, title, '"');
			// cout << title << '\n';
		}

		switch(line[0]){
			case 'B':
				borrowed[books[title]] = true;
				returned[books[title]] = false;
				break;

			case 'R':
				returned[books[title]] = true;
				break;

			default:
				for (int i=0; i<shelf.size(); i++){
					if (returned[i]){
						if (previousBook == -1)
							cout << "Put \"" << shelf[i].second << "\" first\n";
						else
							cout << "Put \"" << shelf[i].second << "\" after \"" << shelf[previousBook].second << "\"\n";
						
						returned[i] = borrowed[i] = false;
						previousBook = i;
					} else if (borrowed[i] == false) {
						previousBook = i;
					}
				}
				cout << "END\n";
					
		}
	}

	return 0;
}










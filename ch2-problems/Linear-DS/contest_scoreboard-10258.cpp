#include <bits/stdc++.h>

using namespace std;

struct Contestant {
	int id, solved, penalty;

	Contestant()
		: id(0), solved(0), penalty(0)
		{}

	bool operator<(const Contestant& other){
		if (solved != other.solved)
			return solved < other.solved;

		if (penalty != other.penalty)
			return penalty > other.penalty;

		return id>other.id;
	}

	void print(){
		cout << id << ' '
		     << solved << ' '
		     << penalty << '\n';
	}

};

int main(){
	cin.ignore(); cin.ignore();
	string line;
	int id, problem, time;
	char status;

	int t; cin >> t;
	while(t--){
		vector <Contestant> contestants(100);
		vector <vector<int>> penalties(100, vector<int>(10, 0));
		vector <bool> participated(100, false);

		for (int i=99; i>=0; i--)
			contestants[i].id = i+1;

		while(1){
			getline(cin, line);
			if (line.length() == 0)  break;

			istringstream in(line);
			in >> id >> problem >> time >> status;
		
			participated[id - 1] = true;
			switch(status){
				case 'C':
				if (penalties[id-1][problem-1] == -1)
					break;
				contestants[id-1].solved++;
				contestants[id-1].penalty += (time + penalties[id-1][problem-1]);
				penalties[id-1][problem-1] = -1;
				break;

				// Add penalty to the said problem of the contestant
				case 'I':
				if (penalties[id-1][problem-1] == -1)
					break;
				penalties[id-1][problem-1] += 20;
				break;

				default:
					break;
			}
		}

		sort(contestants.begin(), contestants.end());


		for (int i=99; i>=0; i--)
			if (participated[contestants[i].id - 1])
				contestants[i].print();
		
		if(t)
			cout << '\n';
	}

	return 0;
}
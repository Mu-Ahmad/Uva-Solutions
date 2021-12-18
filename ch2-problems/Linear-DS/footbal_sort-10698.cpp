#include <bits/stdc++.h>

using namespace std;

struct Team {
	string name;
	int gamesPlayed, points, goalScored, goalConceded;

	Team (string name) 
		: name(name), gamesPlayed(0), 
		  points(0), goalScored(0), goalConceded(0)
	{}

	bool operator<(const Team& other){
		if (points != other.points)
			return points < other.points;

		int difference = goalScored - goalConceded;
		int otherdifference = other.goalScored - other.goalConceded;
		if (difference != otherdifference)
			return difference < otherdifference;

		if (goalScored != other.goalScored)
			return goalScored < other.goalScored;
		
		string n1 = name, n2 = other.name;
		
		transform(n1.begin(), n1.end(), n1.begin(), ::tolower);
		transform(n2.begin(), n2.end(), n2.begin(), ::tolower);

		if (n1 != n2)
			return n1 > n2;

		return true;
	}
};

int main(){
	int t, matches;
	string name;

	bool first = true;

	while(cin >> t >> matches and (t or matches)){

		if (!first)
			cout << "\n";
		
		first = false;

		vector <Team> teams;
		unordered_map <string, int> teamId;
		
		while(t--){
			cin >> name;
			teamId[name] = teams.size();
			teams.push_back(Team(name));
		}

		string home, away, temp;
		int homeScore, awayScore;
		while(matches--){
			cin >> home >> homeScore >> temp >> awayScore >> away;

			teams[teamId[home]].gamesPlayed++;
			teams[teamId[home]].goalScored += homeScore;
			teams[teamId[home]].goalConceded += awayScore;

			teams[teamId[away]].gamesPlayed++;
			teams[teamId[away]].goalScored += awayScore;
			teams[teamId[away]].goalConceded += homeScore;


			if (homeScore > awayScore){ // home won
				teams[teamId[home]].points += 3;
			} else if (homeScore == awayScore){ // draw
				teams[teamId[home]].points++;
				teams[teamId[away]].points++;
			} else { // away won
				teams[teamId[away]].points += 3;
			}
		}

		sort(teams.begin(), teams.end());

		for (int i=teams.size()-1, pos=1; i>=0; i--, pos++){
			// if to print label or not
			if (i+1 == teams.size() or 
				teams[i].points != teams[i+1].points or 
				teams[i].goalScored != teams[i+1].goalScored or 
				teams[i].goalScored - teams[i].goalConceded != teams[i+1].goalScored - teams[i+1].goalConceded
				)
				cout << right << setw(2) << pos << ". ";
			else
				cout << "    ";

			// printing team stats
			cout << right << setw(15) << teams[i].name
				 << right << setw(4) << teams[i].points 
				 << right << setw(4) << teams[i].gamesPlayed 
				 << right << setw(4) << teams[i].goalScored 
				 << right << setw(4) << teams[i].goalConceded 
				 << right << setw(4) << teams[i].goalScored - teams[i].goalConceded ;

			if(teams[i].gamesPlayed)
				cout << right << setw(7) << fixed << setprecision(2) << (teams[i].points * 100.0) / (teams[i].gamesPlayed * 3.00) << '\n';
			else
				cout << "    N/A\n";
		}
		
	}

	return 0;
}
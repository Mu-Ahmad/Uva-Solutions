#include <bits/stdc++.h>

using namespace std;

int main(){

	string line;
	int x = 1;
	while(getline(cin, line)){
		if (line.length() == 0) break;

		istringstream in(line);

		vector <int> signals;
		int signal;

		while(in >> signal)
			signals.push_back(signal);

		int greenLights[3605] = {0};

		for (auto signal: signals){
			int duration = 0;
			int k = 8;

			while(duration <= 3600){
				for (int i=duration; i <= 3600 and i < (duration+signal-5); i++)
					greenLights[i]++;
				duration += 2*signal;
			}
		}

		int syncAt = -1;

		for (int i=*min_element(signals.begin(), signals.end()) * 2 ; i<=3600; i++)
			if (greenLights[i] == signals.size()){
				syncAt = i;
				break;
			}
		


		if (syncAt == -1)
			cout << "Set " << x++ << " is unable to synch after one hour.\n";
		else 
			cout << "Set " << x++ 
				 << " synchs again at " << syncAt / 60 
				 << " minute(s) and " << syncAt % 60 
				 << " second(s) after all turning green.\n";
	}

	return 0;
}
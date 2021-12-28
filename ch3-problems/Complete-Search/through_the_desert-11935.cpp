#include <bits/stdc++.h>

using namespace std;

int main(){
	string line, command; 
	int time;

	while(1){

		int leak = 0, lastStop=0;
		double maxTank = 0, currTank = 0, perLitreRate = 0.0;
		while(getline(cin, line)){
			istringstream in(line);
			in >> time >> command;

			currTank += (perLitreRate + leak) * (time - lastStop);
			maxTank = max(maxTank, currTank);
			lastStop = time;

			if(command == "Fuel"){
				in >> command >> perLitreRate;
				if (perLitreRate < 1) return 0;
				perLitreRate /= 100.0;
			} 
			else if (command == "Leak") {leak++;} 
		    else if (command == "Gas")  {currTank = 0;} 
	        else if (command == "Mechanic")  {leak=0;}
	        else break;
		}

		printf("%.3f\n", maxTank);
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

void solve(int size, int p){
	int center = size/2 + 1;

	if (p == 1){
		cout << "Line = " << center 
			 << ", column = " << center << ".\n";
		return;
	}

	int ring = 1;
	while(p  > ring*ring)
		ring += 2;

	int row, col, lowerBound = (ring -2)*(ring -2);
	int pad = (size - ring) / 2;

	if (p <= lowerBound + ring - 1){
		p -= lowerBound;
		row = center + ring/2;
		col = size - pad  - p;
	} else if (p <= lowerBound + 2*(ring -1)) {
		p -= lowerBound + 1*(ring -1);
		row = size - pad - p;
		col = center - ring/2; 
	} else if (p <= lowerBound + 3*(ring -1)) {
		p -= lowerBound + 2*(ring -1);
		row = center - ring/2;
		col = 1 + p + pad;
	} else {
		p -= lowerBound + 3*(ring -1);
		col = center + ring/2;
		row = 1 + p + pad;
	}

	cout << "Line = " << row 
		 << ", column = " << col << ".\n";
}

int main(){
	int size, pos;

	while(cin >> size >> pos and (size and pos)){
		solve(size, pos);
	}
	return 0;
}
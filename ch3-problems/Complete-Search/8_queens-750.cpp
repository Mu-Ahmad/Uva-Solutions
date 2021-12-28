#include <bits/stdc++.h>

using namespace std;

int a, b, x;
int row[8];

bool place(int r, int c){
	for (int i=0; i<c; i++)
		if (row[i] == r or abs(row[i] - r) == abs(i-c))
			return false;

	return true;
}

void getSomeStuffDone(int c){
	if(c==8 and row[b]==a){
		printf("%2d      %d", ++x, row[0] + 1);
		for (int j = 1; j < 8; j++) printf(" %d", row[j] + 1);
		printf("\n");
		return;
	}

	if (c==8) return;

	for (int i=0; i<8; i++){
		if (place(i, c)){
			row[c] = i;
			getSomeStuffDone(c+1);
		}
	}
}

int main(){
	int n; cin >> n;

	while(n--){
		memset(row, sizeof(*row)*8, 0);

		cin >> a >> b; a--, b--;

		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		x = 0;
		getSomeStuffDone(0);
		if (n) printf("\n");
	}

	return 0;
}
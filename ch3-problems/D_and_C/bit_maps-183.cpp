#include <bits/stdc++.h>

using namespace std;

int bitMap[202][202];
int p = 0;
bool sameSeqence(int startR, int endR, int startC, int endC){
	int target = bitMap[startR][startC];

	for (int i=startR; i<endR; i++)
		for (int j=startC; j<endC; j++)
			if (bitMap[i][j] != target) return false;
		

	return true;
}

void BtoD(int startR, int endR, int startC, int endC){

	if (startR == endR or startC == endC) return;

	// "Each line will contain 50 characters."
    if (p > 0 && p % 50 == 0)
        cout << endl;
    p++;

	if (sameSeqence(startR, endR, startC, endC)){
		cout << bitMap[startR][startC];
		return ;
	}

	cout << 'D';

	int rowCut = (startR + endR + 1) / 2; 
	int colCut = (startC + endC + 1) / 2; 
	BtoD(startR, rowCut, startC, colCut); // top left
	BtoD(startR, rowCut, colCut, endC); // top left
	BtoD(rowCut, endR, startC, colCut); // bottom left
	BtoD(rowCut, endR, colCut, endC); // bottom right
	
	return;
}

void DtoB(int startR, int endR, int startC, int endC){
	if (startR == endR or startC == endC) return;

	// read a character
	char ch; cin >> ch;
	if(ch == '0' or ch == '1'){
		for (int i=startR; i<endR; i++)
			for (int j=startC; j<endC; j++)
				bitMap[i][j] = ch - '0';

		return;
	}

	int rowCut = (startR + endR + 1) / 2; 
	int colCut = (startC + endC + 1) / 2; 

	DtoB(startR, rowCut, startC, colCut); // top left
	DtoB(startR, rowCut, colCut, endC); // top left
	DtoB(rowCut, endR, startC, colCut); // bottom left
	DtoB(rowCut, endR, colCut, endC); // bottom right

	return;
}

int main(){
	char type, temp;
	int r, c; 
	while (cin >> type, type != '#'){
		cin >> r >> c;	

		if (type == 'B'){
			for (int i=0; i<r; i++)
				for (int j=0; j<c; j++){
					cin >> temp;
					bitMap[i][j] = temp - '0';
				}

			printf("D%4d%4d\n", r, c);
			p = 0;
			BtoD(0, r, 0, c);
		} else {
			DtoB(0, r, 0, c);

			printf("B%4d%4d\n", r, c);
			for (int i=0; i<r; i++)
				for (int j=0; j<c; j++){
					// "Each line will contain 50 characters."
                    if (i+j > 0 && (i * c + j) % 50 == 0)
                        cout << endl;
					cout << bitMap[i][j];
				}
		}
		puts("");
	}
	return 0;
}
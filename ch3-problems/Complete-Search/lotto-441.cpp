#include <iostream>

using namespace std;

int main(){
	int n;
	bool first = true;
	while(cin >> n and n){
		int arr[n];

		if (!first)
			printf("\n");

		first = false;

		for (int i=0; i<n; i++)
			cin >> arr[i];

		for (int a=0; a<n-5; a++)
		 for (int b=a+1; b<n-4; b++)
		  for (int c=b+1; c<n-3; c++)
		   for (int d=c+1; d<n-2; d++)
		    for (int e=d+1; e<n-1; e++)
		     for (int f=e+1; f<n; f++)
		     	printf("%d %d %d %d %d %d\n", 
		     		arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);

		
	}
	return 0;
}
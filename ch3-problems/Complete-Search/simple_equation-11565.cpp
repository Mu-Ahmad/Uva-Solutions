#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n; cin >> n;
	int A, B, C;

	while(n--){

		cin >> A >> B >> C;

		bool done = false;
		for (int x=-22; x<=22 and !done; x++) if (x*x <= C)
			for (int y=-100; y<=100 and !done; y++) if (x != y and x*x + y*y<=C) {
				int z = A - x - y;

				if (z == x or z == y or x*y*z != B or x*x + y*y + z*z != C)
				continue;

				int arr[3] = {x, y, z};

				sort(arr, arr+3);

				printf("%d %d %d\n", arr[0], arr[1], arr[2]);
				done = true;
			}

		if (!done) printf("No solution.\n");
	}

	return 0;
}
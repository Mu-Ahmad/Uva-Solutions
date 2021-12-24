#include <bits/stdc++.h>

using namespace std;

struct Info {
	int current, start, end;

	int difference() const{
		return end - start;
	}
};

int main(){
	int n, x=1;
	bool same = true;

	while(cin >> n and n){
		vector <Info> arr(n);

		int curr = 0;

		for (int i=0; i<n; i++){
			cin >> arr[i].current
				>> arr[i].start
				>> arr[i].end;

			curr = max(curr, arr[i].current);
		}

		cout << "Case #" << x++ << ":\n";

		
		for (; curr < 10000; curr++){
			bool found = true;

			for (int i=0; i<n and found; i++)
				if ((curr - arr[i].current) % arr[i].difference() != 0)
					found = false;
			

			if (found) break;
		}

		if (curr < 10000) 	cout << "The actual year is " << curr << ".\n\n";
		else	cout << "Unknown bugs detected.\n\n";
	}

	return 0;
}
























#include <bits/stdc++.h>
#define each const auto&

using namespace std;

int main(){
	int b, s, x = 1;
	while(cin >> b >> s and (b or s)){
		vector<int> bachelors(b), spinsters(s);

		for(int i=0; i<b; i++) cin >> bachelors[i];
		for(int i=0; i<s; i++) cin >> spinsters[i];

		sort(bachelors.begin(), bachelors.end(), greater<int>());
		sort(spinsters.begin(), spinsters.end());

		for (each bachelor: bachelors){
			if (spinsters.size() == 0) break;

			auto it = lower_bound(spinsters.begin(), spinsters.end(), bachelor);
			int s1 = INT_MAX, s2=INT_MAX;

			if (it != spinsters.end()) s1 = *it;
			if (it != spinsters.begin()) s2 = *(it-1);

			if (abs(s1-bachelor) <= abs(s2-bachelor))
				spinsters.erase(it);
			else
				spinsters.erase(it-1);
		}

		printf("Case %d: ", x++);

		if (b > s) printf("%d %d\n", b-s, bachelors[b-1]);
		else puts("0");
	}
	return 0;
}
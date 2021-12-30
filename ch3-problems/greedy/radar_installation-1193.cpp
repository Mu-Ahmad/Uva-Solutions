#include <bits/stdc++.h>

using namespace std;

struct Interval{
	double left, right;

	Interval(double left, double right) 
		:left(left), right(right) 
		{}

	bool operator< (const Interval& other) const {
		return (right==other.right)?left < other.left : right<other.right;
	}

};

int main(){
	int m, t = 1;
	double left, right, x, y, d;
	while(cin >> m >> d and (m or d)){
		vector<Interval> intervals;
		bool valid = true;
		while(m--){
			cin >> x >> y;

			if (y>d) valid = false;

			left = x - sqrt(d*d - y*y);
			right = x + sqrt(d*d - y*y);

			intervals.push_back(Interval(left, right));
		}

		if (!valid) {
			printf("Case %d: -1\n", t++);
			continue;
		}

		sort(intervals.begin(), intervals.end());	

		int radar = 1;
		double distance = intervals[0].right;

		for (auto interval: intervals) {

			if (interval.left > distance){
				radar++;
				distance = interval.right;
			}

			distance = min(distance, interval.right);
		}

		printf("Case %d: %d\n", t++, radar);
		
	}
	return 0;
}
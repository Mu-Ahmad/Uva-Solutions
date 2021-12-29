#include <bits/stdc++.h>
#define EPS 1e-7

using namespace std;

int p,q,r,s,t,u;

double f(double x){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double bisection(){
	double a = 0, b = 1, x;

	while (a + EPS < b){
		x = (a + b) / 2;
		if (f(a) * f(x) <= 0) b = x;
		else a = x;
	}

	return (a+b)/2;
}

double secant(){
	if (f(0) == 0) return 0;
	if (f(1) == 0) return 1;

	double x0=0, x1=1, d;

	while(1){
		// compute delta
		d = f(x1) * (x1 - x0) / (f(x1) - f(x0));

		if (fabs(d) < EPS) break;

		x0 = x1;
		x1 = x1 - d;
	}

	return x1;
}

int main(){
	while(cin >> p >> q >> r >> s >> t >> u){
		if (f(0) * f(1) > 0) cout << "No solution\n";
		else printf("%.4lf\n", /*secent()*/bisection());
	}
	return 0;
}
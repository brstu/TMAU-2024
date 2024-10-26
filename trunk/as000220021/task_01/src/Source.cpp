#include <iostream>
#include <math.h>

using namespace std;

double temperature1(double a,double b,double c, double d, double yCurr, double uCur);
double temperature2(double a, double b, double yCurr, double uCurr);
	
int main() {
	double a, b, c, d, yCurr, uCurr,n,yNext;

	cout << "Input a,b,c,d, current y, current u, n\n";
	cin >> a >> b >> c >> d >> yCurr >> uCurr>>n;
	cout << "linear\n";
	for (int i = 0; i < n; i++) {
		yNext = temperature1(a, b, c, d, yCurr, uCurr);
		cout <<"takt-"<<i+1<<" "<< yNext << '\n';
		yCurr = yNext;
	}
	cout << "nonlinear\n";
	for (int i = 0; i < n; i++) {
		yNext = temperature2(a, b, yCurr, uCurr);
		cout << "takt-" << i + 1 << " " << yNext<<'\n';
		yCurr = yNext;
	}
}

double temperature1(double a, double b, double c, double d, double yCurr, double uCurr) {
	double yPrev, uPrev, yNext;
	yPrev = uPrev = 0;
	yNext = a * yCurr - b * yPrev*yPrev + c * uCurr + d * sin(uPrev);
	return yNext;
}

double temperature2(double a,double b, double yCurr, double uCurr) {
	double yNext;
	yNext = a * yCurr + b * yCurr;
	return yNext;
}
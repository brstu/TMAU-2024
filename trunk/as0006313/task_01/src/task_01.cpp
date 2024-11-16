#include <iostream>
#include <cmath>

using namespace std;

double linearCalc(double tempY, double warmInput, double coefA, double coefB) {
	return (coefA * tempY) + (coefB * warmInput);
}

double nonLinearCalc(double tempY, double tempPrev, double warmInput, double coefA, double coefB, double coefC, double coefD) {
	return (coefA * tempY) - coefB * pow(tempPrev, 2) + (coefC * warmInput) + coefD * sin(warmInput);
}

int main() {
	const double coefLinA = 1.6;
	const double coefLinB = 0.9;
	const double coefNonLinA = 0.8;
	const double coefNonLinB = 0.6;
	const double coefNonLinC = 0.5;
	const double coefNonLinD = 0.3;

	double linRes = 0.0;
	double nonLinRes = 0.0;
	double nonLinPrevRes = 0.0;

	double warmInput = 0;
	int timeSteps;

	cout << "Enter Warm: ";
	cin >> warmInput;
	cout << "Enter Time: ";
	cin >> timeSteps;
	cout << endl;

	for (int i = 1; i <= timeSteps; i++) {
		linRes = linearCalc(linRes, warmInput, coefLinA, coefLinB);
		nonLinRes = nonLinearCalc(nonLinRes, nonLinPrevRes, warmInput, coefNonLinA, coefNonLinB, coefNonLinC, coefNonLinD);
		nonLinPrevRes = nonLinRes;

		cout << "TIME: " << i << endl;
		cout << "LINEAR MODEL: " << linRes << endl;
		cout << "NONLINEAR MODEL: " << nonLinRes << endl << endl;
	}
}

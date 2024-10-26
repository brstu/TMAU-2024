#include <iostream>
#include <cmath>
using namespace std;

// Linear model
void LinearModel(int a, int b, double y, int u, int n) {
    for (int i = 0; i < n; i++) {
        y = a * y + b * u;
        cout << "Iteration " << i + 1 << "\ty(t) = " << y << endl;
    }
}

//Nonlinear model
void NonLinearModel(int a, int b, int c, int d, double y, int u, int n) {
    double y_last = 0;
    double u_last = 0;
    for (int i = 0; i < n; i++) {
        double y_new = a * y - b * pow(y_last, 2) + c * u + d * sin(u_last);
        u_last = u;
        y_last = y;
        cout << "Iteration " << i + 1 << "\ty(t) = " << y_new << endl;
        y = y_new;
    }
}

int main()
{
    int a, b, c, d, n, u;
    double y;

    //Entering values
    cout << "Enter constant a: ";
    cin >> a;
    cout << "Enter constant b: ";
    cin >> b;
    cout << "Enter constant c: ";
    cin >> c;
    cout << "Enter constant d: ";
    cin >> d;

    cout << "Enter input temperature y(t): ";
    cin >> y;
    cout << "Enter input warm u(t): ";
    cin >> u;
    cout << "Enter number of iterations n: ";
    cin >> n;
    cout << endl;

    //Starting linear model
    cout << "Simulating linear model:\n";
    LinearModel(a, b, y, u, n);
    cout << endl;

    //Starting nonlinear model
    cout << "Simulating nonlinear model:\n";
    NonLinearModel(a, b, c, d, y, u, n);

}


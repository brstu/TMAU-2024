#include <iostream>
#include <cmath>

using namespace std;

// Function for linear model
void linearModel(double y, double u, double a, double b, int steps) {
    for (int i = 1; i <= steps; i++) {
        double y_next = a * y + b * u;
        cout << "Step " << i << ": y = " << y_next << endl;

        y = y_next;
    }
}

// Function for nonlinear model
void nonlinearModel(double y, double u, double a, double b, double c, double d, int steps) {
    double y_prev = 0;
    double u_prev = 0;

    for (int i = 1; i <= steps; i++) {
        double y_next = a * y - b * y_prev * y_prev + c * u + d * sin(u_prev);
        cout << "Step " << i << ": y = " << y_next << endl;

        y_prev = y; // Update the previous temperature value
        u_prev = u; // Update the previous control value

        y = y_next; // Update the current temperature value
    }
}

int main() {
    double a, b, c, d; // Constants
    double y; // Current temperature
    double u; // Current heat
    int steps; // Number of modeling steps

    cout << "Enter the value for constant a: "; cin >> a;
    cout << "Enter the value for constant b: "; cin >> b;
    cout << "Enter the value for constant c: "; cin >> c;
    cout << "Enter the value for constant d: "; cin >> d;

    cout << "Enter the initial value for current temperature, y: "; cin >> y;
    cout << "Enter the initial control value, u: "; cin >> u;

    cout << "Enter the number of iterations, steps: "; cin >> steps;

    // Linear model
    cout << "\nLinear model simulation:\n";
    linearModel(y, u, a, b, steps);

    // Nonlinear model
    cout << "\nNonlinear model simulation:\n";
    nonlinearModel(y, u, a, b, c, d, steps);

    return 0;
}

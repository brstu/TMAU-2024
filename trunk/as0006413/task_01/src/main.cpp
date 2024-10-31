#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to simulate the linear model
vector<double> simulateLinearModel(double a, double b, double y0, const vector<double>& u, int n) {
    vector<double> y(n);
    y[0] = y0; // Initial temperature

    // Loop through each time step to calculate the temperature
    for (int t = 1; t < n; ++t) {
        y[t] = a * y[t - 1] + b * u[t - 1]; // Update temperature based on the linear model
    }

    return y; // Return the vector of temperatures
}

// Function to simulate the nonlinear model
vector<double> simulateNonLinearModel(double a, double b, double c, double d, double y0, const vector<double>& u, int n) {
    vector<double> y(n);
    y[0] = y0; // Initial temperature

    // Loop through each time step to calculate the temperature
    for (int t = 1; t < n; ++t) {
        double prev_y = y[t - 1];
        double prev_u = u[t - 1];
        y[t] = a * prev_y - b * pow(prev_y, 2) + c * prev_u + d * sin(prev_u); // Nonlinear model update
    }

    return y; // Return the vector of temperatures
}

int main() {
    // Input constants from user
    double a, b, c, d, y0;
    cout << "Enter the constant a for the model: ";
    cin >> a;
    cout << "Enter the constant b for the linear model: ";
    cin >> b;
    cout << "Enter the constant c for the nonlinear model: ";
    cin >> c;
    cout << "Enter the constant d for the nonlinear model: ";
    cin >> d;
    cout << "Enter the initial temperature (y0): ";
    cin >> y0;

    // Input the number of time moments
    int n;
    cout << "Enter the number of discrete time moments: ";
    cin >> n;

    // Input the heat values
    vector<double> u(n);
    cout << "Enter the heat values (u) for each time moment:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "u[" << i + 1 << "]: ";
        cin >> u[i]; // Read input for each heat value
    }

    // Simulate the linear model
    vector<double> y_linear = simulateLinearModel(a, b, y0, u, n);

    // Simulate the nonlinear model
    vector<double> y_nonlinear = simulateNonLinearModel(a, b, c, d, y0, u, n);

    // Output results
    cout << "\nLinear Model Simulation:" << endl;
    for (int t = 0; t < n; ++t) {
        cout << "Time " << t + 1 << ": Temperature = " << y_linear[t] << endl;
    }

    cout << "\nNon-linear Model Simulation:" << endl;
    for (int t = 0; t < n; ++t) {
        cout << "Time " << t + 1 << ": Temperature = " << y_nonlinear[t] << endl;
    }

    return 0; // Indicate successful completion
}

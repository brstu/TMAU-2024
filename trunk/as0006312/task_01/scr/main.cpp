#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct SimulationResults {
    vector<double> linearModel;
    vector<double> nonlinearModel;
};

SimulationResults runSimulation(double param1, double param2, double param3, double param4, double initialTemp, const vector<double>& heatValues, int numSteps) {
    vector<double> linearResult(numSteps);
    linearResult[0] = initialTemp; // Initial temperature

    vector<double> nonlinearResult(numSteps);
    nonlinearResult[0] = initialTemp; // Initial temperature

    for (int t = 1; t < numSteps; ++t) {
        linearResult[t] = param1 * linearResult[t - 1] + param2 * heatValues[t - 1]; // Update temperature based on the linear model

        double prev_y = nonlinearResult[t - 1];
        double prev_u = heatValues[t - 1];
        nonlinearResult[t] = param1 * prev_y - param2 * pow(prev_y, 2) + param3 * prev_u + param4 * sin(prev_u); // Nonlinear model update
    }

    return { linearResult, nonlinearResult };
}

int main() {
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

    int n;
    cout << "Enter the number of discrete time moments: ";
    cin >> n;

    vector<double> u(n);
    cout << "Enter the heat values (u) for each time moment:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "u[" << i + 1 << "]: ";
        cin >> u[i];
    }

    SimulationResults results = runSimulation(a, b, c, d, y0, u, n);

    cout << "\nLinear Model Simulation:" << endl;
    for (int t = 0; t < n; ++t) {
        cout << "Time " << t + 1 << ": Temperature = " << results.linearModel[t] << endl;
    }

    cout << "\nNon-linear Model Simulation:" << endl;
    for (int t = 0; t < n; ++t) {
        cout << "Time " << t + 1 << ": Temperature = " << results.nonlinearModel[t] << endl;
    }

    return 0;
}
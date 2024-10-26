#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct SimulationData {
    vector<double> model1;
    vector<double> model2;
};

SimulationData executeSimulation(double a, double b, double c, double d, double initialTemp, const vector<double>& heatValues, int steps) {
    vector<double> result1(steps);
    result1[0] = initialTemp; // Initial temperature

    vector<double> result2(steps);
    result2[0] = initialTemp; // Initial temperature

    for (int t = 1; t < steps; ++t) {
        result1[t] = a * result1[t - 1] + b * heatValues[t - 1]; // Update based on model 1

        double prev_y = result2[t - 1];
        double prev_u = heatValues[t - 1];
        result2[t] = a * prev_y - b * pow(prev_y, 2) + c * prev_u + d * sin(prev_u); // Update based on model 2
    }

    return { result1, result2 };
}

int main() {
    double param_a, param_b, param_c, param_d, temp0;
    cout << "Please input constant a for the model: ";
    cin >> param_a;
    cout << "Please input constant b for the linear model: ";
    cin >> param_b;
    cout << "Please input constant c for the nonlinear model: ";
    cin >> param_c;
    cout << "Please input constant d for the nonlinear model: ";
    cin >> param_d;
    cout << "Please input the initial temperature (y0): ";
    cin >> temp0;

    int numSteps;
    cout << "Please enter the number of discrete time steps: ";
    cin >> numSteps;

    vector<double> heatValues(numSteps);
    cout << "Enter the heat values (u) for each time step:" << endl;
    for (int i = 0; i < numSteps; ++i) {
        cout << "u[" << i + 1 << "]: ";
        cin >> heatValues[i];
    }

    SimulationData simulationResults = executeSimulation(param_a, param_b, param_c, param_d, temp0, heatValues, numSteps);

    cout << "\nLinear Model Simulation:" << endl;
    for (int t = 0; t < numSteps; ++t) {
        cout << "Time " << t + 1 << ": Temperature = " << simulationResults.model1[t] << endl;
    }

    cout << "\nNonlinear Model Simulation:" << endl;
    for (int t = 0; t < numSteps; ++t) {
        cout << "Time " << t + 1 << ": Temperature = " << simulationResults.model2[t] << endl;
    }

    return 0;
}
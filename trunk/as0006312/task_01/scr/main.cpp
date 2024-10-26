#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct SimulationData {
    vector<double> model1;
    vector<double> model2;
};

SimulationData runSimulation(double a, double b, double c, double d, double initialTemp, const vector<double>& inputs, int steps) {
    vector<double> result1(steps);
    result1[0] = initialTemp;

    vector<double> result2(steps);
    result2[0] = initialTemp;

    for (int t = 1; t < steps; ++t) {
        result1[t] = a * result1[t - 1] + b * inputs[t - 1]; // Model 1 update

        double prev_y = result2[t - 1];
        double prev_u = inputs[t - 1];
        result2[t] = a * prev_y - b * pow(prev_y, 2) + c * prev_u + d * sin(prev_u); // Model 2 update
    }

    return { result1, result2 };
}

int main() {
    double a, b, c, d, initialTemp;
    cout << "constant a model: ";
    cin >> a;
    cout << "constant b linear model: ";
    cin >> b;
    cout << "constant c nonlinear model: ";
    cin >> c;
    cout << "constant d nonlinear model: ";
    cin >> d;
    cout << "initial temperature (y0): ";
    cin >> initialTemp;

    int numSteps;
    cout << "number of discrete time steps: ";
    cin >> numSteps;

    vector<double> inputs(numSteps);
    cout << "input values (u) for each time step:" << endl;
    for (int i = 0; i < numSteps; ++i) {
        cout << "u[" << i + 1 << "]: ";
        cin >> inputs[i];
    }

    SimulationData simulationResults = runSimulation(a, b, c, d, initialTemp, inputs, numSteps);

    cout << "\nsimulation results for model 1:" << endl;
    for (int t = 0; t < numSteps; ++t) {
        cout << "Time " << t + 1 << ": Temperature = " << simulationResults.model1[t] << endl;
    }

    cout << "\nsimulation results for model 2:" << endl;
    for (int t = 0; t < numSteps; ++t) {
        cout << "time " << t + 1 << ": temperature = " << simulationResults.model2[t] << endl;
    }

    return 0;
}
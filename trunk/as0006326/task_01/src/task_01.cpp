#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to model linear dynamics
vector<double> modelLinearDynamics(double alpha, double beta, double initialValue, const vector<double>& inputSignal, int steps) {
    vector<double> output(steps);
    output[0] = initialValue; // Initial temperature

    // Loop through each step to calculate the temperature
    for (int t = 1; t < steps; ++t) {
        output[t] = alpha * output[t - 1] + beta * inputSignal[t - 1]; // Update based on the linear model
    }

    return output; // Return the vector of temperatures
}

// Function to model nonlinear dynamics
vector<double> modelNonLinearDynamics(double alpha, double beta, double gamma, double delta, double initialValue, const vector<double>& inputSignal, int steps) {
    vector<double> output(steps);
    output[0] = initialValue; // Initial temperature

    // Loop through each step to calculate the temperature
    for (int t = 1; t < steps; ++t) {
        double prevOutput = output[t - 1];
        double prevInput = inputSignal[t - 1];
        output[t] = alpha * prevOutput - beta * pow(prevOutput, 2) + gamma * prevInput + delta * sin(prevInput); // Nonlinear update
    }

    return output; // Return the vector of temperatures
}

int main() {
    // Input constants from user
    double alpha, beta, gamma, delta, initialValue;
    cout << "Enter the constant alpha for the model: ";
    cin >> alpha;
    cout << "Enter the constant beta for the linear model: ";
    cin >> beta;
    cout << "Enter the constant gamma for the nonlinear model: ";
    cin >> gamma;
    cout << "Enter the constant delta for the nonlinear model: ";
    cin >> delta;
    cout << "Enter the initial value (initial temperature): ";
    cin >> initialValue;

    // Input the number of time steps
    int steps;
    cout << "Enter the number of time steps: ";
    cin >> steps;

    // Input the heat values
    vector<double> inputSignal(steps);
    cout << "Enter the input signal (heat) values for each time step:" << endl;
    for (int i = 0; i < steps; ++i) {
        cout << "inputSignal[" << i + 1 << "]: ";
        cin >> inputSignal[i]; // Read input for each heat value
    }

    // Simulate the linear dynamics
    vector<double> linearOutput = modelLinearDynamics(alpha, beta, initialValue, inputSignal, steps);

    // Simulate the nonlinear dynamics
    vector<double> nonlinearOutput = modelNonLinearDynamics(alpha, beta, gamma, delta, initialValue, inputSignal, steps);

    // Output results
    cout << "\nLinear Model Simulation:" << endl;
    for (int t = 0; t < steps; ++t) {
        cout << "Time " << t + 1 << ": Temperature = " << linearOutput[t] << endl;
    }

    cout << "\nNon-linear Model Simulation:" << endl;
    for (int t = 0; t < steps; ++t) {
        cout << "Time " << t + 1 << ": Temperature = " << nonlinearOutput[t] << endl;
    }

    return 0; // Indicate successful completion
}
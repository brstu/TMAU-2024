#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to simulate the linear model
vector<double> calculateLinearTemp(double alpha, double beta, double initialTemp, const vector<double>& heatInput, int steps) {
    vector<double> temperature(steps);
    temperature[0] = initialTemp; // Initial temperature

    // Loop through each time step to calculate the temperature
    for (int time = 1; time < steps; ++time) {
        temperature[time] = alpha * temperature[time - 1] + beta * heatInput[time - 1]; // Update temperature based on the linear model
    }

    return temperature; // Return the vector of temperatures
}

// Function to simulate the nonlinear model
vector<double> calculateNonLinearTemp(double alpha, double beta, double gamma, double delta, double initialTemp, const vector<double>& heatInput, int steps) {
    vector<double> temperature(steps);
    temperature[0] = initialTemp; // Initial temperature

    // Loop through each time step to calculate the temperature
    for (int time = 1; time < steps; ++time) {
        double prev_temp = temperature[time - 1];
        double prev_input = heatInput[time - 1];
        temperature[time] = alpha * prev_temp - beta * pow(prev_temp, 2) + gamma * prev_input + delta * sin(prev_input); // Nonlinear model update
    }

    return temperature; // Return the vector of temperatures
}

int main() {
    // Input constants from user
    double alpha, beta, gamma, delta, initialTemp;
    cout << "Enter the constant alpha for the model: ";
    cin >> alpha;
    cout << "Enter the constant beta for the linear model: ";
    cin >> beta;
    cout << "Enter the constant gamma for the nonlinear model: ";
    cin >> gamma;
    cout << "Enter the constant delta for the nonlinear model: ";
    cin >> delta;
    cout << "Enter the initial temperature (initialTemp): ";
    cin >> initialTemp;

    // Input the number of time moments
    int steps;
    cout << "Enter the number of discrete time moments: ";
    cin >> steps;

    // Input the heat values
    vector<double> heatInput(steps);
    cout << "Enter the heat values (heatInput) for each time moment:" << endl;
    for (int i = 0; i < steps; ++i) {
        cout << "heatInput[" << i + 1 << "]: ";
        cin >> heatInput[i]; // Read input for each heat value
    }

    // Simulate the linear model
    vector<double> linearTemp = calculateLinearTemp(alpha, beta, initialTemp, heatInput, steps);

    // Simulate the nonlinear model
    vector<double> nonLinearTemp = calculateNonLinearTemp(alpha, beta, gamma, delta, initialTemp, heatInput, steps);

    // Output results
    cout << "\nLinear Model Simulation:" << endl;
    for (int time = 0; time < steps; ++time) {
        cout << "Time " << time + 1 << ": Temperature = " << linearTemp[time] << endl;
    }

    cout << "\nNon-linear Model Simulation:" << endl;
    for (int time = 0; time < steps; ++time) {
        cout << "Time " << time + 1 << ": Temperature = " << nonLinearTemp[time] << endl;
    }

    return 0; // Indicate successful completion
}

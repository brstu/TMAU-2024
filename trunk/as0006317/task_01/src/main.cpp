#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Constants for the nonlinear model
const double COEFF_A = 1.34;
const double COEFF_B = 5.23;
const double COEFF_C = 4.37;
const double COEFF_D = 3.95;

// Linear model function
double CalculateLinearModel(double currentY, double coeffA, double coeffB, double inputU) {
    return coeffA * currentY + coeffB * inputU;
}

// Nonlinear model function
double CalculateNonLinearModel(double currentY, double prevY, double inputU, double prevU) {
    return COEFF_A * currentY - COEFF_B * pow(prevY, 2) + COEFF_C * inputU + COEFF_D * sin(prevU);
}

int main() {
    // Input variables
    double currentY;
    double previousY;
    double inputU;
    double previousU;
    double initialY;
    double initialU;
    double linearCoeffA;
    double linearCoeffB;
    int linearIterations;
    int nonLinearIterations;

    // Get parameters for the linear model
    cout << "Parameters for Linear Model" << endl;
    cout << "Enter coefficient a: ";
    cin >> linearCoeffA;
    cout << "Enter coefficient b: ";
    cin >> linearCoeffB;

    cout << "Enter initial value y: ";
    cin >> initialY;
    cout << "Enter initial value u: ";
    cin >> initialU;

    cout << endl;
    cout << "Number of iterations" << endl;
    cout << "Linear model iterations: ";
    cin >> linearIterations;
    cout << "Nonlinear model iterations: ";
    cin >> nonLinearIterations;

    cout << endl;
    cout << "Linear Model Results" << endl;
    currentY = initialY;
    inputU = initialU;
    for (int i = 0; i < linearIterations; ++i) {
        cout << "Enter input U: ";
        cin >> inputU;
        currentY = CalculateLinearModel(currentY, linearCoeffA, linearCoeffB, inputU);
        cout << "Iteration " << (i + 1) << ": Yt = " << currentY << endl;
    }

    cout << endl;
    cout << "Nonlinear Model Results" << endl;
    currentY = initialY;
    inputU = initialU;
    for (int i = 0; i < nonLinearIterations; ++i) {
        if (i > 0) {
            // Store previous values
            previousU = inputU;
            previousY = currentY;
        }
        else {
            // Initialize previous values for the first iteration
            previousU = 0;
            previousY = 0;
        }

        cout << "Enter input U: ";
        cin >> inputU;

        // Calculate current Y using the nonlinear model
        currentY = CalculateNonLinearModel(currentY, previousY, inputU, previousU);
        cout << "Iteration " << (i + 1) << ": Yt = " << currentY << endl;
    }

    return 0;
}
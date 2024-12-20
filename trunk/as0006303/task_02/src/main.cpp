#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Base class for mathematical models
class MathModel {
public:
    virtual double calcOutput(double currentOutput, double previousOutput, double input) const = 0; // Pure virtual function
    virtual ~MathModel() = default; // Default destructor
};

// Linear model class
class LinModel : public MathModel {
private:
    double coefficientA; // Coefficient A
    double coefficientB; // Coefficient B

public:
    // Constructor to initialize coefficients
    LinModel(double a, double b) : coefficientA(a), coefficientB(b) {}

    // Calculate output using the linear formula
    double calcOutput(double currentOutput, double previousOutput, double input) const override {
        return coefficientA * currentOutput + coefficientB * input;
    }
};

// Nonlinear model class
class NonlinModel : public MathModel {
private:
    double coefficientA, coefficientB, coefficientC, coefficientD; // Coefficients

public:
    // Constructor to initialize coefficients
    NonlinModel(double a, double b, double c, double d) 
        : coefficientA(a), coefficientB(b), coefficientC(c), coefficientD(d) {}

    // Calculate output using the nonlinear formula
    double calcOutput(double currentOutput, double previousOutput, double input) const override {
        return coefficientA * currentOutput - coefficientB * pow(previousOutput, 2) 
               + coefficientC * input + coefficientD * sin(input);
    }
};

// PID regulator class
class PIDRegulator {
private:
    double gainP, gainI, gainD; // PID gains
    double previousError = 0.0; // To store previous error
    double integralError = 0.0; // To accumulate error over time

public:
    // Constructor to initialize PID gains
    PIDRegulator(double p, double i, double d) 
        : gainP(p), gainI(i), gainD(d) {}

    // Calculate the control signal based on the current error
    double calcOutput(double currentError) {
        integralError += currentError; // Update the integral of the error
        double derivativeError = currentError - previousError; // Calculate derivative of the error
        double controlSignal = gainP * currentError + gainI * integralError + gainD * derivativeError; // PID formula
        previousError = currentError; // Update previous error
        return controlSignal; // Return the control signal
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); // Set locale for output

    // Declare coefficients for models
    double coefficientA_linear, coefficientB_linear;
    double coefficientA_nonlinear, coefficientB_nonlinear, coefficientC_nonlinear, coefficientD_nonlinear;

    // Input coefficients for the linear model
    cout << "Введите коэффициенты для линейной модели (A B): ";
    cin >> coefficientA_linear >> coefficientB_linear;

    // Input coefficients for the nonlinear model
    cout << "Введите коэффициенты для нелинейной модели (A B C D): ";
    cin >> coefficientA_nonlinear >> coefficientB_nonlinear >> coefficientC_nonlinear >> coefficientD_nonlinear;

    // Initialize outputs
    double currentOutput_linear = 0.0;
    double currentOutput_nonlinear = 0.0;
    double previousOutput_nonlinear = 0.0;
    double input = 1.0; // Example input value

    // Create model instances
    LinModel linModel(coefficientA_linear, coefficientB_linear);
    NonlinModel nonlinModel(coefficientA_nonlinear, coefficientB_nonlinear, coefficientC_nonlinear, coefficientD_nonlinear);
    PIDRegulator pidRegulator(1.0, 0.5, 0.2); // Create PID regulator

    // Vectors to store results
    vector<double> currentOutput_linear_values;
    vector<double> currentOutput_nonlinear_values;
    vector<double> error_values;
    vector<double> controlSignal_values;

    // Simulation loop for 10 iterations
    for (int t = 1; t <= 10; t++) {
        currentOutput_linear = linModel.calcOutput(currentOutput_linear, 0, input); // Calculate linear output
        currentOutput_nonlinear = nonlinModel.calcOutput(currentOutput_nonlinear, previousOutput_nonlinear, input); // Calculate nonlinear output
        previousOutput_nonlinear = currentOutput_nonlinear; // Update previous output

        // Calculate error
        double error = currentOutput_linear - currentOutput_nonlinear;
        double controlSignal = pidRegulator.calcOutput(error); // Calculate control signal

        // Store results
        currentOutput_linear_values.push_back(currentOutput_linear);
        currentOutput_nonlinear_values.push_back(currentOutput_nonlinear);
        error_values.push_back(error);
        controlSignal_values.push_back(controlSignal);
    }

    // Output results for each iteration
    for (int t = 0; t < 10; t++) {
        cout << "Итерация " << t + 1 << ":\n";
        cout << "Выход линейной модели: " << currentOutput_linear_values[t] << '\n';
        cout << "Выход нелинейной модели: " << currentOutput_nonlinear_values[t] << '\n';
        cout << "Ошибка: " << error_values[t] << '\n';
        cout << "Управляющий сигнал: " << controlSignal_values[t] << '\n';
        cout << '\n';
    }

    return 0; // End of program
}
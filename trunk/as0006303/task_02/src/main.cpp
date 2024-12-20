#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Abstract base class for mathematical models
class MathModel {
public:
    virtual double calcOutput(double currentOutput, double previousOutput, double input) const = 0;
    virtual ~MathModel() = default;
};

// Linear model class
class LinModel : public MathModel {
private:
    double coefficientA;
    double coefficientB;

public:
    LinModel(double coefficientA, double coefficientB) 
        : coefficientA(coefficientA), coefficientB(coefficientB) {}

    // Calculate output for the linear model
    double calcOutput(double currentOutput, double previousOutput, double input) const override {
        return coefficientA * currentOutput + coefficientB * input;
    }
};

// Nonlinear model class
class NonlinModel : public MathModel {
private:
    double coefficientA;
    double coefficientB;
    double coefficientC;
    double coefficientD;

public:
    NonlinModel(double coefficientA, double coefficientB, double coefficientC, double coefficientD)
        : coefficientA(coefficientA), coefficientB(coefficientB), 
          coefficientC(coefficientC), coefficientD(coefficientD) {}

    // Calculate output for the nonlinear model
    double calcOutput(double currentOutput, double previousOutput, double input) const override {
        return coefficientA * currentOutput - coefficientB * pow(previousOutput, 2) 
               + coefficientC * input + coefficientD * sin(input);
    }
};

// PID regulator class
class PIDRegulator {
private:
    double gainP;
    double gainI;
    double gainD;
    double previousError = 0.0;
    double integralError = 0.0;

public:
    PIDRegulator(double gainP, double gainI, double gainD)
        : gainP(gainP), gainI(gainI), gainD(gainD) {}

    // Calculate the control signal based on current error
    double calcOutput(double currentError) {
        integralError += currentError;
        double derivativeError = currentError - previousError;
        double controlSignal = gainP * currentError + gainI * integralError + gainD * derivativeError;
        previousError = currentError;
        return controlSignal;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Coefficients for the models can be input by the user
    double coefficientA_linear, coefficientB_linear;
    double coefficientA_nonlinear, coefficientB_nonlinear, coefficientC_nonlinear, coefficientD_nonlinear;

    cout << "Введите коэффициенты для линейной модели (A B): ";
    cin >> coefficientA_linear >> coefficientB_linear;

    cout << "Введите коэффициенты для нелинейной модели (A B C D): ";
    cin >> coefficientA_nonlinear >> coefficientB_nonlinear >> coefficientC_nonlinear >> coefficientD_nonlinear;

    double currentOutput_linear = 0.0;
    double currentOutput_nonlinear = 0.0;
    double previousOutput_nonlinear = 0.0;
    double input = 1.0; // Example input value

    // Create model instances
    LinModel linModel(coefficientA_linear, coefficientB_linear);
    NonlinModel nonlinModel(coefficientA_nonlinear, coefficientB_nonlinear, coefficientC_nonlinear, coefficientD_nonlinear);
    PIDRegulator pidRegulator(1.0, 0.5, 0.2); // PID gains

    // Vectors to store results
    vector<double> currentOutput_linear_values;
    vector<double> currentOutput_nonlinear_values;
    vector<double> error_values;
    vector<double> controlSignal_values;

    // Simulation loop
    for (int t = 1; t <= 10; t++) {
        currentOutput_linear = linModel.calcOutput(currentOutput_linear, 0, input);
        currentOutput_nonlinear = nonlinModel.calcOutput(currentOutput_nonlinear, previousOutput_nonlinear, input);
        previousOutput_nonlinear = currentOutput_nonlinear;

        double error = currentOutput_linear - currentOutput_nonlinear;
        double controlSignal = pidRegulator.calcOutput(error);

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

    return 0;
}
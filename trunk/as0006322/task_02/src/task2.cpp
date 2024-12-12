#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Abstract base class for mathematical models
class MathematicalModel {
public:
    virtual double calculateOutput(double current, double previous, double input) const = 0;
    virtual ~MathematicalModel() = default;
};

// Linear model implementation
class LinearModel : public MathematicalModel {
private:
    double a;
    double b;

public:
    LinearModel(double a, double b) : a(a), b(b) {}

    double calculateOutput(double current, double previous, double input) const override {
        return a * current + b * input;
    }
};

// Non-linear model implementation
class NonLinearModel : public MathematicalModel {
private:
    double a, b, c, d;

public:
    NonLinearModel(double a, double b, double c, double d)
        : a(a), b(b), c(c), d(d) {}

    double calculateOutput(double current, double previous, double input) const override {
        return a * current - b * pow(previous, 2) + c * input + d * sin(input);
    }
};

// PID Controller class
class PIDController {
private:
    double kp, ki, kd;
    double lastError = 0.0;
    double accumulatedError = 0.0;

public:
    PIDController(double kp, double ki, double kd)
        : kp(kp), ki(ki), kd(kd) {}

    double compute(double error) {
        accumulatedError += error;
        double deltaError = error - lastError;
        double output = kp * error + ki * accumulatedError + kd * deltaError;
        lastError = error;
        return output;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Model parameters
    LinearModel linearModel(0.6, 0.5);
    NonLinearModel nonLinearModel(0.7, 0.3, 0.4, 0.2);
    PIDController pidController(1.0, 0.7, 0.3);

    double linearOutput = 0.0;
    double notLinearOutput = 0.0;
    double lastNonLinearOutput = 0.0;
    double inputValue = 1.0;

    // Vectors to store outputs and errors
    vector<double> linearOutputs;
    vector<double> nonLinearOutputs;
    vector<double> errors;
    vector<double> controlOutputs;

    // Simulation loop
    for (int i = 1; i <= 10; i++) {
        linearOutput = linearModel.calculateOutput(linearOutput, 0, inputValue);
        notLinearOutput = nonLinearModel.calculateOutput(notLinearOutput, lastNonLinearOutput, inputValue);
        lastNonLinearOutput = notLinearOutput;

        double error = linearOutput - notLinearOutput;
        double controlOutput = pidController.compute(error);

        linearOutputs.push_back(linearOutput);
        nonLinearOutputs.push_back(notLinearOutput);
        errors.push_back(error);
        controlOutputs.push_back(controlOutput);
    }

    // Output results for each iteration
    for (int i = 0; i < 10; i++) {
        cout << "Iteration " << i + 1 << ":\n";
        cout << "Выход линейной модели: " << linearOutputs[i] << '\n';
        cout << "Выход нелинейной модели: " << nonLinearOutputs[i] << '\n';
        cout << "Error: " << errors[i] << '\n';
        cout << "Управляющий сигнал: " << controlOutputs[i] << '\n';
        cout << '\n';
    }

    return 0;
}
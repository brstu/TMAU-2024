#include <iostream>
#include <vector>
#include <cmath>

// Abstract base class representing a mathematical model
class BaseModel {
public:
    // Pure virtual method to compute the output of the model
    virtual double computeOutput(double current, double previous, double input) const = 0;
    virtual ~BaseModel() = default;
};

// Class representing a nonlinear mathematical model
class NonlinearModel : public BaseModel {
private:
    double paramAlpha; // Coefficient for current output
    double paramBeta;  // Coefficient for squared previous output
    double paramGamma; // Coefficient for input
    double paramDelta; // Coefficient for sine of input

public:
    // Constructor to initialize coefficients
    NonlinearModel(double alpha, double beta, double gamma, double delta)
        : paramAlpha(alpha), paramBeta(beta), paramGamma(gamma), paramDelta(delta) {}

    // Compute the output based on a nonlinear formula
    double computeOutput(double current, double previous, double input) const override {
        return paramAlpha * current - paramBeta * std::pow(previous, 2) + paramGamma * input + paramDelta * std::sin(input);
    }
};

// Class representing a linear mathematical model
class LinearModel : public BaseModel {
private:
    double factorA; // Coefficient for current output
    double factorB; // Coefficient for input signal

public:
    // Constructor to initialize coefficients
    LinearModel(double a, double b) : factorA(a), factorB(b) {}

    // Compute the output based on a linear formula
    double computeOutput(double current, double previous, double input) const override {
        return factorA * current + factorB * input;
    }
};

// Class representing a PID controller
class PIDController {
private:
    double gainProportional; // Proportional gain
    double gainIntegral;     // Integral gain
    double gainDerivative;   // Derivative gain

    double accumulatedError = 0.0; // Sum of errors for integral term
    double previousError = 0.0;    // Previous error for derivative term

public:
    // Constructor to initialize PID gains
    PIDController(double kp, double ki, double kd)
        : gainProportional(kp), gainIntegral(ki), gainDerivative(kd) {}

    // Calculate the control signal based on the error
    double calculateControlSignal(double error) {
        accumulatedError += error;
        double rateOfChange = error - previousError;

        double controlSignal = gainProportional * error +
                               gainIntegral * accumulatedError +
                               gainDerivative * rateOfChange;

        previousError = error;
        return controlSignal;
    }
};

// Main function to simulate the models and PID controller
int main() {
    // Coefficients for models
    double alphaLinear = 0.6, betaLinear = 0.3;
    double alphaNonlinear = 0.8, betaNonlinear = 0.5, gammaNonlinear = 0.2, deltaNonlinear = 0.1;

    // Initial values
    double linearOutput = 0.0;
    double nonlinearOutput = 0.0;
    double previousNonlinearOutput = 0.0;
    double inputSignal = 1.0;

    // Create instances of models and PID controller
    LinearModel linearModel(alphaLinear, betaLinear);
    NonlinearModel nonlinearModel(alphaNonlinear, betaNonlinear, gammaNonlinear, deltaNonlinear);
    PIDController pidController(1.2, 0.6, 0.3);

    // Vectors to store results
    std::vector<double> linearResults;
    std::vector<double> nonlinearResults;
    std::vector<double> errorResults;
    std::vector<double> controlSignals;

    // Simulate for 10 iterations
    for (int step = 1; step <= 10; ++step) {
        linearOutput = linearModel.computeOutput(linearOutput, 0, inputSignal);
        nonlinearOutput = nonlinearModel.computeOutput(nonlinearOutput, previousNonlinearOutput, inputSignal);

        previousNonlinearOutput = nonlinearOutput;

        double error = linearOutput - nonlinearOutput;
        double controlSignal = pidController.calculateControlSignal(error);

        linearResults.push_back(linearOutput);
        nonlinearResults.push_back(nonlinearOutput);
        errorResults.push_back(error);
        controlSignals.push_back(controlSignal);
    }

    // Display results
    for (size_t i = 0; i < linearResults.size(); ++i) {
        std::cout << "Step " << i + 1 << ":\n";
        std::cout << "Linear Model Output: " << linearResults[i] << "\n";
        std::cout << "Nonlinear Model Output: " << nonlinearResults[i] << "\n";
        std::cout << "Error: " << errorResults[i] << "\n";
        std::cout << "Control Signal: " << controlSignals[i] << "\n\n";
    }

    return 0;
}

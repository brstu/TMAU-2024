#include <iostream>
#include <cmath>
#include <array>
using namespace std;

// Abstract class for mathematical models
class BaseModel {
public:
    /*
    Virtual function for simulating temperature with input parameters:
        current_temp - current temperature of the model
        input_signal - input value
        return - output temperature
    */
    virtual double simulateTemperature(double current_temp, double input_signal) = 0;

    virtual ~BaseModel() = default;
};

// Linear temperature control model
class LinearModel : public BaseModel {
private:
    double coefficientA; // Model coefficient A
    double coefficientB; // Model coefficient B

public:
    // Constructor with specified coefficients A and B
    LinearModel(double coefficientA, double coefficientB) : coefficientA(coefficientA), coefficientB(coefficientB) {}

    // Method to calculate output temperature of the linear model
    double simulateTemperature(double current_temp, double input_signal) final {
        return coefficientA * current_temp + coefficientB * input_signal;
    }

    // Destructor
    ~LinearModel() override = default;
};

class NonLinearModel : public BaseModel {
private:
    double coefficientA; // Model coefficient A
    double coefficientB; // Model coefficient B
    double coefficientC; // Model coefficient C
    double coefficientD; // Model coefficient D
    double previousTemp = 0;
    double previousInput = 0;

public:
    // Constructor with specified coefficients A, B, C, D
    NonLinearModel(double coefficientA, double coefficientB, double coefficientC, double coefficientD) :
        coefficientA(coefficientA),
        coefficientB(coefficientB),
        coefficientC(coefficientC),
        coefficientD(coefficientD) {}

    // Method to calculate output temperature of the nonlinear model
    double simulateTemperature(double current_temp, double input_signal) {
        double result = coefficientA * current_temp + coefficientB * pow(previousTemp, 2) + coefficientC * input_signal + coefficientD * sin(previousInput);
        previousTemp = current_temp;
        previousInput = input_signal;
        return result;
    }

    // Destructor
    ~NonLinearModel() override = default;
};

class PIDController {
private:
    const double proportionalGain = 0.1; // Proportional gain
    const double integrationTime = 10; // Integration time
    const double differentiationTime = 80; // Differentiation time
    const double quantizationTime = 50; // Quantization time
    const double simulationDuration = 30; // Simulation duration
    double controlSignal = 0; // Control signal value

    /*
    Method to compute the control signal
        error - error value
        return - value of the control signal
    */
    double computeControlSignal(double error) {
        array<double, 3> recentErrors = { 0, 0, 0 }; // Storage for the last three errors
        recentErrors[2] = recentErrors[1]; // Shift errors
        recentErrors[1] = recentErrors[0];
        recentErrors[0] = error; // Store current error

        // Coefficients for the PID formula
        array<double, 3> pidCoefficients = { proportionalGain * (1 + differentiationTime / quantizationTime),
                                              -proportionalGain * (1 + 2 * differentiationTime / quantizationTime - quantizationTime / integrationTime),
                                              proportionalGain * differentiationTime / quantizationTime };

        // Calculate control signal
        for (int i = 0; i < 3; i++) {
            controlSignal += pidCoefficients[i] * recentErrors[i];
        }

        return controlSignal;
    }

public:
    /*
    Method for simulating regulation
        targetTemperature - desired temperature
        initialTemperature - starting temperature
        model - linear or nonlinear model
    */
    void regulateTemperature(double targetTemperature, double initialTemperature, BaseModel& model) {
        double currentTemperature = initialTemperature;
        for (int i = 1; i <= simulationDuration; i++) {
            double error = targetTemperature - currentTemperature;
            controlSignal = computeControlSignal(error);
            currentTemperature = model.simulateTemperature(initialTemperature, controlSignal);
            cout << "Error = " << error << "\t"
                << "Current Temperature = " << currentTemperature << "\t"
                << "Control Signal = " << controlSignal << endl;
        }
        controlSignal = 0;
    }
};

/*
Function to input model parameters
    coefficientA - constant A
    coefficientB - constant B
    coefficientC - constant C
    coefficientD - constant D
    isNonLinear - model type
*/
void inputModelParameters(double& coefficientA, double& coefficientB, double& coefficientC, double& coefficientD, bool isNonLinear) {
    cout << "Enter coefficient A: ";
    cin >> coefficientA;
    cout << "Enter coefficient B: ";
    cin >> coefficientB;
    if (isNonLinear) {
        cout << "Enter coefficient C: ";
        cin >> coefficientC;
        cout << "Enter coefficient D: ";
        cin >> coefficientD;
    }
}

int main() {
    system("chcp 1251");
    system("cls");

    struct ModelSettings {
        double coefficientA;
        double coefficientB;
        double coefficientC;
        double coefficientD;
    };

    array<const char*, 2> modelTitles = { "Linear Model", "Non-Linear Model" }; // Model names
    array<ModelSettings, 2> modelConfigurations; // Input model parameters
    for (int i = 0; i < 2; i++) {
        cout << "_____________________________________" << modelTitles[i] << ". Enter parameters___________________________________________________" << endl;
        inputModelParameters(modelConfigurations[i].coefficientA, modelConfigurations[i].coefficientB, modelConfigurations[i].coefficientC, modelConfigurations[i].coefficientD, i);
    }

    // Create models with input parameters
    LinearModel linearModel(modelConfigurations[0].coefficientA, modelConfigurations[0].coefficientB);
    NonLinearModel nonlinearModel(modelConfigurations[1].coefficientA, modelConfigurations[1].coefficientB, modelConfigurations[1].coefficientC, modelConfigurations[1].coefficientD);

    PIDController pidController;

    const double targetTemperature = 12;
    const double initialTemperature = 5;

    cout << "\t______________________________Linear Model__________________________________" << endl;
    pidController.regulateTemperature(targetTemperature, initialTemperature, linearModel);
    cout << endl;

    cout << "\t______________________________Non-Linear Model______________________________" << endl;
    pidController.regulateTemperature(targetTemperature, initialTemperature, nonlinearModel);
}
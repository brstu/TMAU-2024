#include <iostream>
#include <cmath>
using namespace std;

// Линейная модель
void linearModel(double coeffA, double coeffB, double heatInput, double currentTemp, int cycles) {
    cout << "\tЛинейная модель" << endl;
    for (int i = 1; i <= cycles; i++) {
        double nextTemp = coeffA * currentTemp + coeffB * heatInput; // Вычисление следующей температуры
        cout << "y" << i << " = " << nextTemp << endl; // Используем следующую температуру
        currentTemp = nextTemp; // Обновление текущей температуры для следующей итерации
    }
}

// Нелинейная модель
void nonlinearModel(double coeffA, double coeffB, double coeffC, double coeffD, double heatInput, double currentTemp, int cycles) {
    double prevHeat = 0;
    double prevTemp = 0;

    cout << "\tНелинейная модель" << endl;
    for (int i = 1; i <= cycles; i++) {
        double nextTemp = coeffA * currentTemp - coeffB * pow(prevTemp, 2) + coeffC * heatInput + coeffD * sin(prevHeat);
        cout << "y" << i << " = " << nextTemp << endl;
        prevHeat = heatInput;
        prevTemp = currentTemp;
        currentTemp = nextTemp; // Обновление текущей температуры для следующей итерации
=======
#include <array>
using namespace std;

// Abstract class for mathematical models
class BaseModel {
public:
    /*
    Virtual function for simulating temperature with input parameters:
        currentTemperature - current temperature of the model
        inputSignal - input value
        return - output temperature
    */
    virtual double simulateTemperature(double currentTemperature, double inputSignal) = 0;

    virtual ~BaseModel() = default; // Virtual destructor for proper cleanup
};

// Linear temperature control model
class LinearModel : public BaseModel {
private:
    double linearCoefficientA; // Linear model coefficient A
    double linearCoefficientB; // Linear model coefficient B

public:
    // Constructor with specified coefficients A and B
    LinearModel(double linearCoefficientA, double linearCoefficientB) : 
        linearCoefficientA(linearCoefficientA), 
        linearCoefficientB(linearCoefficientB) {}

    // Method to calculate output temperature of the linear model
    double simulateTemperature(double currentTemperature, double inputSignal) final {
        return linearCoefficientA * currentTemperature + linearCoefficientB * inputSignal;
    }

    // Destructor
    ~LinearModel() override = default;
};

// Non-linear temperature control model
class NonLinearModel : public BaseModel {
private:
    double nonLinearCoefficientA; // Non-linear model coefficient A
    double nonLinearCoefficientB; // Non-linear model coefficient B
    double nonLinearCoefficientC; // Non-linear model coefficient C
    double nonLinearCoefficientD; // Non-linear model coefficient D
    double previousTemperature = 0; // Store previous temperature for calculations
    double previousInput = 0; // Store previous input for calculations

public:
    // Constructor with specified coefficients A, B, C, D
    NonLinearModel(double nonLinearCoefficientA, double nonLinearCoefficientB, 
                   double nonLinearCoefficientC, double nonLinearCoefficientD) :
        nonLinearCoefficientA(nonLinearCoefficientA),
        nonLinearCoefficientB(nonLinearCoefficientB),
        nonLinearCoefficientC(nonLinearCoefficientC),
        nonLinearCoefficientD(nonLinearCoefficientD) {}

    // Method to calculate output temperature of the non-linear model
    double simulateTemperature(double currentTemperature, double inputSignal) {
        double result = nonLinearCoefficientA * currentTemperature + 
                        nonLinearCoefficientB * pow(previousTemperature, 2) + 
                        nonLinearCoefficientC * inputSignal + 
                        nonLinearCoefficientD * sin(previousInput);
        previousTemperature = currentTemperature; // Update previous temperature
        previousInput = inputSignal; // Update previous input
        return result; // Return the calculated temperature
    }

    // Destructor
    ~NonLinearModel() override = default;
};

// PID Controller class
class PIDController {
private:
    const double proportionalGain = 0.1; // Proportional gain for PID
    const double integrationTime = 10; // Time constant for integration
    const double differentiationTime = 80; // Time constant for differentiation
    const double quantizationTime = 50; // Time constant for quantization
    const double simulationDuration = 30; // Duration of the simulation
    double controlSignal = 0; // Control signal value

    /*
    Method to compute the control signal based on the error
        error - the difference between target and current temperature
        return - computed control signal value
    */
    double computeControlSignal(double error) {
        array<double, 3> recentErrors = { 0, 0, 0 }; // Array to store the last three errors
        recentErrors[2] = recentErrors[1]; // Shift errors
        recentErrors[1] = recentErrors[0];
        recentErrors[0] = error; // Store the current error

        // Coefficients for the PID formula
        array<double, 3> pidCoefficients = { proportionalGain * (1 + differentiationTime / quantizationTime),
                                              -proportionalGain * (1 + 2 * differentiationTime / quantizationTime - quantizationTime / integrationTime),
                                              proportionalGain * differentiationTime / quantizationTime };

        // Calculate control signal by summing contributions from recent errors
        for (int i = 0; i < 3; i++) {
            controlSignal += pidCoefficients[i] * recentErrors[i];
        }

        return controlSignal; // Return the computed control signal
    }

public:
    /*
    Method for simulating temperature regulation
        targetTemperature - the desired temperature to reach
        initialTemperature - starting temperature for the simulation
        model - an instance of the linear or non-linear model
    */
    void regulateTemperature(double targetTemperature, double initialTemperature, BaseModel& model) {
        double currentTemperature = initialTemperature; // Initialize current temperature
        for (int i = 1; i <= simulationDuration; i++) {
            double error = targetTemperature - currentTemperature; // Calculate error
            controlSignal = computeControlSignal(error); // Compute control signal
            currentTemperature = model.simulateTemperature(initialTemperature, controlSignal); // Update current temperature based on the model
            cout << "Error = " << error << "\t"
                 << "Current Temperature = " << currentTemperature << "\t"
                 << "Control Signal = " << controlSignal << endl; // Output current state
        }
        controlSignal = 0; // Reset control signal after simulation
    }
};

/*
Function to input model parameters
    coefficientA - constant A for the model
    coefficientB - constant B for the model
    coefficientC - constant C for the model (if non-linear)
    coefficientD - constant D for the model (if non-linear)
    isNonLinear - indicates if the model is non-linear
*/
void inputModelParameters(double& coefficientA, double& coefficientB, double& coefficientC, double& coefficientD, bool isNonLinear) {
    cout << "Enter coefficient A: ";
    cin >> coefficientA; // Input coefficient A
    cout << "Enter coefficient B: ";
    cin >> coefficientB; // Input coefficient B
    if (isNonLinear) {
        cout << "Enter coefficient C: ";
        cin >> coefficientC; // Input coefficient C for non-linear model
        cout << "Enter coefficient D: ";
        cin >> coefficientD; // Input coefficient D for non-linear model


#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// Class representing a Linear Model for temperature calculations
class LinearTemperatureModel
{
private:
    double coefficientA; // Linear coefficient A
    double coefficientB; // Linear coefficient B
    double currentTemperature; // Current computed temperature

public:
    // Constructor initializing the coefficients and initial temperature
    LinearTemperatureModel(double a, double b, double initialTemperature)
        : coefficientA(a), coefficientB(b), currentTemperature(initialTemperature)
    {
    }

    // Function to calculate the new temperature based on the linear equation
    double calculateTemperature(double inputTemperature, double inputHeat) {
        currentTemperature = coefficientA * inputTemperature + coefficientB * inputHeat;
        return currentTemperature;
    }
};

// Class representing a Non-Linear Model for temperature calculations
class NonLinearTemperatureModel
{
private:
    double paramA; // Non-linear coefficient A
    double paramB; // Non-linear coefficient B
    double paramC; // Non-linear coefficient C
    double paramD; // Non-linear coefficient D
    double previousTemperature = 0; // Temperature from the previous step
    double currentTemperature; // Current computed temperature
    double inputHeat = 0; // Input heat value for calculations

public:
    // Constructor initializing the coefficients and initial temperature
    NonLinearTemperatureModel(double a, double b, double c, double d, double initialTemperature)
        : paramA(a), paramB(b), paramC(c), paramD(d), currentTemperature(initialTemperature)
    {
    }

    // Function to calculate the new temperature based on the non-linear equation
    double calculateTemperature(double inputTemperature, double inputHeatValue) {
        currentTemperature = paramA * inputTemperature
            - paramB * pow(previousTemperature, 2)
            + paramC * inputHeatValue
            + paramD * sin(this->inputHeat);
        this->inputHeat = inputHeatValue; // Update input heat for the next calculation
        previousTemperature = inputTemperature; // Store the current temperature for the next iteration
        return currentTemperature;
    }
};

// Class for the PID Controller
class PIDController
{
private:
    double samplingPeriod; // Sampling period T
    double proportionalPeriod; // Proportional period TP
    double integrationPeriod; // Integration period TM
    double gain; // Gain factor K
    double controlOutput = 0; // Control output value

public:
    // Constructor initializing the PID parameters
    PIDController(double t, double tp, double tm, double k)
        : samplingPeriod(t), proportionalPeriod(tp), integrationPeriod(tm), gain(k)
    {
    }

    // Function to calculate the control output based on errors
    double computeControlOutput(double currentError, double previousError1, double previousError2) {
        double q0, q1, q2;

        // Calculate the PID coefficients based on the sampling period and gains
        q0 = gain * (1 + integrationPeriod / proportionalPeriod);
        q1 = -gain * (1 + 2 * integrationPeriod / proportionalPeriod - proportionalPeriod / samplingPeriod);
        q2 = gain * integrationPeriod / proportionalPeriod;

        // Update control output based on the current and previous errors
        controlOutput += q0 * currentError + q1 * previousError1 + q2 * previousError2;
        return controlOutput;
    }
};

// Function implementing the PID control logic
void executePIDControl(double targetTemperature, double initialTemperature, PIDController& controller,
    LinearTemperatureModel& linearModel, NonLinearTemperatureModel& nonLinearModel, bool isLinear) {
    ofstream outputFile;
    outputFile.open("D:\\result.txt", ios_base::out | ios_base::app); // Open file for logging results

    if (outputFile.is_open()) {
        double previousError1 = 0;
        double previousError2 = 0;
        double currentTemperature = initialTemperature;

        // Run the PID control loop for a fixed number of iterations
        for (int iteration = 0; iteration < 100; iteration++) {
            double currentError;
            double controlOutput;

            // Calculate the current error as the difference from the target temperature
            currentError = targetTemperature - currentTemperature;
            controlOutput = controller.computeControlOutput(currentError, previousError1, previousError2); // Calculate control output

            // Depending on the selected model, calculate the new temperature
            if (isLinear) {
                currentTemperature = linearModel.calculateTemperature(initialTemperature, controlOutput);
            }
            else {
                currentTemperature = nonLinearModel.calculateTemperature(initialTemperature, controlOutput);
            }

            // Log the results to the output file
            outputFile << "Error=" << currentError << " CurrentTemp=" << currentTemperature << " ControlOutput=" << controlOutput << endl;

            // Update previous errors for the next iteration
            previousError2 = previousError1;
            previousError1 = currentError;
        }
    }
    outputFile.close(); // Close the output file after writing results
}

// Main function to drive the program
int main() {
    setlocale(0, ""); // Set locale for Russian language support
    ofstream outputFile;
    outputFile.open("D:\\result.txt", ios_base::out | ios_base::app); // Open file for logging results

    if (outputFile.is_open()) {
        outputFile << "Linear Temperature Model Results:" << endl;
        LinearTemperatureModel linearModel(0.333f, 0.667f, 1); // Initialize linear model
        NonLinearTemperatureModel nonLinearModel(1.0f, 0.0033f, 0.525f, 0.525f, 1.0f); // Initialize non-linear model
        PIDController pidController(10, 10, 50, 0.1f); // Initialize PID controller

        // Execute PID control for linear model
        executePIDControl(5, 2, pidController, linearModel, nonLinearModel, true);

        outputFile << "Non-Linear Temperature Model Results:" << endl;
        PIDController nonLinearPIDController(10, 10, 50, 0.1f); // Initialize PID controller for non-linear model
        executePIDControl(5, 2, nonLinearPIDController, linearModel, nonLinearModel, false); // Execute PID control for non-linear model
    }

    cout << "Results saved to result.txt" << endl; // Notify user that results have been saved
    return 0; // End of the program
}
# Report

## About the Report
This report contains information about a program that simulates a PID controller. The control object is based on a mathematical temperature model, along with classes representing linear and nonlinear models.

## Classes

### Class "BaseModel"
This abstract class serves as a foundation for creating mathematical models. It includes a virtual function simulateTemperature, which must be implemented in derived classes. This function takes the current temperature and input signal and returns the calculated output temperature based on the model.

### Class "LinearModel"

The LinearModel class, which inherits from BaseModel, represents a linear model. It contains two coefficients: coefficientA and coefficientB, which are used to compute the output value using the formula coefficientA * current_temp + coefficientB * input_signal.

### Class "NonLinearModel"

This class implements a nonlinear mathematical model and also inherits from the abstract class BaseModel, implementing its virtual function simulateTemperature. It includes four private variables: coefficientA, coefficientB, coefficientC, and coefficientD. The constructor takes the values of these coefficients and initializes them using the formula coefficientA * current_temp + coefficientB * pow(previousTemp, 2) + coefficientC * input_signal + coefficientD * sin(previousInput), allowing the calculation of the output value based on current and previous outputs, as well as the input signal.

### Class "PIDController"

The PIDController class is responsible for the functioning of the PID controller. It includes five coefficients: proportionalGain, integrationTime, differentiationTime, quantizationTime, and simulationDuration, as well as a variable controlSignal. The method regulateTemperature takes the target and initial temperatures, along with the model type for simulation, and computes the control signal.
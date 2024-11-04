# Report

## About the Report

This report provides information about a program that models a PID controller. The controlled object uses a mathematical model, as well as classes representing linear and nonlinear models.

## Classes

### Class `MathModel`

An abstract base class for mathematical models. It contains a virtual function calcOutput that must be implemented in derived classes. This function takes the current output, previous output, and input signal, and returns the computed output of the model.

### Class `LinModel`

A class that inherits from MathModel and represents a linear model. It has two coefficients, coefficientA and coefficientB, which are used to calculate the output value according to the formula coefficientA * currentOutput + coefficientB * input.

### Class `NonlinearModel`

Represents a nonlinear mathematical model. This class inherits from the abstract class MathModel and implements its virtual function calcOutput. It has four private variables - coefficientA, coefficientB, coefficientC, and coefficientD, which are used in the formula to calculate the model’s output value. The class constructor accepts values for coefficientA, coefficientB, coefficientC, and coefficientD and initializes the respective private variables.

The calcOutput function is overridden in the NonlinearModel class and uses the formula coefficientA * currentOutput - coefficientB * pow(previousOutput, 2) + coefficientC * input + coefficientD * sin(input) to compute the model's output based on the current output, previous output, and input value.

### Class `PIDRegulator`

A class that implements the PID controller. It has three coefficients, gainP, gainI, and gainD, which correspond to the proportional, integral, and derivative components of the controller, respectively. The calcOutput function takes the current error and calculates the control signal based on the coefficients and accumulated errors.
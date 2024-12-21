# Doxygen Documentation

## Overview
This project implements a simulation of mathematical models and a PID controller. It includes:
- A linear mathematical model.
- A nonlinear mathematical model.
- A PID controller to compute control signals based on the error between models.

---

## Classes

### MathModel
**Abstract base class** for mathematical models.

#### Public Methods:
- `virtual double computeOutput(double currentOutput, double prevOutput, double inputSignal) const = 0;`  
  Compute the output of the mathematical model.  
  - **Parameters:**
    - `currentOutput` (*double*): Current output value.
    - `prevOutput` (*double*): Previous output value.
    - `inputSignal` (*double*): Input signal value.  
  - **Returns:** Computed output value.

---

### NonlinearModel
**Class for nonlinear mathematical models.**  
Derived from `MathModel`.

#### Private Members:
- `double factorA;`  
  Coefficient for the current output.
- `double factorB;`  
  Coefficient for the square of the previous output.
- `double factorC;`  
  Coefficient for the input signal.
- `double factorD;`  
  Coefficient for the sine of the input signal.

#### Public Methods:
- `NonlinearModel(double factorA, double factorB, double factorC, double factorD);`  
  Constructor to initialize coefficients.  
  - **Parameters:**  
    - `factorA` (*double*): Coefficient A.
    - `factorB` (*double*): Coefficient B.
    - `factorC` (*double*): Coefficient C.
    - `factorD` (*double*): Coefficient D.

- `double computeOutput(double currentOutput, double prevOutput, double inputSignal) const override;`  
  Compute the output of the nonlinear model.  
  - **Parameters:**  
    - `currentOutput` (*double*): Current output value.
    - `prevOutput` (*double*): Previous output value.
    - `inputSignal` (*double*): Input signal value.  
  - **Returns:** Computed output value.

---

### LinearModel
**Class for linear mathematical models.**  
Derived from `MathModel`.

#### Private Members:
- `double linearCoefA;`  
  Coefficient for the current output.
- `double linearCoefB;`  
  Coefficient for the input signal.

#### Public Methods:
- `explicit LinearModel(double linearCoefA, double linearCoefB);`  
  Constructor to initialize coefficients.  
  - **Parameters:**  
    - `linearCoefA` (*double*): Coefficient A.
    - `linearCoefB` (*double*): Coefficient B.

- `double computeOutput(double currentOutput, double prevOutput, double inputSignal) const override;`  
  Compute the output of the linear model.  
  - **Parameters:**  
    - `currentOutput` (*double*): Current output value.
    - `prevOutput` (*double*): Previous output value.
    - `inputSignal` (*double*): Input signal value.  
  - **Returns:** Computed output value.

---

### PIDController
**Class implementing a PID controller.**

#### Private Members:
- `double gainP;`  
  Proportional gain.
- `double gainI;`  
  Integral gain.
- `double gainD;`  
  Derivative gain.
- `double lastError;`  
  Last error value.
- `double cumulativeError;`  
  Accumulated error for the integral term.
- `double lastControlSignal;`  
  Last computed control signal.

#### Public Methods:
- `explicit PIDController(double gainP, double gainI, double gainD);`  
  Constructor to initialize gains.  
  - **Parameters:**  
    - `gainP` (*double*): Proportional gain.
    - `gainI` (*double*): Integral gain.
    - `gainD` (*double*): Derivative gain.

- `double computeControl(double currentError);`  
  Compute the control signal based on the current error.  
  - **Parameters:**  
    - `currentError` (*double*): The difference between desired and actual values.  
  - **Returns:** Computed control signal.

---

## Main Function
**Simulates the interaction between models and a PID controller.**

#### Process:
1. Creates instances of `LinearModel`, `NonlinearModel`, and `PIDController`.
2. Runs a simulation for 10 iterations:
   - Computes outputs of linear and nonlinear models.
   - Calculates error between the models.
   - Uses the PID controller to generate control signals.
3. Outputs the results for each iteration.

#### Return Value:
- Returns `0` upon successful completion.
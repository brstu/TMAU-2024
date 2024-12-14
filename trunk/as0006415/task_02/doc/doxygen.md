# PID Controller Modeling - Documentation

## Overview

**PID Controller Modeling** is the second laboratory work for modeling and analyzing the behavior of a PID controller.

## Project Structure

The project is organized as follows:

- `src/` - Contains the main source code files.
- `docs/` - Generated documentation files.
- `tests/` - Contains unit tests for the project.

## Files

### `pid_controller.h`

This file defines the **PIDController** class that implements the PID control algorithm. It includes methods for setting the PID constants, updating the control signal, and getting the control signal.

```cpp
class PIDController {
public:
    PIDController(double kp, double ki, double kd);
    void setPIDConstants(double kp, double ki, double kd);
    double update(double setpoint, double actual_value);
    double getControlSignal();
private:
    double _kp;
    double _ki;
    double _kd;
    double _prev_error;
    double _integral;
};
```

### `pid_controller.cpp`

This file implements the methods declared in `pid_controller.h`.

```cpp
PIDController::PIDController(double kp, double ki, double kd)
    : _kp(kp), _ki(ki), _kd(kd), _prev_error(0.0), _integral(0.0) {}

void PIDController::setPIDConstants(double kp, double ki, double kd) {
    _kp = kp;
    _ki = ki;
    _kd = kd;
}

double PIDController::update(double setpoint, double actual_value) {
    double error = setpoint - actual_value;
    _integral += error;
    double derivative = error - _prev_error;
    _prev_error = error;
    return (_kp * error) + (_ki * _integral) + (_kd * derivative);
}

double PIDController::getControlSignal() {
    return _control_signal;
}
```

### `main.cpp`

The entry point of the program where the PID controller is instantiated and used to control a system.

```cpp
#include "pid_controller.h"
#include <iostream>

int main() {
    PIDController pid(1.0, 0.1, 0.01);
    double setpoint = 100.0; // Desired value
    double actual_value = 90.0; // Current value

    while (true) {
        double control_signal = pid.update(setpoint, actual_value);
        std::cout << "Control Signal: " << control_signal << std::endl;
        
        // Simulate the system response
        actual_value += control_signal;
        
        // Exit condition
        if (abs(setpoint - actual_value) < 0.1) break;
    }

    return 0;
}
```

## Functions and Classes

### **PIDController**

- **Constructor:**
    - `PIDController(double kp, double ki, double kd)`
    - Initializes the PID constants.

- **Methods:**
    - `void setPIDConstants(double kp, double ki, double kd)`
        - Sets the PID constants.
    - `double update(double setpoint, double actual_value)`
        - Updates the control signal based on the setpoint and actual value.
    - `double getControlSignal()`
        - Returns the current control signal.

## Usage

To use the PID controller, include `pid_controller.h` and instantiate the `PIDController` class with desired PID constants. Use the `update()` method to calculate the control signal, and adjust the system accordingly.

```cpp
PIDController pid(1.0, 0.1, 0.01);
double control_signal = pid.update(setpoint, actual_value);
```

## Compilation and Running

To compile and run the project, you can use a C++ compiler like g++:

```bash
g++ -o pid_controller pid_controller.cpp main.cpp
./pid_controller
```

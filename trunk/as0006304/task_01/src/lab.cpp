#include <iostream>
#include <cmath>

// Constants
constexpr double C = 1.0;
constexpr double RC = 2.0;
constexpr double a = 0.8;
constexpr double b = 0.2;
constexpr double c = 0.5;
constexpr double d = 0.1;
constexpr double roomTemp = 20.0;

// Linear model
double calculateLinearModel(double currentTemp, double inputWarm) {
    return a * currentTemp + b * inputWarm;
}

// Nonlinear model
double calculateNonlinearModel(double currentTemp, double prevTemp, double inputWarm) {
    return a * currentTemp - b * prevTemp + c * inputWarm + d * std::sin(inputWarm - 1);
}

int main() {
    double time, inputTemp, inputWarm;
    std::cout << "Enter time, input temperature, and input warm: ";
    std::cin >> time >> inputTemp >> inputWarm;

    // Calculate temperature using linear model
    double nextTempLinear = calculateLinearModel(inputTemp, inputWarm);
    std::cout << "Temperature using linear model: " << nextTempLinear << std::endl;

    // Calculate temperature using nonlinear model
    double nextTempNonlinear = calculateNonlinearModel(inputTemp, nextTempLinear, inputWarm);
    std::cout << "Temperature using nonlinear model: " << nextTempNonlinear << std::endl;

    return 0;
}
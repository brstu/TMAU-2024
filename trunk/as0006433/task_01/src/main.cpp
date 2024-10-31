#include <iostream>
#include <cmath>
#include <vector>

const double a = 0.5;
const double b = 0.3;
const double c = 0.1;
const double d = 0.05;

const double Y0 = 20.0;
const double C = 1.0;

const int simulation_steps = 50;
const double initial_temperature = 22.0;
const double initial_input_warm = 5.0;

void simulateLinearModel(double y0, double u0) {
    std::vector<double> temperatures = {y0};
    double y = y0;

    for (int t = 1; t <= simulation_steps; ++t) {
        double u = u0;
        y = a * y + b * u;
        temperatures.push_back(y);
    }

    std::cout << "Linear Model Temperature Simulation:" << std::endl;
    for (int t = 0; t <= simulation_steps; ++t) {
        std::cout << "Step " << t << ": Temperature = " << temperatures[t] << std::endl;
    }
}

void simulateNonlinearModel(double y0, double u0) {
    std::vector<double> temperatures = {y0};
    double y_prev = y0;
    double y = y0;

    for (int t = 1; t <= simulation_steps; ++t) {
        double u = u0;
        y = a * y - b * std::pow(y_prev, 2) + c * u + d * std::sin(u);
        temperatures.push_back(y);
        y_prev = y;
    }

    std::cout << "Nonlinear Model Temperature Simulation:" << std::endl;
    for (int t = 0; t <= simulation_steps; ++t) {
        std::cout << "Step " << t << ": Temperature = " << temperatures[t] << std::endl;
    }
}

int main() {
    double initial_temperature = 22.0;
    double initial_input_warm = 5.0;

    simulateLinearModel(initial_temperature, initial_input_warm);
    std::cout << std::endl;
    simulateNonlinearModel(initial_temperature, initial_input_warm);

    return 0;
}

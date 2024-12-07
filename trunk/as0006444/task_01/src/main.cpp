#include <iostream>
#include <cmath>

const double a = 0.8;
const double b = 0.02;
const double c = 0.1;
const double d = 0.05;
const int time_steps = 100;

void linear_model(double y0, double u[], double y[]) {
    for (int tau = 0; tau < time_steps - 1; ++tau) {
        y[tau + 1] = a * y[tau] + b * u[tau];
    }
}

void nonlinear_model(double y0, double u[], double y[]) {
    for (int tau = 1; tau < time_steps - 1; ++tau) {
        y[tau + 1] = a * y[tau] - b * y[tau - 1] * y[tau - 1] + c * u[tau] + d * sin(u[tau - 1]);
    }
}

int main() {
    double u[time_steps] = { };
    double y_linear[time_steps] = { 0 };
    double y_nonlinear[time_steps] = { 0 };

    double initial_temp = 20.0;
    y_linear[0] = initial_temp;
    y_nonlinear[0] = initial_temp;

    linear_model(initial_temp, u, y_linear);
    nonlinear_model(initial_temp, u, y_nonlinear);

    std::cout << "Time\tLinear Model\tNonlinear Model\n";
    for (int tau = 0; tau < time_steps; ++tau) {
        std::cout << tau << "\t" << y_linear[tau] << "\t\t" << y_nonlinear[tau] << "\n";
    }

    return 0;
}
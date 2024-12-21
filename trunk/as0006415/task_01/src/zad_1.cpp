#include <iostream>
#include <cmath>

// Constants
double C = 1.0, RC = 2.0;
double a = 0.5, b = 0.2, c = 0.1, d = 0.05;

// Linear model
double linearModel(double y_t, double u_t) {
    return a * y_t + b * u_t;
}

// Nonlinear model
double nonlinearModel(double y_t, double u_t) {
    return a * y_t - b * y_t * y_t - 1 + c * u_t + d * std::sin(u_t - 1);
}

int main() {
    double y_0 = 20.0, y_t = y_0;
    double u_t = 10.0;

    for (int t = 1; t <= 10; t++) {
        // Linear model
        double y_t_plus_1 = linearModel(y_t, u_t);
        std::cout << "Time step " << t << ", Linear model: y(" << t << ") = " << y_t_plus_1 << std::endl;

        // Nonlinear model
        y_t_plus_1 = nonlinearModel(y_t, u_t);
        std::cout << "Time step " << t << ", Nonlinear model: y(" << t << ") = " << y_t_plus_1 << std::endl;

        y_t = y_t_plus_1;
        u_t += 1.0; // Increase the input temperature
    }

    return 0;
}
#include "models.h"

LinearModel::LinearModel(double a, double b, double current_temperature, double warm)
    : A(a), B(b), current_temperature(current_temperature), warm(warm) {}

void LinearModel::calculate_and_print(const int& time) {
    std::cout.setf(std::ios::left);
    std::cout << std::setw(10) << "TIME";
    std::cout << std::setw(30) << "LINEAR MODEL" << std::endl;
    std::cout << std::setfill('=') << std::setw(25) << "" << std::setfill(' ') << std::endl;
    double temp = current_temperature;
    for (int i = 1; i <= time; ++i) {
        std::cout << std::setw(10) << i;
        temp = A * temp + B * warm;
        std::cout << std::setw(30) << temp << std::endl;
    }
}

NonLinearModel::NonLinearModel(double A, double B, double C, double D, double current_temperature, double warm)
    : A(A), B(B), C(C), D(D), current_temperature(current_temperature), warm(warm) {}

void NonLinearModel::calculate_and_print(const int& time) {
    std::cout.setf(std::ios::left);
    std::cout << std::setw(10) << "TIME";
    std::cout << std::setw(30) << "NONLINEAR MODEL" << std::endl;
    std::cout << std::setfill('=') << std::setw(25) << "" << std::setfill(' ') << std::endl;
    double curr_temp = current_temperature;
    double previous_temperature = 0.0;
    double buffer = 0.0;
    for (int i = 1; i <= time; ++i) {
        std::cout << std::setw(10) << i;
        buffer = A * curr_temp - B * pow(previous_temperature, 2) + C * warm + D * sin(warm);
        previous_temperature = curr_temp;
        curr_temp = buffer;
        std::cout << std::setw(30) << curr_temp << std::endl;
    }
}

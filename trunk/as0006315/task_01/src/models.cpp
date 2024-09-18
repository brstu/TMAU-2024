#include "models.h"

void ModelingObject::print(const std::map<int, double> &temps, const std::string &name) {
    std::cout.setf(std::ios::left);
    std::cout << std::setw(10) << "TIME";
    std::cout << std::setw(30) << name << std::endl;
    std::cout << std::setfill('=') << std::setw(25) << "" << std::setfill(' ') << std::endl;
    for (auto it = temps.begin(); it != temps.end(); ++it) {
        std::cout << std::setw(10) << it->first;
        std::cout << std::setw(30) << it->second << std::endl;
    }
}

LinearModel::LinearModel(double a, double b, double current_temperature, double warm) : A(a), B(b), current_temperature(current_temperature), warm(warm) {}

void LinearModel::calculate(const int& time) {
    double temp = current_temperature;
    for (int i = 1; i <= time; ++i) {
        temp = A * temp + B * warm;
        temps[i] = temp;
    }
}

void LinearModel::print() {
    ModelingObject::print(this->temps, "LINEAR MODEL");
}

NonLinearModel::NonLinearModel(double A, double B, double C, double D, double current_temperature, double warm) : A(A), B(B), C(C), D(D), current_temperature(current_temperature), warm(warm) {}

void NonLinearModel::calculate(const int& time) {
    double curr_temp = current_temperature;
    double previous_temperature = 0.0;
    double buffer = 0.0;
    for (int i = 1; i <= time; ++i) {
        buffer = A * curr_temp - B * pow(previous_temperature, 2) + C * warm + D * sin(warm);
        previous_temperature = curr_temp;
        curr_temp = buffer;
        temps[i] = curr_temp;
    }
}

void NonLinearModel::print() {
    ModelingObject::print(this->temps, "NONLINEAR MODEL");
}

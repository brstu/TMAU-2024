/**
 * @file models.cpp
 *
 * @brief The file contains the implementation of linear and nonlinear models.
 *
 * @author Loginov Gleb
 *
 * @version 1.0.0
 *
 * @date 21-09-2024
 */

#include "models.h"

/**
 * @brief The function prints the temperatures calculated by one of the models.
 *
 * @param temps The map of temperatures.
 * @param name The name of the model.
 */
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

/**
 * @brief The function gets the temperatures calculated by one of the models.
 *
 * @param temps The map of temperatures.
 *
 * @return The vector of temperatures.
 */
std::vector<double> ModelingObject::getTemp(const std::map<int, double> &temps) {
    std::vector<double> temp;
    for (auto it = temps.begin(); it != temps.end(); ++it) {
        temp.push_back(it->second);
    }
    return temp;
}

/**
 * @brief The constructor of the LinearModel class.
 *
 * @param a The coefficient a in the linear model.
 * @param b The coefficient b in the linear model.
 * @param current_temperature The current temperature.
 * @param warm The temperature of the warm.
 */
LinearModel::LinearModel(double a, double b, double current_temperature, double warm) : A(a), B(b), current_temperature(current_temperature), warm(warm) {}

/**
 * @brief The function calculates the temperatures with the linear model.
 *
 * @param time The time.
 */
void LinearModel::calculate(const int& time) {
    double temp = current_temperature;
    for (int i = 1; i <= time; ++i) {
        temp = A * temp + B * warm;
        temps[i] = temp;
    }
}

/**
 * @brief The function prints the temperatures calculated by the linear model.
 */
void LinearModel::print() {
    ModelingObject::print(this->temps, "LINEAR MODEL");
}

/**
 * @brief The function gets the temperatures calculated by the linear model.
 *
 * @return The vector of temperatures.
 */
std::vector<double> LinearModel::getTemp() {
    return ModelingObject::getTemp(this->temps);
}

/**
 * @brief The constructor of the NonLinearModel class.
 *
 * @param A The coefficient A in the nonlinear model.
 * @param B The coefficient B in the nonlinear model.
 * @param C The coefficient C in the nonlinear model.
 * @param D The coefficient D in the nonlinear model.
 * @param current_temperature The current temperature.
 * @param warm The temperature of the warm.
 */
NonLinearModel::NonLinearModel(double A, double B, double C, double D, double current_temperature, double warm) : A(A), B(B), C(C), D(D), current_temperature(current_temperature), warm(warm) {}

/**
 * @brief The function calculates the temperatures with the nonlinear model.
 *
 * @param time The time.
 */
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

/**
 * @brief The function prints the temperatures calculated by the nonlinear model.
 */
void NonLinearModel::print() {
    ModelingObject::print(this->temps, "NONLINEAR MODEL");
}

/**
 * @brief The function gets the temperatures calculated by the nonlinear model.
 *
 * @return The vector of temperatures.
 */
std::vector<double> NonLinearModel::getTemp() {
    return ModelingObject::getTemp(this->temps);
}


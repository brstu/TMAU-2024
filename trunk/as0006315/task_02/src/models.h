/**
 * @file models.h
 *
 * @brief The header file with the declaration of the base class ModelingObject
 * and derived classes LinearModel and NonLinearModel.
 *
 * @author Loginov Gleb
 *
 * @version 1.0.0
 *
 * @date 21-09-2024
 */

#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>

/**
 * @brief The base class for the models.
 *
 * The class contains the virtual method calculate(),
 * the method print() and the method getTemp().
 */
class ModelingObject {
public:
    /**
     * @brief The virtual method to calculate the temperatures.
     *
     * @param time The time.
     */
    virtual void calculate(const int& time) = 0;

    /**
     * @brief The method to output the temperatures.
     *
     * @param temps The temperatures.
     * @param name The name of the model.
     */
    void print(const std::map<int, double>& temps, const std::string& name);

    /**
     * @brief The method to get the temperatures.
     *
     * @param temps The temperatures.
     * @return The temperatures.
     */
    std::vector<double> getTemp(const std::map<int, double>& temps);
};

/**
 * @brief The class for the linear model.
 *
 * The class contains the constructor, the method calculate(),
 * the method print() and the method getTemp().
 */
class LinearModel : public ModelingObject {
private:
    double A;
    double B;
    double current_temperature;
    double warm;
    std::map<int, double> temps;

public:
    /**
     * @brief The constructor.
     *
     * @param a The coefficient A.
     * @param b The coefficient B.
     * @param current_temperature The current temperature.
     * @param warm The warm temperature.
     */
    LinearModel(double a, double b, double current_temperature, double warm);

    /**
     * @brief The method to calculate the temperatures.
     *
     * @param time The time.
     */
    void calculate(const int& time);

    /**
     * @brief The method to output the temperatures.
     */
    void print();

    /**
     * @brief The method to get the temperatures.
     *
     * @return The temperatures.
     */
    std::vector<double> getTemp();
};

/**
 * @brief The class for the nonlinear model.
 *
 * The class contains the constructor, the method calculate(),
 * the method print() and the method getTemp().
 */
class NonLinearModel : public ModelingObject {
private:
    double A;
    double B;
    double C;
    double D;
    double current_temperature;
    double previous_temperature;
    double warm;
    std::map<int, double> temps;

public:
    /**
     * @brief The constructor.
     *
     * @param A The coefficient A.
     * @param B The coefficient B.
     * @param C The coefficient C.
     * @param D The coefficient D.
     * @param current_temperature The current temperature.
     * @param warm The warm temperature.
     */
    NonLinearModel(double A, double B, double C, double D, double current_temperature, double warm);

    /**
     * @brief The method to calculate the temperatures.
     *
     * @param time The time.
     */
    void calculate(const int& time);

    /**
     * @brief The method to output the temperatures.
     */
    void print();

    /**
     * @brief The method to get the temperatures.
     *
     * @return The temperatures.
     */
    std::vector<double> getTemp();
};

#endif  // MODELS_H


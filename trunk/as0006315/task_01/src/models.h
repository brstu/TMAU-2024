#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

class ModelingObject {
public:
    virtual void calculate_and_print(const int& time) = 0;
};

class LinearModel : public ModelingObject {
private:
    double A;
    double B;
    double current_temperature;
    double warm;

public:
    LinearModel(double a, double b, double current_temperature, double warm);
    void calculate_and_print(const int& time);
};

class NonLinearModel : public ModelingObject {
private:
    double A;
    double B;
    double C;
    double D;
    double current_temperature;
    double previous_temperature;
    double warm;

public:
    NonLinearModel(double A, double B, double C, double D, double current_temperature, double warm);
    void calculate_and_print(const int& time);
};

#endif  // MODELS_H
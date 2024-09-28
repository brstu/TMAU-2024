#include <iostream>
#include <cmath>

// Interface for different models
class TemperatureModel {
public:
    virtual ~TemperatureModel() = default;
    virtual double calculate(double currentTemp, double heatInput) = 0;
};

// Linear temperature control model
class SimpleLinearModel : public TemperatureModel {
private:
    double coeff1;
    double coeff2;
public:
    SimpleLinearModel(double coeff1, double coeff2) : coeff1(coeff1), coeff2(coeff2) {}

    ~SimpleLinearModel() override = default;

    // Calculate temperature based on a linear equation
    double calculate(double currentTemp, double heatInput) override {
        return coeff1 * currentTemp + coeff2 * heatInput;
    }
};

// Nonlinear temperature control model
class ComplexNonlinearModel : public TemperatureModel {
private:
    double coeff1;
    double coeff2;
    double coeff3;
    double coeff4;
    double previousTemp = 0;
    double previousHeat = 0;
public:
    ComplexNonlinearModel(double coeff1, double coeff2, double coeff3, double coeff4)
        : coeff1(coeff1), coeff2(coeff2), coeff3(coeff3), coeff4(coeff4) {}

    ~ComplexNonlinearModel() override = default;

    // Calculate temperature based on a nonlinear equation
    double calculate(double currentTemp, double heatInput) override {
        double result = coeff1 * currentTemp - coeff2 * pow(previousTemp, 2) + coeff3 * heatInput + coeff4 * sin(previousHeat);
        previousTemp = currentTemp;
        previousHeat = heatInput;
        return result;
    }
};

// Function to simulate the temperature modeling process
void runSimulation(TemperatureModel& model, double initialTemp, int steps) {
    double heatInput;
    for (int step = 1; step <= steps; ++step) {
        std::cout << "Enter heat flow value (Uw): "; std::cin >> heatInput;
        initialTemp = model.calculate(initialTemp, heatInput);
        std::cout << "\tStep " << step << "\tTemperature: " << initialTemp << std::endl;
    }
}

int main() {
    double initialTemp;
    double coeff1, coeff2, coeff3, coeff4;
    int numSteps;

    // Input parameters for the linear model
    std::cout << "Enter parameters for the linear model" << std::endl;
    std::cout << "Parameter a: "; std::cin >> coeff1;
    std::cout << "Parameter b: "; std::cin >> coeff2;

    SimpleLinearModel linearModel(coeff1, coeff2);

    // Input parameters for the nonlinear model
    std::cout << "Enter parameters for the nonlinear model" << std::endl;
    std::cout << "Parameter a: "; std::cin >> coeff1;
    std::cout << "Parameter b: "; std::cin >> coeff2;
    std::cout << "Parameter c: "; std::cin >> coeff3;
    std::cout << "Parameter d: "; std::cin >> coeff4;

    ComplexNonlinearModel nonlinearModel(coeff1, coeff2, coeff3, coeff4);

    std::cout << "Enter initial temperature: "; std::cin >> initialTemp;

    // Simulation for the linear model
    std::cout << "Enter the number of simulation steps for the linear model: ";
    std::cin >> numSteps;
    std::cout << "\n--- Simulation for the linear model ---" << std::endl;
    runSimulation(linearModel, initialTemp, numSteps);

    std::cout << std::endl;

    // Simulation for the nonlinear model
    std::cout << "Enter the number of simulation steps for the nonlinear model: ";
    std::cin >> numSteps;
    std::cout << "\n--- Simulation for the nonlinear model ---" << std::endl;
    runSimulation(nonlinearModel, initialTemp, numSteps);

    return 0;
}

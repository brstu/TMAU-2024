#include <iostream>
#include <cmath>

class TemperatureModel {
public:
    virtual double calculateTemperature(double currentTemperature, double heatInput) = 0;
    virtual ~TemperatureModel() = default;
};

class LinearTemperatureModel : public TemperatureModel {
private:
    double coefficientA;
    double coefficientB;
public:
    LinearTemperatureModel(double a, double b) : coefficientA(a), coefficientB(b) {}

    double calculateTemperature(double currentTemperature, double heatInput) override {
        return coefficientA * currentTemperature + coefficientB * heatInput;
    }

    ~LinearTemperatureModel() override = default;
};

class NonlinearTemperatureModel : public TemperatureModel {
private:
    double coeff1, coeff2, coeff3, coeff4;
    double previousTemperature = 0;
    double previousHeatInput = 0;
public:
    NonlinearTemperatureModel(double c1, double c2, double c3, double c4)
        : coeff1(c1), coeff2(c2), coeff3(c3), coeff4(c4) {}

    double calculateTemperature(double currentTemperature, double heatInput) override {
        double result = coeff1 * currentTemperature - coeff2 * pow(previousTemperature, 2) 
                        + coeff3 * heatInput + coeff4 * sin(previousHeatInput);
        previousTemperature = currentTemperature;
        previousHeatInput = heatInput;
        return result;
    }

    ~NonlinearTemperatureModel() override = default;
};

class TemperatureControlSystem {
private:
    const double controlGain = 0.1;
    const double integralTime = 10;
    const double derivativeTime = 80;
    const double sampleTime = 50;
    const double totalSimulationDuration = 30;
    double controlOutput = 0;

    double calculateControlSignal(double error, double previousError1, double previousError2) {
        double term1 = controlGain * (1 + derivativeTime / sampleTime);
        double term2 = -controlGain * (1 + 2 * derivativeTime / sampleTime - sampleTime / integralTime);
        double term3 = controlGain * derivativeTime / sampleTime;
        controlOutput += term1 * error + term2 * previousError1 + term3 * previousError2;
        return controlOutput;
    }

public:
    void runSimulation(double targetTemperature, double initialTemperature, TemperatureModel& model) {
        double previousError1 = 0;
        double previousError2 = 0;
        double currentTemperature = initialTemperature;

        for (int step = 1; step <= totalSimulationDuration; step++) {
            double error = targetTemperature - currentTemperature;
            controlOutput = calculateControlSignal(error, previousError1, previousError2);
            currentTemperature = model.calculateTemperature(currentTemperature, controlOutput);

            std::cout << "Step " << step << " -> Error: " << error 
                      << ", Temperature: " << currentTemperature 
                      << ", Control Output: " << controlOutput << std::endl;

            previousError2 = previousError1;
            previousError1 = error;
        }
        controlOutput = 0;
    }
};

void getInputParameters(double& a, double& b, double& c, double& d, bool isNonlinear) {
    std::cout << "Enter parameter 1: "; std::cin >> a;
    std::cout << "Enter parameter 2: "; std::cin >> b;

    if (isNonlinear) {
        std::cout << "Enter parameter 3: "; std::cin >> c;
        std::cout << "Enter parameter 4: "; std::cin >> d;
    }
}

int main() {
    const double desiredTemperature = 8;
    const double startingTemperature = 3;
    double param1, param2, param3, param4;

    std::cout << "--- Parameters for Linear Model ---" << std::endl;
    getInputParameters(param1, param2, param3, param4, false);
    LinearTemperatureModel linearModel(param1, param2);

    std::cout << "--- Parameters for Nonlinear Model ---" << std::endl;
    getInputParameters(param1, param2, param3, param4, true);
    NonlinearTemperatureModel nonlinearModel(param1, param2, param3, param4);

    TemperatureControlSystem controller;

    std::cout << "\n--- Linear Model Simulation ---" << std::endl;
    controller.runSimulation(desiredTemperature, startingTemperature, linearModel);

    std::cout << "\n--- Nonlinear Model Simulation ---" << std::endl;
    controller.runSimulation(desiredTemperature, startingTemperature, nonlinearModel);

    return 0;
}
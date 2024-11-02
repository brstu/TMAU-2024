#include <iostream>
#include <cmath>

class TempModel {
public:
    virtual double computeTemperature(double currentTemp, double heatInput) = 0;
    virtual ~TempModel() = default;
};

class LinearTempModel : public TempModel {
private:
    double param1;
    double param2;
public:
    LinearTempModel(double param1, double param2) : param1(param1), param2(param2) {}

    double computeTemperature(double currentTemp, double heatInput) override {
        return param1 * currentTemp + param2 * heatInput;
    }

    ~LinearTempModel() override = default;
};

class NonlinearTempModel : public TempModel {
private:
    double param1, param2, param3, param4;
    double prevTemp = 0;
    double prevHeatInput = 0;
public:
    NonlinearTempModel(double param1, double param2, double param3, double param4)
        : param1(param1), param2(param2), param3(param3), param4(param4) {}

    double computeTemperature(double currentTemp, double heatInput) override {
        double result = param1 * currentTemp - param2 * pow(prevTemp, 2) + param3 * heatInput + param4 * sin(prevHeatInput);
        prevTemp = currentTemp;
        prevHeatInput = heatInput;
        return result;
    }

    ~NonlinearTempModel() override = default;
};

class ControlSystem {
private:
    const double gain = 0.1;
    const double integrationTime = 10;
    const double derivativeTime = 80;
    const double samplingTime = 50;
    const double totalSimulationTime = 30;
    double controlSignal = 0;

    double computeControlSignal(double error, double prevError1, double prevError2) {
        double q0 = gain * (1 + derivativeTime / samplingTime);
        double q1 = -gain * (1 + 2 * derivativeTime / samplingTime - samplingTime / integrationTime);
        double q2 = gain * derivativeTime / samplingTime;
        controlSignal += q0 * error + q1 * prevError1 + q2 * prevError2;
        return controlSignal;
    }

public:
    void simulate(double targetTemp, double initialTemp, TempModel& model) {
        double prevError1 = 0;
        double prevError2 = 0;
        double temp = initialTemp;

        for (int i = 1; i <= totalSimulationTime; i++) {
            double error = targetTemp - temp;
            controlSignal = computeControlSignal(error, prevError1, prevError2);
            temp = model.computeTemperature(initialTemp, controlSignal);

            std::cout << "Step " << i << " -> Error: " << error << ", Temp: " << temp << ", Control Signal: " << controlSignal << std::endl;

            prevError2 = prevError1;
            prevError1 = error;
        }
        controlSignal = 0;
    }
};

void readParams(double& p1, double& p2, double& p3, double& p4, bool isNonlinear) {
    std::cout << "Enter parameter 1: "; std::cin >> p1;
    std::cout << "Enter parameter 2: "; std::cin >> p2;

    if (isNonlinear) {
        std::cout << "Enter parameter 3: "; std::cin >> p3;
        std::cout << "Enter parameter 4: "; std::cin >> p4;
    }
}

int main() {
    const double targetTemp = 8;
    const double initialTemp = 3;
    double p1, p2, p3, p4;

    std::cout << "--- Parameters for Linear Model ---" << std::endl;
    readParams(p1, p2, p3, p4, false);
    LinearTempModel linearModel(p1, p2);

    std::cout << "--- Parameters for Nonlinear Model ---" << std::endl;
    readParams(p1, p2, p3, p4, true);
    NonlinearTempModel nonlinearModel(p1, p2, p3, p4);

    ControlSystem controller;

    std::cout << "\n--- Linear Model Simulation ---" << std::endl;
    controller.simulate(targetTemp, initialTemp, linearModel);

    std::cout << "\n--- Nonlinear Model Simulation ---" << std::endl;
    controller.simulate(targetTemp, initialTemp, nonlinearModel);

    return 0;
}

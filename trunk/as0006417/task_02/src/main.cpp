#include <iostream>
#include <cmath>

class TempModel {
public:
    virtual double calcTemp(double currTemp, double heat) = 0;
    virtual ~TempModel() = default;
};

class LinTempModel : public TempModel {
private:
    double a, b;
public:
    LinTempModel(double a, double b) : a(a), b(b) {}

    double calcTemp(double currTemp, double heat) override {
        return a * currTemp + b * heat;
    }

    ~LinTempModel() override = default;
};

class NonlinTempModel : public TempModel {
private:
    double c1, c2, c3, c4;
    double prevTemp = 0;
    double prevHeat = 0;
public:
    NonlinTempModel(double c1, double c2, double c3, double c4)
        : c1(c1), c2(c2), c3(c3), c4(c4) {}

    double calcTemp(double currTemp, double heat) override {
        double result = c1 * currTemp - c2 * pow(prevTemp, 2) 
                        + c3 * heat + c4 * sin(prevHeat);
        prevTemp = currTemp;
        prevHeat = heat;
        return result;
    }

    ~NonlinTempModel() override = default;
};

class ControlSystem {
private:
    const double gain = 0.1;
    const double intTime = 10;
    const double derTime = 80;
    const double sampleTime = 50;
    const double simDuration = 30;
    double outSignal = 0;

    double computeSignal(double err, double prevErr1, double prevErr2) {
        double t1 = gain * (1 + derTime / sampleTime);
        double t2 = -gain * (1 + 2 * derTime / sampleTime - sampleTime / intTime);
        double t3 = gain * derTime / sampleTime;
        outSignal += t1 * err + t2 * prevErr1 + t3 * prevErr2;
        return outSignal;
    }

public:
    void simulate(double targetTemp, double initTemp, TempModel& model) {
        double prevErr1 = 0, prevErr2 = 0;
        double currTemp = initTemp;

        for (int i = 1; i <= simDuration; i++) {
            double error = targetTemp - currTemp;
            outSignal = computeSignal(error, prevErr1, prevErr2);
            currTemp = model.calcTemp(currTemp, outSignal);

            std::cout << "Step " << i << " -> Error: " << error 
                      << ", Temp: " << currTemp 
                      << ", Output: " << outSignal << std::endl;

            prevErr2 = prevErr1;
            prevErr1 = error;
        }
        outSignal = 0;
    }
};

void getParams(double& p1, double& p2, double& p3, double& p4, bool isNonlin) {
    std::cout << "Enter param 1: "; std::cin >> p1;
    std::cout << "Enter param 2: "; std::cin >> p2;

    if (isNonlin) {
        std::cout << "Enter param 3: "; std::cin >> p3;
        std::cout << "Enter param 4: "; std::cin >> p4;
    }
}

int main() {
    const double targetTemp = 8;
    const double startTemp = 3;
    double p1, p2, p3, p4;

    std::cout << "--- Linear Model Params ---" << std::endl;
    getParams(p1, p2, p3, p4, false);
    LinTempModel linearModel(p1, p2);

    std::cout << "--- Nonlinear Model Params ---" << std::endl;
    getParams(p1, p2, p3, p4, true);
    NonlinTempModel nonlinearModel(p1, p2, p3, p4);

    ControlSystem controller;

    std::cout << "\n--- Linear Model Simulation ---" << std::endl;
    controller.simulate(targetTemp, startTemp, linearModel);

    std::cout << "\n--- Nonlinear Model Simulation ---" << std::endl;
    controller.simulate(targetTemp, startTemp, nonlinearModel);

    return 0;
}
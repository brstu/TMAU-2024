#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class ControlModel {
public:
    virtual double computeOutput(double currentOutput, double previousOutput, double input) const = 0;
    virtual ~ControlModel() = default;
};

class LinearModel : public ControlModel {
private:
    double paramA;
    double paramB;

public:
    explicit LinearModel(double paramA, double paramB) : paramA(paramA), paramB(paramB) {}

    double computeOutput(double currentOutput, double previousOutput, double input) const override {
        return paramA * currentOutput + paramB * input;
    }
};

class NonlinearModel : public ControlModel {
private:
    double paramA;
    double paramB;
    double paramC;
    double paramD;

public:
    NonlinearModel(double paramA, double paramB, double paramC, double paramD)
        : paramA(paramA), paramB(paramB), paramC(paramC), paramD(paramD) {}

    double computeOutput(double currentOutput, double previousOutput, double input) const override {
        return paramA * currentOutput - paramB * pow(previousOutput, 2) + paramC * input + paramD * sin(input);
    }
};

class PIDController {
private:
    double kp;
    double ki;
    double kd;
    double lastError = 0.0;
    double accumulatedError = 0.0;

public:
    explicit PIDController(double kp, double ki, double kd)
        : kp(kp), ki(ki), kd(kd) {}

    double computeControlSignal(double currentError) {
        accumulatedError += currentError;
        double derivativeError = currentError - lastError;
        double controlOutput = kp * currentError + ki * accumulatedError + kd * derivativeError;
        lastError = currentError;
        return controlOutput;
    }
};

void displayResults(int iteration, double linearOutput, double nonlinearOutput, double error, double controlSignal) {
    cout << "==============================\n";
    cout << "Итерация: " << iteration << "\n";
    cout << "------------------------------\n";
    cout << "Линейная модель:\n";
    cout << "  Выход: " << linearOutput << "\n";
    cout << "Нелинейная модель:\n";
    cout << "  Выход: " << nonlinearOutput << "\n";
    cout << "Ошибка: " << error << "\n";
    cout << "Управляющий сигнал: " << controlSignal << "\n";
    cout << "==============================\n\n";
}

int main() {
    setlocale(LC_ALL, "Russian");

    LinearModel linearModel(0.8, 0.5);
    NonlinearModel nonlinearModel(0.8, 0.5, 0.2, 0.1);
    PIDController pidController(1.0, 0.5, 0.2);

    double linearOutput = 0.0;
    double nonlinearOutput = 0.0;
    double previousNonlinearOutput = 0.0;
    double inputSignal = 1.0;

    for (int iteration = 0; iteration < 10; iteration++) {
        linearOutput = linearModel.computeOutput(linearOutput, 0, inputSignal);
        nonlinearOutput = nonlinearModel.computeOutput(nonlinearOutput, previousNonlinearOutput, inputSignal);
        previousNonlinearOutput = nonlinearOutput;

        double error = linearOutput - nonlinearOutput;
        double controlSignal = pidController.computeControlSignal(error);

        displayResults(iteration + 1, linearOutput, nonlinearOutput, error, controlSignal);
    }

    return 0;
}
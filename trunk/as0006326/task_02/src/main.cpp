#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MathematicalModel {
public:
    virtual double calculateOutput(double currentOutput, double previousOutput, double inputSignal) const = 0;
    virtual ~MathematicalModel() = default;
};

class LinearModel : public MathematicalModel {
private:
    double linearCoefficientA;
    double linearCoefficientB;

public:
    explicit LinearModel(double coefficientA, double coefficientB) : linearCoefficientA(coefficientA), linearCoefficientB(coefficientB) {}

    double calculateOutput(double currentOutput, double previousOutput, double inputSignal) const override {
        return linearCoefficientA * currentOutput + linearCoefficientB * inputSignal;
    }
};

class NonlinearModel : public MathematicalModel {
private:
    double nonlinearCoefficientA;
    double nonlinearCoefficientB;
    double nonlinearCoefficientC;
    double nonlinearCoefficientD;

public:
    NonlinearModel(double coefficientA, double coefficientB, double coefficientC, double coefficientD)
        : nonlinearCoefficientA(coefficientA), nonlinearCoefficientB(coefficientB), nonlinearCoefficientC(coefficientC), nonlinearCoefficientD(coefficientD) {}

    double calculateOutput(double currentOutput, double previousOutput, double inputSignal) const override {
        return nonlinearCoefficientA * currentOutput - nonlinearCoefficientB * pow(previousOutput, 2) + nonlinearCoefficientC * inputSignal + nonlinearCoefficientD * sin(inputSignal);
    }
};

class PIDController {
private:
    double proportionalGain;
    double integralGain;
    double derivativeGain;
    double previousError = 0.0;
    double accumulatedError = 0.0;

public:
    explicit PIDController(double gainP, double gainI, double gainD)
        : proportionalGain(gainP), integralGain(gainI), derivativeGain(gainD) {}

    double computeControlSignal(double currentError) {
        accumulatedError += currentError;
        double errorChange = currentError - previousError;
        double controlSignal = proportionalGain * currentError + integralGain * accumulatedError + derivativeGain * errorChange;
        previousError = currentError;
        return controlSignal;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    double linearCoefficientA = 0.8;
    double linearCoefficientB = 0.5;

    double nonlinearCoefficientA = 0.8;
    double nonlinearCoefficientB = 0.5;
    double nonlinearCoefficientC = 0.2;
    double nonlinearCoefficientD = 0.1;

    double linearModelOutput = 0.0;
    double nonlinearModelOutput = 0.0;
    double previousNonlinearOutput = 0.0;

    double inputSignal = 1.0;

    LinearModel linearModel(linearCoefficientA, linearCoefficientB);
    NonlinearModel nonlinearModel(nonlinearCoefficientA, nonlinearCoefficientB, nonlinearCoefficientC, nonlinearCoefficientD);
    PIDController pidController(1.0, 0.5, 0.2);

    vector<double> linearOutputs;
    vector<double> nonlinearOutputs;
    vector<double> errorValues;
    vector<double> controlSignals;

    for (int iteration = 1; iteration <= 10; iteration++) {
        linearModelOutput = linearModel.calculateOutput(linearModelOutput, 0, inputSignal);
        nonlinearModelOutput = nonlinearModel.calculateOutput(nonlinearModelOutput, previousNonlinearOutput, inputSignal);
        previousNonlinearOutput = nonlinearModelOutput;

        double outputError = linearModelOutput - nonlinearModelOutput;
        double controlSignal = pidController.computeControlSignal(outputError);

        linearOutputs.push_back(linearModelOutput);
        nonlinearOutputs.push_back(nonlinearModelOutput);
        errorValues.push_back(outputError);
        controlSignals.push_back(controlSignal);
    }

for (int iteration = 0; iteration < 10; iteration++) {
        cout << "Итерация " << iteration + 1 << ":\n";
        cout << "Выход линейной модели: " << linearOutputs[iteration] << '\n';
        cout << "Выход нелинейной модели: " << nonlinearOutputs[iteration] << '\n';
        cout << "Ошибка: " << errorValues[iteration] << '\n';
        cout << "Управляющий сигнал: " << controlSignals[iteration] << '\n';
        cout << '\n';
    }

    return 0;
}
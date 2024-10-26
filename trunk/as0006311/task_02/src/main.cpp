#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MathematicalModel {
public:
    virtual double calculateOutput(double current, double previous, double input) const = 0;
    virtual ~MathematicalModel() = default;
};

class LinearModel : public MathematicalModel {
private:
    double a;
    double b;

public:
    explicit LinearModel(double a, double b) : a(a), b(b) {}

    double calculateOutput(double current, double previous, double input) const override {
        return a * current + b * input;
    }
};

class NonLinearModel : public MathematicalModel {
private:
    double a;
    double b;
    double c;
    double d;

public:
    NonLinearModel(double a, double b, double c, double d)
        : a(a), b(b), c(c), d(d) {}

    double calculateOutput(double current, double previous, double input) const override {
        return a * current - b * pow(previous, 2) + c * input + d * sin(input);
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

    double compute(double error) {
        accumulatedError += error;
        double deltaError = error - lastError;
        double output = kp * error + ki * accumulatedError + kd * deltaError;
        lastError = error;
        return output;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    double linearA = 0.8;
    double linearB = 0.5;

    double nonLinearA = 0.8;
    double nonLinearB = 0.5;
    double nonLinearC = 0.2;
    double nonLinearD = 0.1;

    double linearOutput = 0.0;
    double nonLinearOutput = 0.0;
    double lastNonLinearOutput = 0.0;

    double inputValue = 1.0;

    LinearModel linearModel(linearA, linearB);
    NonLinearModel nonLinearModel(nonLinearA, nonLinearB, nonLinearC, nonLinearD);
    PIDController pidController(1.0, 0.5, 0.2);

    vector<double> linearOutputs;
    vector<double> nonLinearOutputs;
    vector<double> errors;
    vector<double> controlOutputs;

    for (int i = 1; i <= 10; i++) {
        linearOutput = linearModel.calculateOutput(linearOutput, 0, inputValue);
        nonLinearOutput = nonLinearModel.calculateOutput(nonLinearOutput, lastNonLinearOutput, inputValue);
        lastNonLinearOutput = nonLinearOutput;

        double error = linearOutput - nonLinearOutput;
        double controlOutput = pidController.compute(error);

        linearOutputs.push_back(linearOutput);
        nonLinearOutputs.push_back(nonLinearOutput);
        errors.push_back(error);
        controlOutputs.push_back(controlOutput);
    }

    // Вывод результатов для каждой итерации
    for (int i = 0; i < 10; i++) {
        cout << "Итерация " << i + 1 << ":\n";
        cout << "Выход линейной модели: " << linearOutputs[i] << '\n';
        cout << "Выход нелинейной модели: " << nonLinearOutputs[i] << '\n';
        cout << "Ошибка: " << errors[i] << '\n';
        cout << "Управляющий сигнал: " << controlOutputs[i] << '\n';
        cout << '\n';
    }

    return 0;
}
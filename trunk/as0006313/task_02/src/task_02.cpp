#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class Model {
public:
    virtual double compute(double current, double previous, double inputValue) const = 0;
    virtual ~Model() = default;
};

class LinearModel : public Model {
private:
    double factorX;
    double factorY;

public:
    explicit LinearModel(double factorX, double factorY) : factorX(factorX), factorY(factorY) {}

    double compute(double current, double previous, double inputValue) const override {
        return factorX * current + factorY * inputValue;
    }
};

class NonlinearModel : public Model {
private:
    double factorX;
    double factorY;
    double factorZ;
    double factorW;

public:
    NonlinearModel(double factorX, double factorY, double factorZ, double factorW)
        : factorX(factorX), factorY(factorY), factorZ(factorZ), factorW(factorW) {}

    double compute(double current, double previous, double inputValue) const override {
        return factorX * current - factorY * pow(previous, 2) + factorZ * inputValue + factorW * sin(inputValue);
    }
};

class Regulator {
private:
    double proportionalGain;
    double integralGain;
    double derivativeGain;
    double lastError = 0.0;
    double sumError = 0.0;
    double lastSignal = 0.0;

public:
    explicit Regulator(double proportionalGain, double integralGain, double derivativeGain)
        : proportionalGain(proportionalGain), integralGain(integralGain), derivativeGain(derivativeGain) {}

    double compute(double error) {
        sumError += error;
        double changeRate = error - lastError;
        double signal = proportionalGain * error + integralGain * sumError + derivativeGain * changeRate;
        lastError = error;
        lastSignal = signal;
        return signal;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    double factorX_linear = 0.7;
    double factorY_linear = 0.4;

    double factorX_nonlinear = 0.7;
    double factorY_nonlinear = 0.4;
    double factorZ_nonlinear = 0.3;
    double factorW_nonlinear = 0.15;

    double current_linear = 0.0;
    double current_nonlinear = 0.0;
    double last_nonlinear = 0.0;

    double inputValue = 1.2;

    LinearModel linearModel(factorX_linear, factorY_linear);
    NonlinearModel nonlinearModel(factorX_nonlinear, factorY_nonlinear, factorZ_nonlinear, factorW_nonlinear);
    Regulator regulator(1.2, 0.6, 0.3);

    vector<double> linear_outputs;
    vector<double> nonlinear_outputs;
    vector<double> errors;
    vector<double> control_signals;

    for (int time = 1; time <= 10; time++) {
        current_linear = linearModel.compute(current_linear, 0, inputValue);
        current_nonlinear = nonlinearModel.compute(current_nonlinear, last_nonlinear, inputValue);
        last_nonlinear = current_nonlinear;

        double error = current_linear - current_nonlinear;
        double controlSignal = regulator.compute(error);

        linear_outputs.push_back(current_linear);
        nonlinear_outputs.push_back(current_nonlinear);
        errors.push_back(error);
        control_signals.push_back(controlSignal);
    }
	
    ofstream outFile("results.txt");
    if (outFile.is_open()) {
        for (int time = 0; time < 10; time++) {
            cout << "Итерация " << time + 1 << ":\n";
            cout << "Выход линейной модели: " << linear_outputs[time] << '\n';
            cout << "Выход нелинейной модели: " << nonlinear_outputs[time] << '\n';
            cout << "Ошибка: " << errors[time] << '\n';
            cout << "Управляющий сигнал: " << control_signals[time] << '\n';
            cout << '\n';

            outFile << "Итерация " << time + 1 << ":\n";
            outFile << "Выход линейной модели: " << linear_outputs[time] << '\n';
            outFile << "Выход нелинейной модели: " << nonlinear_outputs[time] << '\n';
            outFile << "Ошибка: " << errors[time] << '\n';
            outFile << "Управляющий сигнал: " << control_signals[time] << '\n';
            outFile << '\n';
        }
        outFile.close();
    } else {
        cout << "Не удалось открыть файл для записи.\n";
    }

    return 0;
}

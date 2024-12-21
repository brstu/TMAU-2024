#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Базовый класс для математических моделей
class MathModel {
public:
    virtual double calcOutput(double currentOutput, double previousOutput, double input) = 0; // Чисто виртуальная функция
};

// Линейная модель
class LinModel : public MathModel {
public:
    double a, b; // Коэффициенты модели

    LinModel(double a_, double b_) {
        a = a_;
        b = b_;
    }

    double calcOutput(double currentOutput, double previousOutput, double input) override {
        return a * currentOutput + b * input; // Формула для расчёта линейной модели
    }
};

// Нелинейная модель
class NonlinModel : public MathModel {
public:
    double a, b, c, d; // Коэффициенты модели

    NonlinModel(double a_, double b_, double c_, double d_) {
        a = a_;
        b = b_;
        c = c_;
        d = d_;
    }

    double calcOutput(double currentOutput, double previousOutput, double input) override {
        return a * currentOutput - b * pow(previousOutput, 2) + c * input + d * sin(input); // Формула для расчёта нелинейной модели
    }
};

// PID-регулятор
class PIDRegulator {
public:
    double kp, ki, kd; // Коэффициенты PID-регулятора
    double prevError = 0.0; // Предыдущая ошибка
    double integral = 0.0; // Интегральная ошибка

    PIDRegulator(double kp_, double ki_, double kd_) {
        kp = kp_;
        ki = ki_;
        kd = kd_;
    }

    double calcOutput(double error) {
        integral += error; // Накопление ошибки
        double derivative = error - prevError; // Разница ошибки
        prevError = error;
        return kp * error + ki * integral + kd * derivative; // Расчёт управляющего сигнала
    }
};

int main() {
    // Коэффициенты для моделей
    double aLinear, bLinear;
    double aNonlinear, bNonlinear, cNonlinear, dNonlinear;

    cout << "Введите коэффициенты для линейной модели (A B): ";
    cin >> aLinear >> bLinear;

    cout << "Введите коэффициенты для нелинейной модели (A B C D): ";
    cin >> aNonlinear >> bNonlinear >> cNonlinear >> dNonlinear;

    // Инициализация моделей
    LinModel linModel(aLinear, bLinear);
    NonlinModel nonlinModel(aNonlinear, bNonlinear, cNonlinear, dNonlinear);
    PIDRegulator pid(1.0, 0.5, 0.2);

    // Переменные для расчётов
    double currentOutputLinear = 0.0;
    double currentOutputNonlinear = 0.0;
    double prevOutputNonlinear = 0.0;
    double input = 1.0; // Входное значение

    for (int i = 1; i <= 10; i++) {
        // Вычисления моделей
        currentOutputLinear = linModel.calcOutput(currentOutputLinear, 0, input);
        currentOutputNonlinear = nonlinModel.calcOutput(currentOutputNonlinear, prevOutputNonlinear, input);
        prevOutputNonlinear = currentOutputNonlinear;

        // Расчёт ошибки и управляющего сигнала
        double error = currentOutputLinear - currentOutputNonlinear;
        double controlSignal = pid.calcOutput(error);

        // Вывод результата
        cout << "Итерация " << i << ":\n";
        cout << "Выход линейной модели: " << currentOutputLinear << '\n';
        cout << "Выход нелинейной модели: " << currentOutputNonlinear << '\n';
        cout << "Ошибка: " << error << '\n';
        cout << "Управляющий сигнал: " << controlSignal << '\n';
        cout << "---------------------\n";
    }

    return 0;
}
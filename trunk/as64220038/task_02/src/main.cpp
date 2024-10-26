/**
 * @file main.cpp
 * @brief Программа моделирования работы линейной и нелинейной математических моделей с регулятором.
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

/**
 * @class MathematicModel
 * @brief Абстрактный класс для математической модели.
 */
class MathematicModel {
public:
    /**
     * @brief Вычисление выходного значения модели.
     * 
     * @param currentVal Текущее значение.
     * @param prevVal Предыдущее значение.
     * @param inputVal Входное значение.
     * @return Выходное значение модели.
     */
    virtual double calculateOutput(double currentVal, double prevVal, double inputVal) const = 0;

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~MathematicModel() = default;
};

/**
 * @class LinearModel
 * @brief Класс для линейной математической модели.
 */
class LinearModel : public MathematicModel {
    double a, b; /**< Коэффициенты линейной модели. */

public:
    /**
     * @brief Конструктор класса LinearModel.
     * 
     * @param a Коэффициент для текущего значения.
     * @param b Коэффициент для входного значения.
     */
    LinearModel(double a, double b) : a(a), b(b) {}

    /**
     * @brief Вычисление выходного значения линейной модели.
     * 
     * @param currentVal Текущее значение.
     * @param prevVal Не используется в линейной модели.
     * @param inputVal Входное значение.
     * @return Выходное значение линейной модели.
     */
    double calculateOutput(double currentVal, double, double inputVal) const override {
        return a * currentVal + b * inputVal;
    }
};

/**
 * @class NonLinearModel
 * @brief Класс для нелинейной математической модели.
 */
class NonLinearModel : public MathematicModel {
    double a, b, c, d; /**< Коэффициенты нелинейной модели. */

public:
    /**
     * @brief Конструктор класса NonLinearModel.
     * 
     * @param a Коэффициент для текущего значения.
     * @param b Коэффициент для квадрата предыдущего значения.
     * @param c Коэффициент для входного значения.
     * @param d Коэффициент для синуса входного значения.
     */
    NonLinearModel(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

    /**
     * @brief Вычисление выходного значения нелинейной модели.
     * 
     * @param currentVal Текущее значение.
     * @param prevVal Предыдущее значение.
     * @param inputVal Входное значение.
     * @return Выходное значение нелинейной модели.
     */
    double calculateOutput(double currentVal, double prevVal, double inputVal) const override {
        return a * currentVal - b * pow(prevVal, 2) + c * inputVal + d * sin(inputVal);
    }
};

/**
 * @class Regulator
 * @brief Класс регулятора для управления ошибкой.
 */
class Regulator {
    double q0, q1, q3; /**< Коэффициенты регулятора. */
    double previousError = 0.0; /**< Предыдущее значение ошибки. */
    double errorSum = 0.0; /**< Сумма ошибок для интегрального действия. */

public:
    /**
     * @brief Конструктор класса Regulator.
     * 
     * @param q0 Пропорциональный коэффициент.
     * @param q1 Интегральный коэффициент.
     * @param q3 Дифференциальный коэффициент.
     */
    Regulator(double q0, double q1, double q3) : q0(q0), q1(q1), q3(q3) {}

    /**
     * @brief Вычисление управляющего сигнала на основе текущей ошибки.
     * 
     * @param currentError Текущая ошибка.
     * @return Управляющий сигнал.
     */
    double calculateControl(double currentError) {
        errorSum += currentError;
        double errorDerivative = currentError - previousError;
        double controlSignal = q0 * currentError + q1 * errorSum + q3 * errorDerivative;
        previousError = currentError;
        return controlSignal;
    }
};

/**
 * @brief Главная функция программы.
 * 
 * Выполняет моделирование работы линейной и нелинейной моделей с регулятором,
 * записывает результаты в файл.
 * 
 * @return Код завершения программы (0 - успех, 1 - ошибка).
 */
int main() {
    ofstream fout("results.txt");

    // Проверка успешного открытия файла
    if (!fout) {
        cerr << "Failed to open file to write results." << endl;
        return 1;
    }

    LinearModel linearModel(0.8, 0.5); // Линейная модель
    NonLinearModel nonLinearModel(0.8, 0.5, 0.2, 0.1); // Нелинейная модель
    Regulator regulator(1.0, 0.5, 0.2); // Регулятор

    double linearValue = 0.0;
    double nonLinearValue = 0.0, previousNonLinearValue = 0.0;
    double inputValue = 1.0;

    fout << "Linear model: " << endl;

    // Моделирование линейной модели
    for (int i = 0; i < 50; ++i) {
        linearValue = linearModel.calculateOutput(linearValue, 0, inputValue);
        nonLinearValue = nonLinearModel.calculateOutput(nonLinearValue, previousNonLinearValue, inputValue);
        previousNonLinearValue = nonLinearValue;

        double error = linearValue - nonLinearValue;
        double controlSignal = regulator.calculateControl(error);

        fout << "E=" << error << " Y=" << nonLinearValue << " U=" << controlSignal << endl;
    }

    fout << "Nonlinear model: " << endl;

    // Моделирование нелинейной модели
    for (int i = 0; i < 50; ++i) {
        linearValue = linearModel.calculateOutput(linearValue, 0, inputValue);
        nonLinearValue = nonLinearModel.calculateOutput(nonLinearValue, previousNonLinearValue, inputValue);
        previousNonLinearValue = nonLinearValue;

        double error = linearValue - nonLinearValue;
        double controlSignal = regulator.calculateControl(error);

        fout << "E=" << error << " Y=" << nonLinearValue << " U=" << controlSignal << endl;
    }

    fout.close();

    return 0;
}

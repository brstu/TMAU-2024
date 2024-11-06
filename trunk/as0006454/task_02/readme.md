<p style="text-align: center;">Министерство образования Республики Беларусь</p>
<p style="text-align: center;">Учреждение образования</p>
<p style="text-align: center;">“Брестский Государственный технический университет”</p>
<p style="text-align: center;">Кафедра ИИТ</p>
<div style="margin-bottom: 10em;"></div>
<p style="text-align: center;">Лабораторная работа №2</p>
<p style="text-align: center;">По дисциплине “Теория и методы автоматического управления”</p>
<p style="text-align: center;">Тема: “ПИД-регулятор”</p>
<div style="margin-bottom: 10em;"></div>
<p style="text-align: right;">Выполнил:</p>
<p style="text-align: right;">Студент 3 курса</p>
<p style="text-align: right;">Группы АС-64</p>
<p style="text-align: right;">Хомич В. Г.</p>
<p style="text-align: right;">Проверила:</p>
<p style="text-align: right;">Ситковец Я. С.</p>
<div style="margin-bottom: 10em;"></div>
<p style="text-align: center;">Брест 2024</p>

---

## Task:

In C++, implement a program that simulates the PID controller discussed above. Use the mathematical model obtained in the previous work as the control object. To use OOP, the program must have at least 3 classes (+inheritance).

 Add information about the developed program (class diagram, etc.) to the report using Doxygen (in .md format).

## Example of program output:

```cpp
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * @brief Базовый класс для математической модели.
 */
class MathModel {
public:
    /**
     * @brief Виртуальная функция для вычисления выходного значения модели.
     * 
     * @param current Текущее значение.
     * @param previous Предыдущее значение.
     * @param input Входное значение.
     * @return double Результат вычисления.
     */
    virtual double computeOutput(double current, double previous, double input) const = 0;

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~MathModel() = default;
};

/**
 * @brief Линейная математическая модель.
 */
class SimpleLinearModel : public MathModel {
private:
    double coefficientA; ///< Коэффициент для текущего значения.
    double coefficientB; ///< Коэффициент для входного значения.

public:
    /**
     * @brief Конструктор с параметрами.
     * 
     * @param a Коэффициент для текущего значения.
     * @param b Коэффициент для входного значения.
     */
    explicit SimpleLinearModel(double a, double b) : coefficientA(a), coefficientB(b) {}

    /**
     * @brief Вычисляет выходное значение линейной модели.
     * 
     * @param current Текущее значение.
     * @param previous Предыдущее значение (не используется).
     * @param input Входное значение.
     * @return double Выходное значение.
     */
    double computeOutput(double current, double previous, double input) const override {
        return coefficientA * current + coefficientB * input;
    }
};

/**
 * @brief Нелинейная математическая модель.
 */
class AdvancedNonLinearModel : public MathModel {
private:
    double paramA; ///< Коэффициент для текущего значения.
    double paramB; ///< Коэффициент для квадрата предыдущего значения.
    double paramC; ///< Коэффициент для входного значения.
    double paramD; ///< Коэффициент для синуса входного значения.

public:
    /**
     * @brief Конструктор с параметрами.
     * 
     * @param a Коэффициент для текущего значения.
     * @param b Коэффициент для квадрата предыдущего значения.
     * @param c Коэффициент для входного значения.
     * @param d Коэффициент для синуса входного значения.
     */
    AdvancedNonLinearModel(double a, double b, double c, double d)
        : paramA(a), paramB(b), paramC(c), paramD(d) {}

    /**
     * @brief Вычисляет выходное значение нелинейной модели.
     * 
     * @param current Текущее значение.
     * @param previous Предыдущее значение.
     * @param input Входное значение.
     * @return double Выходное значение.
     */
    double computeOutput(double current, double previous, double input) const override {
        return paramA * current - paramB * pow(previous, 2) + paramC * input + paramD * sin(input);
    }
};

/**
 * @brief Класс ПИД-контроллера.
 */
class PIDControl {
private:
    double gainP; ///< Пропорциональный коэффициент.
    double gainI; ///< Интегральный коэффициент.
    double gainD; ///< Дифференциальный коэффициент.
    double lastErr = 0.0; ///< Предыдущее значение ошибки.
    double totalErr = 0.0; ///< Накопленная ошибка.

public:
    /**
     * @brief Конструктор с параметрами.
     * 
     * @param kp Пропорциональный коэффициент.
     * @param ki Интегральный коэффициент.
     * @param kd Дифференциальный коэффициент.
     */
    explicit PIDControl(double kp, double ki, double kd)
        : gainP(kp), gainI(ki), gainD(kd) {}

    /**
     * @brief Вычисляет управляющий сигнал на основе текущей ошибки.
     * 
     * @param error Текущее значение ошибки.
     * @return double Управляющий сигнал.
     */
    double generateControl(double error) {
        totalErr += error;
        double errorDelta = error - lastErr;
        double output = gainP * error + gainI * totalErr + gainD * errorDelta;
        lastErr = error;
        return output;
    }
};

/**
 * @brief Основная функция.
 * 
 * Выполняет симуляцию работы линейной и нелинейной моделей, а также ПИД-контроллера для управления ошибкой.
 * 
 * @return int Код завершения программы.
 */
int main() {
    setlocale(LC_ALL, "Russian");

    // Параметры для линейной модели
    double linearParamA = 0.8;
    double linearParamB = 0.5;

    // Параметры для нелинейной модели
    double nonLinearParamA = 0.8;
    double nonLinearParamB = 0.5;
    double nonLinearParamC = 0.2;
    double nonLinearParamD = 0.1;

    double linearResult = 0.0;
    double nonLinearResult = 0.0;
    double previousNonLinearResult = 0.0;

    double input = 1.0;

    // Создание объектов моделей и контроллера
    SimpleLinearModel linearModel(linearParamA, linearParamB);
    AdvancedNonLinearModel nonLinearModel(nonLinearParamA, nonLinearParamB, nonLinearParamC, nonLinearParamD);
    PIDControl pidController(1.0, 0.5, 0.2);

    vector<double> linearResults;
    vector<double> nonLinearResults;
    vector<double> errorValues;
    vector<double> controlSignals;

    // Симуляция работы на 10 итераций
    for (int i = 1; i <= 10; i++) {
        linearResult = linearModel.computeOutput(linearResult, 0, input);
        nonLinearResult = nonLinearModel.computeOutput(nonLinearResult, previousNonLinearResult, input);
        previousNonLinearResult = nonLinearResult;

        double error = linearResult - nonLinearResult;
        double controlSignal = pidController.generateControl(error);

        linearResults.push_back(linearResult);
        nonLinearResults.push_back(nonLinearResult);
        errorValues.push_back(error);
        controlSignals.push_back(controlSignal);
    }

    // Вывод результатов для каждой итерации
    for (int i = 0; i < 10; i++) {
        cout << "Итерация " << i + 1 << ":\n";
        cout << "Результат линейной модели: " << linearResults[i] << '\n';
        cout << "Результат нелинейной модели: " << nonLinearResults[i] << '\n';
        cout << "Ошибка: " << errorValues[i] << '\n';
        cout << "Управляющий сигнал: " << controlSignals[i] << '\n';
        cout << '\n';
    }

    return 0;
}


Linear model result: 0.5
Nonlinear model result: 0.284147
Error: 0.215853
Control signal: 0.36695
Iteration 2:

Linear model result: 0.9
Nonlinear model result: 0.471095
Error: 0.428905
Control signal: 0.793894
Iteration 3:

Linear model result: 1.22
Nonlinear model result: 0.550058
Error: 0.669942
Control signal: 1.3755
Iteration 4:

Linear model result: 1.476
Nonlinear model result: 0.572912
Error: 0.903088
Control signal: 2.05861
Iteration 5:

Linear model result: 1.6808
Nonlinear model result: 0.578363
Error: 1.10244
Control signal: 2.80242
Iteration 6:

Linear model result: 1.84464
Nonlinear model result: 0.579586
Error: 1.26505
Control signal: 3.59022
Iteration 7:

Linear model result: 1.97571
Nonlinear model result: 0.579856
Error: 1.39586
Control signal: 4.41258
Iteration 8:

Linear model result: 2.08057
Nonlinear model result: 0.579915
Error: 1.50065
Control signal: 5.26251
Iteration 9:

Linear model result: 2.16446
Nonlinear model result: 0.579928
Error: 1.58453
Control signal: 6.13446
Iteration 10:

Linear model result: 2.23156
Nonlinear model result: 0.579931
Error: 1.65163
Control signal: 7.02403
```
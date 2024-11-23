#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

/**
 * @class Model
 * @brief Абстрактный базовый класс для математической модели.
 */
class Model {
public:
    /**
     * @brief Вычисляет выходное значение модели.
     * @param current Текущее значение.
     * @param previous Предыдущее значение.
     * @param input Входное значение.
     * @return Выходное значение модели.
     */
    virtual double getOutput(double current, double previous, double input) const = 0;

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~Model() = default;
};

/**
 * @class SimpleModel
 * @brief Класс для простой (линейной) модели.
 */
class SimpleModel : public Model {
    double k1, k2; /**< Коэффициенты для линейной модели. */

public:
    /**
     * @brief Конструктор класса SimpleModel.
     * @param k1 Коэффициент для текущего значения.
     * @param k2 Коэффициент для входного значения.
     */
    SimpleModel(double k1, double k2) : k1(k1), k2(k2) {}

    /**
     * @brief Вычисляет выходное значение линейной модели.
     * @param current Текущее значение.
     * @param previous Не используется.
     * @param input Входное значение.
     * @return Выходное значение линейной модели.
     */
    double getOutput(double current, double, double input) const override {
        return k1 * current + k2 * input;
    }
};

/**
 * @class ComplexModel
 * @brief Класс для сложной (нелинейной) модели.
 */
class ComplexModel : public Model {
    double p, q, r, s; /**< Коэффициенты для нелинейной модели. */

public:
    /**
     * @brief Конструктор класса ComplexModel.
     * @param p Коэффициент для текущего значения.
     * @param q Коэффициент для квадрата предыдущего значения.
     * @param r Коэффициент для входного значения.
     * @param s Коэффициент для синуса входного значения.
     */
    ComplexModel(double p, double q, double r, double s) : p(p), q(q), r(r), s(s) {}

    /**
     * @brief Вычисляет выходное значение нелинейной модели.
     * @param current Текущее значение.
     * @param previous Предыдущее значение.
     * @param input Входное значение.
     * @return Выходное значение нелинейной модели.
     */
    double getOutput(double current, double previous, double input) const override {
        return p * current - q * pow(previous, 2) + r * input + s * sin(input);
    }
};

/**
 * @class Controller
 * @brief Класс для регулятора, вычисляющего управляющий сигнал.
 */
class Controller {
    double kp, ki, kd; /**< Коэффициенты регулятора. */
    double lastError = 0.0; /**< Последнее значение ошибки. */
    double accumulatedError = 0.0; /**< Сумма ошибок для интегрального действия. */

public:
    /**
     * @brief Конструктор класса Controller.
     * @param kp Пропорциональный коэффициент.
     * @param ki Интегральный коэффициент.
     * @param kd Дифференциальный коэффициент.
     */
    Controller(double kp, double ki, double kd) : kp(kp), ki(ki), kd(kd) {}

    /**
     * @brief Вычисляет управляющий сигнал на основе текущей ошибки.
     * @param error Текущая ошибка.
     * @return Управляющий сигнал.
     */
    double computeSignal(double error) {
        accumulatedError += error;
        double errorDiff = error - lastError;
        double signal = kp * error + ki * accumulatedError + kd * errorDiff;
        lastError = error;
        return signal;
    }
};

/**
 * @brief Главная функция программы.
 * 
 * Выполняет моделирование работы простой и сложной моделей с регулятором
 * и записывает результаты в файл "simulation.txt".
 * 
 * @return Код завершения программы (0 - успех, 1 - ошибка).
 */
int main() {
    ofstream outputFile("result.txt");

    if (!outputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    SimpleModel simple(0.7, 0.6);
    ComplexModel complex(1.2, 0.4, 0.3, 0.2);
    Controller control(1.3, 0.7, 0.4);

    double simpleVal = 0.0;
    double complexVal = 0.0, previousComplexVal = 0.0;
    double inputVal = 2.5;

    outputFile << "\n\n\n" << endl;
    outputFile << "== Simple Model Simulation ==" << endl;

    for (int i = 0; i < 30; ++i) {
        simpleVal = simple.getOutput(simpleVal, 0, inputVal);
        complexVal = complex.getOutput(complexVal, previousComplexVal, inputVal);
        previousComplexVal = complexVal;

        double error = simpleVal - complexVal;
        double controlSignal = control.computeSignal(error);

        outputFile << "E=" << error << " Y=" << complexVal << " U=" << controlSignal << endl;
    }

    outputFile << "\n\n\n" << endl;
    outputFile << "== Complex Model Simulation ==" << endl;

    for (int i = 0; i < 30; ++i) {
        simpleVal = simple.getOutput(simpleVal, 0, inputVal);
        complexVal = complex.getOutput(complexVal, previousComplexVal, inputVal);
        previousComplexVal = complexVal;

        double error = simpleVal - complexVal;
        double controlSignal = control.computeSignal(error);

        outputFile << "E=" << error << " Y=" << complexVal << " U=" << controlSignal << endl;
    }

    outputFile.close();

    return 0;
}

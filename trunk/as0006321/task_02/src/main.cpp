#include <iostream>
#include <cmath>
#include <vector>

/**
 * \brief Абстрактный класс модели
 *
 * Модель используется для представления других моделей.
 */
class Model {
public:
    virtual double simulate(double prevOutput, double input, double prevInput) = 0;
    virtual ~Model() = default;
};

/**
 * @brief Линейная модель управления
 *
 */
class LinearModel : public Model {
private:
    double a; ///< Параметр a
    double b; ///< Параметр b
public:
    LinearModel(double a, double b) : a(a), b(b) {}

    double simulate(double prevOutput, double input, double) override {
        return a * prevOutput + b * input;
    }
};

/**
 * @brief Нелинейная модель управления
 *
 */
class NonlinearModel : public Model {
private:
    double a; ///< Параметр a
    double b; ///< Параметр b
    double c; ///< Параметр c
    double d; ///< Параметр d
    double prevOutput = 0; ///< Предыдущее значение выхода
    double prevInput = 0; ///< Предыдущее значение входа
public:
    NonlinearModel(double a, double b, double c, double d)
        : a(a), b(b), c(c), d(d) {}

    double simulate(double prevOutput, double input, double prevInput) override {
        double output = a * prevOutput - b * pow(prevOutput, 2) + c * input + d * sin(prevInput);
        this->prevOutput = prevOutput;
        this->prevInput = input;
        return output;
    }
};

/**
 * @brief ПИД-регулятор
 *
 */
class PIDController {
private:
    double Kp; ///< Пропорциональный коэффициент
    double Ki; ///< Интегральный коэффициент
    double Kd; ///< Дифференциальный коэффициент
    double prevError; ///< Предыдущая ошибка
    double integral; ///< Интегральная ошибка

public:
    PIDController(double Kp, double Ki, double Kd)
        : Kp(Kp), Ki(Ki), Kd(Kd), prevError(0), integral(0) {}

    double compute(double setpoint, double measured) {
        double error = setpoint - measured;
        integral += error; // Интегральная составляющая
        double derivative = error - prevError; // Производная
        prevError = error; // Обновляем предыдущую ошибку

        return Kp * error + Ki * integral + Kd * derivative; // ПИД-выход
    }
};

/**
 * @brief Класс для симуляции
 *
 */
class Simulation {
private:
    Model& model; ///< Ссылка на модель
    PIDController& controller;

public:
    Simulation(Model& model, PIDController& controller)
        : model(model), controller(controller) {}

    void run(int timeSteps, double setpoint) {
        double output = 0; // Начальное значение выхода
        for (int t = 0; t < timeSteps; t++) {
            double control = controller.compute(setpoint, output);
            output = model.simulate(output, control, control); // Используем управление для расчета выхода

            std::cout << "Time: " << t << ", Control: " << control << ", Output: " << output << std::endl;
        }
    }
};

void inputParameters(double& a, double& b, double& c, double& d, bool isNonlinear) {
    std::cout << "Input a-parameter: "; std::cin >> a;
    std::cout << "Input b-parameter: "; std::cin >> b;
    
    if (isNonlinear) {
        std::cout << "Input c-parameter: "; std::cin >> c;
        std::cout << "Input d-parameter: "; std::cin >> d;
    }
}

int main() {
    double a, b, c, d;
    double Kp, Ki, Kd;
    int timeSteps;

    std::cout << "--- Please input LinearModel's constant parameters ---" << std::endl;
    inputParameters(a, b, c, d, false);
    LinearModel linearModel(a, b);

    std::cout << "--- Please input NonlinearModel's constant parameters ---" << std::endl;
    inputParameters(a, b, c, d, true);
    NonlinearModel nonlinearModel(a, b, c, d);

    std::cout << "Enter PID parameters Kp, Ki, Kd: ";
    std::cin >> Kp >> Ki >> Kd;
    PIDController pidController(Kp, Ki, Kd);

    std::cout << "Enter number of time steps: ";
    std::cin >> timeSteps;

    std::cout << "\t--- LinearModel ---" << std::endl;
    Simulation linearSimulation(linearModel, pidController);
    linearSimulation.run(timeSteps, 10); // Задаем целевое значение

    std::cout << "\n\t--- NonlinearModel ---" << std::endl;
    Simulation nonlinearSimulation(nonlinearModel, pidController);
    nonlinearSimulation.run(timeSteps, 10); // Задаем целевое значение

    return 0;
}
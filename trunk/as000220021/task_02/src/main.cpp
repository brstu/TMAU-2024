#include <iostream>
#include <vector>
#include "models.h"
#include "PID.h"

using namespace std;

/**
 * @file main.cpp
 *
 * @brief Программа реализует контроллер для системы с двумя моделями:
 * линейной и нелинейной.
 *
 * @author Поплавский Владислав
 *
 * @version 1.0.0
 *
 * @date 21-09-2024
 */

void start();
bool choice_input(int& choice);
LinearModel get_liner_model(const int& T0);
NonLinearModel get_nonlinear_model(const int& T0);
template<typename T> bool input_value(T& value, const string& name);
void output(const vector <vector<double>>& control_signals, const string& name);

/**
 * @brief Главная функция.
 *
 * Главная функция запускает программу, является точкой входа.
 *
 * @return 0, если все в порядке.
 */

int main() {
    /**
     * @brief Массив функций для переключения между ними.
     */
    void (*point[])() = { []() { exit(0); }, start };
    int choice;
    while (true) {
        /**
         * @brief Вывод выбора для пользователя.
         */
        cout << "\n\tВведите выбор (0 - выход, 1 - начать)\n";
        /**
         * @brief Ввод выбора от пользователя.
         */
        if (!choice_input(choice)) {
            /**
             * @brief Если ввод некорректен, выводим сообщение об ошибке.
             */
            cerr << "\n\a\t\t***Некорректное значение ввода***\n\n";
            continue;
        }
        /**
         * @brief Вызываем функцию из массива в зависимости от выбора.
         */
        point[choice]();
    }
    return 0;
}

/**
 * @brief Функция для начала программы.
 *
 * Функция запускает программу, вводит данные для линейной и нелинейной моделей,
 * вычисляет ошибку, рассчитывает управляющий сигнал с помощью PID и выводит результаты.
 */
void start() {
    double w;
    int T0;

    do {
        /**
         * @brief Запрос ввода алгоритма функционирования системы.
         */
        cout << "Введите алгоритм функционирования системы\n";
    } while (!input_value(w, "w(t)"));

    /**
     * @brief Запрос ввода шага.
     */
    cout << "Введите шаг\n";
    input_value(T0, "T0");

    /**
     * @brief Запрос ввода данных для линейной модели.
     */
    cout << "\tЗаполните данные для линейной модели\n";
    LinearModel liner_model = get_liner_model(T0);

    /**
     * @brief Получаем температуры из линейной модели.
     */
    vector <double> temps_linear = liner_model.getTemp();

    /**
     * @brief Создаем объекты PID-регулятора.
     */
    PID pid_liner, pid_nonlinear;

    /**
     * @brief Рассчитываем управляющий сигнал с помощью PID для линейной модели.
     */
    pid_liner.calculate(w, T0, temps_linear);

    /**
     * @brief Получаем управляющие сигналы от PID-регулятора для линейной модели.
     */
    vector <vector<double>> control_signals_liner = pid_liner.getControlSignals();

    /**
     * @brief Запрос ввода данных для нелинейной модели.
     */
    cout << "\tЗаполните данные для нелинейной модели\n";
    NonLinearModel non_liner_model = get_nonlinear_model(T0);

    /**
     * @brief Получаем температуры из нелинейной модели.
     */
    vector <double> temps_nonlinear = non_liner_model.getTemp();

    /**
     * @brief Рассчитываем управляющий сигнал с помощью PID для нелинейной модели.
     */
    pid_nonlinear.calculate(w, T0, temps_nonlinear);

    /**
     * @brief Получаем управляющие сигналы от PID-регулятора для нелинейной модели.
     */
    vector <vector<double>> control_signals_nonlinear = pid_nonlinear.getControlSignals();

    /**
     * @brief Выводим результаты для линейной модели.
     */
    output(control_signals_liner, "Линейная модель");
    /**
     * @brief Выводим результаты для нелинейной модели.
     */
    output(control_signals_nonlinear, "Нелинейная модель");
}

/**
 * @brief Функция для вывода результатов.
 *
 * @param control_signals Управляющие сигналы для вывода.
 * @param name Имя модели.
 */
void output(const vector <vector<double>>& control_signals, const string& name) {
    /**
     * @brief Вывод заголовка таблицы.
     */
    cout << "\n\t\t\t\t\t\t\t\tРЕЗУЛЬТАТЫ\n\n";
    cout << "\t\t\t\t\t\t\t\t" << name << "\n\n";
    cout.setf(ios::left);
    cout << setw(15) << "ВРЕМЯ (T0)";
    cout << setw(20) << "ОТКЛОНЕНИЕ (e)";
    cout << setw(27) << "ВЫХОДНАЯ ПЕРЕМЕННАЯ (Yt)";
    cout << setw(35) << "УПРАВЛЯЮЩЕЕ ВЛИЯНИЕ (Uk)" << endl;
    cout << setfill('=') << setw(85) << "" << setfill(' ') << endl;
    int i = 1;
    for (const auto& signal : control_signals) {
        /**
         * @brief Вывод строки таблицы.
         */
        cout << setw(15) << i++;
        cout << setw(20) << signal[0];
        cout << setw(27) << signal[1];
        cout << setw(35) << signal[2] << endl;
    }
}

/**
 * @brief Шаблонная функция для ввода значения.
 *
 * @param value Значение для ввода.
 * @param name Имя значения.
 *
 * @return true, если все в порядке.
 */
template<typename T> bool input_value(T& value, const string& name) {
    while (true) {
        /**
         * @brief Запрос ввода значения.
         */
        cout << "Введите " << name << ": ";
        if (cin >> value) {
            /**
             * @brief Если ввод корректен, возвращаем true.
             */
            return true;
        }
        else {
            /**
             * @brief Если ввод некорректен, выводим сообщение об ошибке.
             */
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\n\a\t\t***Некорректное значение ввода***\n\n";
        }
    }
}

/**
 * @brief Функция для ввода данных для линейной модели.
 *
 * @return Линейная модель.
 */
LinearModel get_liner_model(const int& T0) {
    double A, B, current_temperature, warm;
    /**
     * @brief Ввод данных для линейной модели.
     */
    input_value(A, "A");
    input_value(B, "B");
    input_value(current_temperature, "current_temperature");
    input_value(warm, "warm");
    LinearModel model(A, B, current_temperature, warm);
    model.calculate(T0);
    return model;
}

/**
 * @brief Функция для ввода данных для нелинейной модели.
 *
 * @return Нелинейная модель.
 */
NonLinearModel get_nonlinear_model(const int& T0) {
    double A, B, C, D, current_temperature, warm;
    /**
     * @brief Ввод данных для нелинейной модели.
     */
    input_value(A, "A");
    input_value(B, "B");
    input_value(C, "C");
    input_value(D, "D");
    input_value(current_temperature, "current_temperature");
    input_value(warm, "warm");
    NonLinearModel model(A, B, C, D, current_temperature, warm);
    model.calculate(T0);
    return model;
}

/**
 * @brief Функция для ввода выбора.
 *
 * @param choice Выбор.
 *
 * @return true, если все в порядке.
 */
bool choice_input(int& choice) {
    while (true) {
        if (input_value(choice, "выбор")) {
            if (choice >= 0 && choice <= 1) {
                /**
                 * @brief Если ввод корректен, возвращаем true.
                 */
                return true;
            }
            else {
                /**
                 * @brief Если ввод некорректен, выводим сообщение об ошибке.
                 */
                cerr << "\n\a\t\t***Некорректное значение ввода***\n\n";
            }
        }
    }
}
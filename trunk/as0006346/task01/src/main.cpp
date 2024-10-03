#include <iostream>
#include <cmath>    // Для функции sin

// Функция для симуляции линейной модели
double linearSim(double currentTemp, double currentInput, double coeffA, double coeffB) {
    return coeffA * currentTemp + coeffB * currentInput;
}

// Функция для симуляции нелинейной модели
double nonlinearSim(double currentTemp, double prevTemp, double currentInput, double prevInput, double coeffA, double coeffB, double coeffC, double coeffD) {
    return coeffA * currentTemp - coeffB * pow(prevTemp, 2) + coeffC * currentInput + coeffD * sin(prevInput);
}

int main() {
    system("chcp 1251");
    // Константы (их можно изменить)
    double coeffA = 0.5;
    double coeffB = 0.1;
    double coeffC = 0.2;
    double coeffD = 0.05;

    // Начальные условия
    double currentTemp = 0.0;           // Начальная температура
    double prevTemp = 0.0;              // Предыдущая температура (для нелинейной модели)
    double currentInput = 1.0;          // Начальное значение тепла
    double prevInput = 1.0;             // Предыдущее значение тепла (для нелинейной модели)

    // Количество шагов моделирования
    int totalSteps = 100;

    // Симуляция системы во времени
    for (int step = 0; step < totalSteps; ++step) {
        // Симуляция линейной модели
        double linearTemp = linearSim(currentTemp, currentInput, coeffA, coeffB);
        
        // Симуляция нелинейной модели
        double nonlinearTemp = nonlinearSim(currentTemp, prevTemp, currentInput, prevInput, coeffA, coeffB, coeffC, coeffD);

        // Обновление состояний для следующей итерации
        prevTemp = currentTemp;
        currentTemp = linearTemp;        // Используем результат линейной модели для следующего шага
        prevInput = currentInput;
        currentInput = 1.0;  // или другая функция, которая изменяется во времени

        // Вывод результатов
        std::cout << "Шаг времени " << step + 1 << ":\n";
        std::cout << "  Температура линейной модели: " << linearTemp << "\n";
        std::cout << "  Температура нелинейной модели: " << nonlinearTemp << "\n\n";
    }

    return 0;
}

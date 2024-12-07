#include <iostream>
#include <cmath>

// Общая функция модели
double model(bool isLinear, double Yt, double Yt_1, double U, double a, double b, double c = 0, double d = 0) {
    if (isLinear) {
        return a * Yt + b * U; // Линейная модель
    } else {
        return a * Yt - b * pow(Yt_1, 2) + c * U + d * sin(U); // Нелинейная модель
    }
}

int main() {
    // Параметры моделей
    double a = 0.8;
    double b = 0.5;
    double c = 0.2;
    double d = 0.1;

    // Начальные значения
    double Y_linear = 0.0;
    double Y_nonlinear = 0.0;
    double Y_prev_nonlinear = 0.0;

    // Входное значение
    double U = 1.0;

    // Моделирование для 10 временных шагов
    for (int t = 1; t <= 10; t++) {
        // Линейная модель
        Y_linear = model(true, Y_linear, 0, U, a, b);

        // Нелинейная модель
        Y_nonlinear = model(false, Y_nonlinear, Y_prev_nonlinear, U, a, b, c, d);
        Y_prev_nonlinear = Y_nonlinear;

        // Вывод результатов
        std::cout << "time step: " << t << std::endl;
        std::cout << "Linear model: " << Y_linear << std::endl;
        std::cout << "Nonlinear model: " << Y_nonlinear << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}

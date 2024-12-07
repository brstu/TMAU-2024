#include <iostream>
#include <cmath>

using namespace std;

void linearModel(double y, double u, double a, double b, int steps) {
    for (int i = 1; i <= steps; i++) {
        double y_next = a * y + b * u;
        cout << "Шаг " << i << ": y = " << y_next << endl;

        y = y_next;
    }
}

void nonlinearModel(double y, double u, double a, double b, double c, double d, int steps) {
    double y_prev = 0;
    double u_prev = 0;

    for (int i = 1; i <= steps; i++) {
        double y_next = a * y - b * y_prev * y_prev + c * u + d * sin(u_prev);
        cout << "Шаг " << i << ": y = " << y_next << endl;

        y_prev = y; 
        u_prev = u; // Обновляем

        y = y_next; 
    }
}

int main() {
    double a, b, c, d; // Константы
    double y; // Текущая температура
    double u; // Текущее тепло
    int steps; // Количество шагов моделирования

    cout << "Введите значение  a: ";
    cin >> a;
    cout << "Введите значение  b: ";
    cin >> b;
    cout << "Введите значение  c: ";
    cin >> c;
    cout << "Введите значение  d: ";
    cin >> d;

    cout << "Введите начальное значение текущей температуры, y: ";
    cin >> y;
    cout << "Введите начальное значение управляющего воздействия, u: ";
    cin >> u;

    cout << "Введите количество итераций, шагов: ";
    cin >> steps;

    // Линейная
    cout << "\nСимуляция линейной модели:\n";
    linearModel(y, u, a, b, steps);

    // Нелинейная
    cout << "\nСимуляция нелинейной модели:\n";
    nonlinearModel(y, u, a, b, c, d, steps);

    return 0;
}
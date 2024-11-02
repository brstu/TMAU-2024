#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double linearModel(double y, double u, double a, double b) {
    return a * y + b * u;
}

double nonlinearModel(double y, double y_prev, double u, double u_prev, double a, double b, double c, double d) {
    return a * y - b * y_prev * y_prev + c * u + d * sin(u_prev);
}

int main() {
    const double a = 0.5;
    const double b = 0.1;
    const double c = 0.2;
    const double d = 0.05;

    double y = 0.0;
    double y_prev = 0.0;
    double u = 1.0;
    double u_prev = 1.0;

    int numSteps;
    cout << "Введите количество шагов моделирования: ";
    cin >> numSteps;

    int modelType;
    cout << "Выберите модель (1 - линейная, 2 - нелинейная): ";
    cin >> modelType;

    for (int t = 0; t < numSteps; ++t) {
        double y_next;

        if (modelType == 1) {
            y_next = linearModel(y, u, a, b);
        } else if (modelType == 2) {
            y_next = nonlinearModel(y, y_prev, u, u_prev, a, b, c, d);
        } else {
            cout << "Неправильный выбор модели!" << endl;
            break;
        }

        cout << "Шаг " << t << ": y = " << y_next << ", u = " << u << endl;

        y_prev = y;
        y = y_next;
        u_prev = u;

        u = 1.0;
    }

    return 0;
}

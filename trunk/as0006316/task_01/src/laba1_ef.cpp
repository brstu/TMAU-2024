#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

struct ModelParams {
    double a, b, c, d;
};

double calculate_linear_temp(const ModelParams& params, double prev_temp, double heat) {
    return params.a * prev_temp + params.b * heat;
}

double calculate_nonlinear_temp(const ModelParams& params, double prev_temp, double heat) {
    return params.a * prev_temp - params.b * pow(prev_temp, 2) + params.c * heat + params.d * sin(heat);
}

vector<double> simulate_temperature(const ModelParams& params, double initial_temp, double heat, int steps, bool is_linear) {
    vector<double> temps(steps + 1);
    temps[0] = initial_temp;

    for (int i = 1; i <= steps; ++i) {
        if (is_linear) {
            temps[i] = calculate_linear_temp(params, temps[i - 1], heat);
        }
        else {
            temps[i] = calculate_nonlinear_temp(params, temps[i - 1], heat);
        }
    }


    return temps;
}

int main() {
    setlocale(LC_ALL, "russian");
    ModelParams params;
    cout << "Введите коэффициенты модели (a, b, c, d): ";
    cin >> params.a >> params.b >> params.c >> params.d;

    double initial_temp, heat;
    int steps;
    cout << "Введите начальную температуру: ";
    cin >> initial_temp;
    cout << "Введите тепловой поток: ";
    cin >> heat;
    cout << "Введите количество шагов: ";
    cin >> steps;

    int choice;
    cout << "Выберите модель (1 - линейная, 2 - нелинейная): ";
    cin >> choice;

    vector<double> temps;
    if (choice == 1) {
        temps = simulate_temperature(params, initial_temp, heat, steps, true);
    }
    else if (choice == 2) {
        temps = simulate_temperature(params, initial_temp, heat, steps, false);
    }
    else {
        cout << "Неверный выбор модели!" << endl;
        return 1;
    }

    cout << "\nРезультаты моделирования:\n";
    cout << "-------------------------\n"; // Добавлена линия для разделения
    cout << fixed << setprecision(2); // Установка фиксированной точности для вывода

    for (int i = 0; i <= steps; ++i) {
        cout << "Шаг " << i << ": Температура = " << temps[i] << "°C" << endl; // Добавлено обозначение градусов Цельсия
    }

    return 0;
}
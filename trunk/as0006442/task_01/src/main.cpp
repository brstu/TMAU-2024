#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

struct Coefficients {
    double a, b, c, d;
};

double get_linear_temperature(const Coefficients& coeffs, double current_temp, double heat_flow) {
    return coeffs.a * current_temp + coeffs.b * heat_flow;
}

double get_nonlinear_temperature(const Coefficients& coeffs, double current_temp, double heat_flow) {
    return coeffs.a * current_temp - coeffs.b * pow(current_temp, 2) + coeffs.c * heat_flow + coeffs.d * sin(heat_flow);
}

vector<double> calculate_temperatures(const Coefficients& coeffs, double start_temp, double heat_flow, int num_steps, bool linear_model) {
    vector<double> temperature_values(num_steps + 1);
    temperature_values[0] = start_temp;

    for (int i = 1; i <= num_steps; ++i) {
        if (linear_model) {
            temperature_values[i] = get_linear_temperature(coeffs, temperature_values[i - 1], heat_flow);
        } else {
            temperature_values[i] = get_nonlinear_temperature(coeffs, temperature_values[i - 1], heat_flow);
        }
    }

    return temperature_values;
}

int main() {
    setlocale(LC_ALL, "russian");

    Coefficients coeffs;
    cout << "Введите значения коэффициентов (a, b, c, d): ";
    cin >> coeffs.a >> coeffs.b >> coeffs.c >> coeffs.d;

    double start_temp, heat_flow;
    int num_steps;
    cout << "Введите начальную температуру: ";
    cin >> start_temp;
    cout << "Введите тепловой поток: ";
    cin >> heat_flow;
    cout << "Введите количество шагов: ";
    cin >> num_steps;

    int model_choice;
    cout << "Выберите тип модели (1 - линейная, 2 - нелинейная): ";
    cin >> model_choice;

    vector<double> temperature_values;
    if (model_choice == 1) {
        temperature_values = calculate_temperatures(coeffs, start_temp, heat_flow, num_steps, true);
    } else if (model_choice == 2) {
        temperature_values = calculate_temperatures(coeffs, start_temp, heat_flow, num_steps, false);
    } else {
        cout << "Некорректный выбор модели!" << endl;
        return 1;
    }

    cout << "\nРезультаты моделирования:\n";
    cout << "-------------------------\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i <= num_steps; ++i) {
        cout << "Шаг " << i << ": Температура = " << temperature_values[i] << "°C" << endl;
    }

    return 0;
}

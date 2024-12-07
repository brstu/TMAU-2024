#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Функция для симуляции линейной модели
vector<double> simulateLinearSystem(double alpha, double beta, double initialTemp, const vector<double>& heatInputs, int timeSteps) {
    vector<double> temperatures(timeSteps);
    temperatures[0] = initialTemp; // Начальная температура

    // Рассчёт температуры на каждом временном шаге
    for (int step = 1; step < timeSteps; ++step) {
        temperatures[step] = alpha * temperatures[step - 1] + beta * heatInputs[step - 1];
    }

    return temperatures; // Возвращаем вектор температур
}

// Функция для симуляции нелинейной модели
vector<double> simulateNonLinearSystem(double alpha, double beta, double gamma, double delta, double initialTemp, const vector<double>& heatInputs, int timeSteps) {
    vector<double> temperatures(timeSteps);
    temperatures[0] = initialTemp; // Начальная температура

    // Рассчёт температуры на каждом временном шаге
    for (int step = 1; step < timeSteps; ++step) {
        double prevTemp = temperatures[step - 1];
        double prevInput = heatInputs[step - 1];
        temperatures[step] = alpha * prevTemp - beta * pow(prevTemp, 2) + gamma * prevInput + delta * sin(prevInput);
    }

    return temperatures; // Возвращаем вектор температур
}

int main() {
    // Ввод констант от пользователя
    double alpha, beta, gamma, delta, initialTemp;
    cout << "Введите коэффициент alpha для модели: ";
    cin >> alpha;
    cout << "Введите коэффициент beta для линейной модели: ";
    cin >> beta;
    cout << "Введите коэффициент gamma для нелинейной модели: ";
    cin >> gamma;
    cout << "Введите коэффициент delta для нелинейной модели: ";
    cin >> delta;
    cout << "Введите начальную температуру: ";
    cin >> initialTemp;

    // Ввод количества временных шагов
    int timeSteps;
    cout << "Введите количество временных шагов: ";
    cin >> timeSteps;

    // Ввод значений нагрева
    vector<double> heatInputs(timeSteps);
    cout << "Введите значения нагрева для каждого временного шага:" << endl;
    for (int i = 0; i < timeSteps; ++i) {
        cout << "Нагрев (u[" << i + 1 << "]): ";
        cin >> heatInputs[i];
    }

    // Симуляция линейной модели
    vector<double> linearTemps = simulateLinearSystem(alpha, beta, initialTemp, heatInputs, timeSteps);

    // Симуляция нелинейной модели
    vector<double> nonLinearTemps = simulateNonLinearSystem(alpha, beta, gamma, delta, initialTemp, heatInputs, timeSteps);

    // Вывод результатов
    cout << "\nСимуляция линейной модели:" << endl;
    for (int step = 0; step < timeSteps; ++step) {
        cout << "Шаг " << step + 1 << ": Температура = " << linearTemps[step] << endl;
    }

    cout << "\nСимуляция нелинейной модели:" << endl;
    for (int step = 0; step < timeSteps; ++step) {
        cout << "Шаг " << step + 1 << ": Температура = " << nonLinearTemps[step] << endl;
    }

    return 0; // Завершение программы
}

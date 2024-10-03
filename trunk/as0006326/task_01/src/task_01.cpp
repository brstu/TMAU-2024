#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Функция для моделирования линейной динамики
vector<double> linearDynamics(double alpha, double beta, double initialTemp, const vector<double>& heatInput, int timeSteps) {
    vector<double> temp(timeSteps);
    temp[0] = initialTemp; // Начальная температура

    // Цикл по каждому временному шагу для расчета температуры
    for (int t = 1; t < timeSteps; ++t) {
        temp[t] = alpha * temp[t - 1] + beta * heatInput[t - 1]; // Обновление температуры в линейной модели
    }

    return temp; // Возвращаем вектор температур
}

// Функция для моделирования нелинейной динамики
vector<double> nonlinearDynamics(double alpha, double beta, double gamma, double delta, double initialTemp, const vector<double>& heatInput, int timeSteps) {
    vector<double> temp(timeSteps);
    temp[0] = initialTemp; // Начальная температура

    // Цикл по каждому временному шагу для расчета температуры
    for (int t = 1; t < timeSteps; ++t) {
        double prev_temp = temp[t - 1];
        double prev_heat = heatInput[t - 1];
        temp[t] = alpha * prev_temp - beta * pow(prev_temp, 2) + gamma * prev_heat + delta * sin(prev_heat); // Обновление для нелинейной модели
    }

    return temp; // Возвращаем вектор температур
}

int main() {
    // Ввод констант от пользователя
    double alpha, beta, gamma, delta, initialTemp;
    cout << "Введите коэффициент alpha: ";
    cin >> alpha;
    cout << "Введите коэффициент beta для линейной модели: ";
    cin >> beta;
    cout << "Введите коэффициент gamma для нелинейной модели: ";
    cin >> gamma;
    cout << "Введите коэффициент delta для нелинейной модели: ";
    cin >> delta;
    cout << "Введите начальную температуру (initialTemp): ";
    cin >> initialTemp;

    // Ввод количества временных шагов
    int timeSteps;
    cout << "Введите количество временных шагов: ";
    cin >> timeSteps;

    // Ввод значений теплового воздействия
    vector<double> heatInput(timeSteps);
    cout << "Введите значения теплового воздействия для каждого временного момента:" << endl;
    for (int i = 0; i < timeSteps; ++i) {
        cout << "heatInput[" << i + 1 << "]: ";
        cin >> heatInput[i]; // Чтение входного значения тепла
    }

    // Моделирование линейной динамики
    vector<double> linearTemp = linearDynamics(alpha, beta, initialTemp, heatInput, timeSteps);

    // Моделирование нелинейной динамики
    vector<double> nonlinearTemp = nonlinearDynamics(alpha, beta, gamma, delta, initialTemp, heatInput, timeSteps);

    // Вывод результатов
    cout << "\nМоделирование линейной динамики:" << endl;
    for (int t = 0; t < timeSteps; ++t) {
        cout << "Время " << t + 1 << ": Температура = " << linearTemp[t] << endl;
    }

    cout << "\nМоделирование нелинейной динамики:" << endl;
    for (int t = 0; t < timeSteps; ++t) {
        cout << "Время " << t + 1 << ": Температура = " << nonlinearTemp[t] << endl;
    }

    return 0; // Завершение программы
}
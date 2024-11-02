#include <iostream>
#include <cmath>
using namespace std;

// Линейная модель
void linearModel(double coeffA, double coeffB, double heatInput, double currentTemp, int cycles) {
    cout << "\tЛинейная модель" << endl;
    for (int i = 1; i <= cycles; i++) {
        double nextTemp = coeffA * currentTemp + coeffB * heatInput; // Вычисление следующей температуры
        cout << "y" << i << " = " << nextTemp << endl; // Используем следующую температуру
        currentTemp = nextTemp; // Обновление текущей температуры для следующей итерации
    }
}

// Нелинейная модель
void nonlinearModel(double coeffA, double coeffB, double coeffC, double coeffD, double heatInput, double currentTemp, int cycles) {
    double prevHeat = 0;
    double prevTemp = 0;

    cout << "\tНелинейная модель" << endl;
    for (int i = 1; i <= cycles; i++) {
        double nextTemp = coeffA * currentTemp - coeffB * pow(prevTemp, 2) + coeffC * heatInput + coeffD * sin(prevHeat);
        cout << "y" << i << " = " << nextTemp << endl;
        prevHeat = heatInput;
        prevTemp = currentTemp;
        currentTemp = nextTemp; // Обновление текущей температуры для следующей итерации
    }
}

int main() {
    system("chcp 1251");
    system("cls");

    double coeffA, coeffB, coeffC, coeffD; // Константы
    double heatInput; // Теплота
    double currentTemp; // Температура
    int cycles; // Такты

    cout << "Введите константу a: "; cin >> coeffA;
    cout << "Введите константу b: "; cin >> coeffB;
    cout << "Введите константу c: "; cin >> coeffC;
    cout << "Введите константу d: "; cin >> coeffD;
    cout << "Введите подаваемое тепло: "; cin >> heatInput;
    cout << "Введите температуру: "; cin >> currentTemp;
    cout << "Введите количество тактов работы модели: "; cin >> cycles;

    linearModel(coeffA, coeffB, heatInput, currentTemp, cycles);
    nonlinearModel(coeffA, coeffB, coeffC, coeffD, heatInput, currentTemp, cycles);

    return 0;
}

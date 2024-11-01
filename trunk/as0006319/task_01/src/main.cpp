#include <iostream>
#include <cmath>
using namespace std;

// Линейная модель
void lineynaya(double a, double b, double uT, double yT, int t) {
    cout << "\tЛинейная модель" << endl;
    for (int i = 1; i <= t; i++) {
        double yT1 = a * yT + b * uT; // Вычисление yT1
        cout << "y" << i << " = " << yT1 << endl; // Используем yT1, а не yT
        yT = yT1; // Обновление yT для следующей итерации
    }
}

// Нелинейная модель
void neLineynaya(double a, double b, double c, double d, double uT, double yT, int t) {
    double uT_1 = 0;
    double yT_1 = 0;

    cout << "\tНелинейная модель" << endl;
    for (int i = 1; i <= t; i++) {
        double yT1 = a * yT - b * pow(yT_1, 2) + c * uT + d * sin(uT_1);
        cout << "y" << i << " = " << yT1 << endl;
        uT_1 = uT;
        yT_1 = yT;
        yT = yT1; // Обновление yT для следующей итерации
    }
}

int main() {
    system("chcp 1251");
    system("cls");

    double a, b, c, d; // Константы
    double uT; // Теплота
    double yT; // Температура
    int t; // Такты

    cout << "Введите константу a: "; cin >> a;
    cout << "Введите константу b: "; cin >> b;
    cout << "Введите константу c: "; cin >> c;
    cout << "Введите константу d: "; cin >> d;
    cout << "Введите подаваемое тепло: "; cin >> uT;
    cout << "Введите температуру: "; cin >> yT;
    cout << "Введите количество тактов работы модели: "; cin >> t;

    lineynaya(a, b, uT, yT, t);
    neLineynaya(a, b, c, d, uT, yT, t);

    return 0;
}

﻿#include <iostream>
#include <cmath>
using namespace std;

//линейная модель
void linear(double a, double b, double uT, double yT, int t) {
    cout << "\t---Линейна температурная модель---" << endl;
    for (int i = 1; i <= t; i++) {
        double yT1 = a * yT + b * uT;
        cout << "y" << i << " = " << yT1 << endl;
        yT = yT1;
    }
}

//НЕлинейная модель
void nonLinear(double a, double b, double c, double d, double uT, double yT, int t) {
    double uT_1 = 0;
    double yT_1 = 0;

    cout << "\t---Нелинейная температурная модель---" << endl;
    for (int i = 1; i <= t; i++) {
        double yT1 = a * yT - b * pow(yT_1, 2) + c * uT + d * sin(uT_1);
        cout << "y" << i << " = " << yT1 << endl;
        uT_1 = uT;
        yT_1 = yT;
        yT = yT1;
    }
}

int main() {

    system("chcp 1251");
    system("cls");

    double a, b, c, d; //константы
    double uT; //теплота
    double yT; //температура
    int t; // такты

    cout << "Введите константу a: "; cin >> a;
    cout << "Введите константу b: "; cin >> b;
    cout << "Введите константу c: "; cin >> c;
    cout << "Введите константу d: "; cin >> d;
    cout << "Введите подаваемое тепло: "; cin >> uT;
    cout << "Введите температуру: "; cin >> yT;
    cout << "Введите количество тактов работы модели: "; cin >> t;

    linear(a, b, uT, yT, t);
    nonLinear(a, b, c, d, uT, yT, t);

    return 0;
}

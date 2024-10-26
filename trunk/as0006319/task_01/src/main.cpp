#include <iostream>
#include <cmath>
using namespace std;

//линейная модель
void lineynaya(double a, double b, double at, double bt, int t) {
    cout << "\tЛинейна модель" << endl;
    for (int i = 1; i <= t; i++) {
        double bt1 = a * bt + b * at;
        cout << "y" << i << " = " << yT1 << endl;
        bt = bt1;
    }
}

//НЕлинейная модель
void neLineynaya(double a, double b, double c, double d, double at, double bt, int t) {
    double at_1 = 0;
    double bt_1 = 0;

    cout << "\tНелинейная модель" << endl;
    for (int i = 1; i <= t; i++) {
        double bt1 = a * bt - b * pow(bt_1, 2) + c * at + d * sin(uT_1);
        cout << "y" << i << " = " << bt1 << endl;
        at_1 = at;
        bt_1 = bt;
        bt = bt1;
    }
}

int main() {

    system("chcp 1251");
    system("cls");

    double a, b, c, d; //константы
    double at; //теплота
    double bt; //температура
    int t; // такты

    cout << "Введите константу a: "; cin >> a;
    cout << "Введите константу b: "; cin >> b;
    cout << "Введите константу c: "; cin >> c;
    cout << "Введите константу d: "; cin >> d;
    cout << "Введите подаваемое тепло: "; cin >> at;
    cout << "Введите температуру: "; cin >> bt;
    cout << "Введите количество тактов работы модели: "; cin >> t;

    lineynaya(a, b, at, bt, t);
    neLineynaya(a, b, c, d, at, bt, t);

    return 0;
}

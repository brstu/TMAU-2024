#include <iostream>
#include <cmath>

using namespace std;

void nonLinearModel(float a, float b, float c, float d, float uT, float yT, int t) {
    float yT_prev = 0;
    float uT_prev = 0;

    cout << "Нелинейная температурная модель:" << endl;
    for (int k = 1; k <= t; k++) {
        float yT_next = a * yT - b * pow(yT_prev, 2) + d * sin(uT_prev) + c * uT;
        cout << "y" << k << " = " << yT_next << endl;

        uT_prev = uT;
        yT_prev = yT;
        yT = yT_next;
    }
}

void linearModel(float a, float b, float uT, float yT, int t) {
    cout << "Линейная температурная модель:" << endl;
    for (int k = 1; k <= t; k++) {
        float yT_next = a * yT + b * uT;
        cout << "y" << k << " = " << yT_next << endl;
        yT = yT_next;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    float a, b, c, d, uT, yT;
    int t;

    cout << "Введите константы" << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "c: "; cin >> c;
    cout << "d: "; cin >> d;
    cout << "Подаваемое тепло: "; cin >> uT;
    cout << "Начальная температура: "; cin >> yT;
    cout << "Количество тактов работы модели: "; cin >> t;

    nonLinearModel(a, b, c, d, uT, yT, t);
    linearModel(a, b, uT, yT, t);

    return 0;
}
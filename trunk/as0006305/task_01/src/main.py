#include<iostream>
#include<cmath>

using namespace std;

//НЕлинейная модель
void nonLinear(float a, float b, float c, float d, float uT, float yT, int t) {
    float uT_1 = 0;
    float yT_1 = 0;

    cout << "\t---Нелинейная температурная модель---" << endl;
    for (int i = 1; i <= t; i++) {
        double yT1 = a * yT - b * pow(yT_1, 2) + c * uT + d * sin(uT_1);
        cout << "y" << i << " = " << yT1 << endl;
        uT_1 = uT;
        yT_1 = yT;
        yT = yT1;
    }
}

//линейная модель
void linear(float a, float b, float uT, float yT, int t) {
    cout << "\t---Линейная температурная модель---" << endl;
    for (int i = 1; i <= t; i++) {
        float yT1 = a * yT + b * uT;
        cout << "y" << i << " = " << yT1 << endl;
        yT = yT1;
    }
}



int main()
{
    setlocale(LC_ALL, "Russian");
    
    //константы
    float a, b, c, d;
    
    //теплота
    float uT;
    
    //температура
    float yT;
    
    // такты
    int t;

    cout << "Введите константы" << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "c: "; cin >> c;
    cout << "d: "; cin >> d;
    
    cout << "Введите подаваемое тепло: "; cin >> uT;
    cout << "Введите температуру: "; cin >> yT;
    cout << "Введите к-во тактов работы модели: "; cin >> t;
    
    nonLinear(a, b, c, d, uT, yT, t);
    linear(a, b, uT, yT, t);
    
    return 0;
}

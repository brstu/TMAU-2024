#include<iostream>
#include<cmath>

using namespace std;

//НЕлинейная модель
void nonLinearModel(float a, float b, float c, float d, float uT, float yT, int t) {
    float uT_1 = 0;
    float yT_1 = 0;

    cout << "Нелинейная температурная модель:" << endl;
    for (int k = 1; k <= t; k++) {
        double yT1 = a * yT - b * pow(yT_1, 2) + c * uT + d * sin(uT_1);
        cout << "y" << k << " = " << yT1 << endl;
        uT_1 = uT;
        yT_1 = yT;
        yT = yT1;
    }
}

//линейная модель
void linearModel(float a, float b, float uT, float yT, int t) {
    cout << "Линейная температурная модель:" << endl;
    for (int k = 1; k <= t; k++) {
        float yT1 = a * yT + b * uT;
        cout << "y" << k << " = " << yT1 << endl;
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
    
    cout << "Подаваемое тепло: "; cin >> uT;
    cout << "Температура: "; cin >> yT;
    cout << "К-во тактов работы модели: "; cin >> t;
    
    //функции
    nonLinearModel(a, b, c, d, uT, yT, t);
    linearModel(a, b, uT, yT, t);
}

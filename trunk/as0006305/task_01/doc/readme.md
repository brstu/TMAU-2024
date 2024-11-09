<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">По дисциплине “Теория и методы автоматического управления”</p>
<p align="center">Тема: “Моделирования температуры объекта”</p>
<br><br><br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-63</p>
<p align="right">Казаренко П. В.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2024</p>

---

**Задание**:

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

After transformation we get these linear (2) and nonlinear (3) models:

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)

$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ – time discrete moments ($1,2,3{\dots}n$); $a,b,c,d$ – some constants.

Task is to write program (**С++**), which simulates this object temperature.

Код программы:
``` cpp
#include<iostream>

#include<cmath>

  

using namespace std;

  

//НЕлинейная модель

void nonLinearModel(float a, float b, float c, float d, float uT, float yT, int t) {

    float yT_1 = 0;

    float uT_1 = 0;

  

    cout << "Нелинейная температурная модель:" << endl;

    for (int k = 1; k <= t; k++) {

        double yT1 = a * yT - b * pow(yT_1, 2) + d * sin(uT_1) + c * uT;

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

        float yT1 = b * uT + a * yT;

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

    float uT = 0;

    //температура

    float yT = 0;

    // такты

    int t = 0;

  

    cout << "Введите константы" << endl;

    cout << "a: ";

    cin >> a;

    cout << "b: ";

    cin >> b;

    cout << "c: ";

    cin >> c;

    cout << "d: ";

    cin >> d;

    cout << "Подаваемое тепло: "; cin >> uT;

    cout << "Температура: "; cin >> yT;

    cout << "К-во тактов работы модели: "; cin >> t;

    //функции

    nonLinearModel(a, b, c, d, uT, yT, t);

    linearModel(a, b, uT, yT, t);

}
```

Результат работы программы:
``` bash
Введите константы
a: 
4
b: 
2
c: 
8
d: 
1
Подаваемое тепло: 
7
Температура: 
4
К-во тактов работы модели: 
5
Нелинейная температурная модель:
y1 = 72
y2 = 312.657
y3 = -9060.72
y4 = -231695
y5 = -1.6512e+08
Линейная температурная модель:
y1 = 30
y2 = 134
y3 = 550
y4 = 2214
y5 = 8870

```

Вывод: я закрепил навыки разработки на языке C++.

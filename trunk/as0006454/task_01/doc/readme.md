<p style="text-align: center;">Министерство образования Республики Беларусь</p>
<p style="text-align: center;">Учреждение образования</p>
<p style="text-align: center;">“Брестский Государственный технический университет”</p>
<p style="text-align: center;">Кафедра ИИТ</p>
<div style="margin-bottom: 10em;"></div>
<p style="text-align: center;">Лабораторная работа №1</p>
<p style="text-align: center;">По дисциплине “Теория и методы автоматического управления”</p>
<p style="text-align: center;">Тема: “Моделирования температуры объекта”</p>
<div style="margin-bottom: 10em;"></div>
<p style="text-align: right;">Выполнил:</p>
<p style="text-align: right;">Студент 3 курса</p>
<p style="text-align: right;">Группы АС-64</p>
<p style="text-align: right;">Хомич В. Г.</p>
<p style="text-align: right;">Проверила:</p>
<p style="text-align: right;">Ситковец Я. С.</p>
<div style="margin-bottom: 10em;"></div>
<p style="text-align: center;">Брест 2024</p>

---

**Задание**:

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $ (1)

where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

After transformation we get these linear (2) and nonlinear (3) models:

$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$ (2)

$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$ (3)

where $\tau$ – time discrete moments ($1,2,3{\dots}n$); $a,b,c,d$ – some constants.

Task is to write program (**С++**), which simulates this object temperature.

---

# Выполнение задания #

Код программы:

```cpp
#include <iostream>
#include <cmath>
using namespace std;
class functs {
public:
    double a = 0.2;  // Modified value
    double b = 0.3;  // Modified value
    double c = 0.2;  // Modified value
    double d = 0.3;  // Modified value
    double u = 1.0;
    double y = 0.0;

    void print(double val) const {
        cout << val <<endl;
    }

    // Modified linear model
    double linear(double y_input, int n, int t) {
        if (n < t) {
            print(y_input);
            return linear(a * y_input + b * u, n + 1, t);
        }
        print(y_input);
        return a * y_input + b * u;
    }
};

int main() {
    functs f;

    cout << "Linear model" << endl;
    cout << f.linear(f.y, 0, 10) << endl << endl;
    cout << "Nolinear model" << endl;
    f.print(f.y);
    double y_prev = f.y;
    double u_prev = f.u;
    f.y = f.a * f.y - f.b * y_prev * y_prev + f.c * 1 + f.d * sin(1);
    for (int i = 1; i < 20; i++) {
        f.print(f.y);
        double temp = f.y;
        f.y = f.a * f.y - f.b * y_prev * y_prev + f.c * f.u + f.d * sin(u_prev);
        y_prev = temp;
        u_prev = f.u;
    }

    return 0;
}
Вывод:
Linear model
0
0.3
0.36
0.372
0.3744
0.37488
0.374976
0.374995
0.374999
0.375
0.375
0.375

Nolinear model
0
0.452441
0.54293
0.499616
0.463933
0.470343
0.48194
0.482463
0.479254
0.478461
0.479228
0.479609
0.479465
0.479327
0.479341
0.479383
0.479388
0.479376
0.479373
0.479375
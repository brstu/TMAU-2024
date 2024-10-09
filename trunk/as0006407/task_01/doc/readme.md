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
<p style="text-align: right;">Евкович А. В.</p>
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
#include <math.h>

using namespace std;

const double a = 0.21;
const double b = 0.64;
const double c = 0.80;
const double d = 0.07;

const int step_number = 10;

double Linear_Model(double y, double u){
    double res = a * y + b * u;
    cout << res << endl;
    return res;
}

double Not_Linear_Model(double y, double y_prev, double u, double u_prev){
    double res = a * y - b * pow(y_prev, 2) + c * u + d * sin(u_prev);
    cout << res << endl;
    return res;
}

int main() {
    double y = 0.0;
    double u = 1.0;
    cout << "Linear:" << endl;
    for(int i = 0; i < step_number; i++){
        y = Linear_Model(y, u);
        y += 0.1;
        u += 0.1;
    }
    y = 0;
    u = 1;
    cout << "Not Linear:" << endl;
    for(int i = 0; i < step_number; i++){
        double y_prev = y;
        double u_prev = u;
        y = Not_Linear_Model(y + 0.1, y_prev, u + 0.1, u_prev);
    }
    return 0;
}
Вывод:
Linear:
0.64
0.8594
0.969474
1.05659
1.13888
1.22017
1.30123
1.38226
1.46327
1.54429
Not Linear:
0.959903
0.571778
0.870741
0.657517
0.821291
0.700682
0.792835
0.724102
0.776397
0.737159

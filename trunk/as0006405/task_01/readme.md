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
<p style="text-align: right;">Бурак И. Э.</p>
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
#include <vector>

using namespace std;

void linearModel(float A, float B, float temp, float warm, int time)
{
    cout << endl << "LinearModel:" << endl << endl;

    float currentTemp = temp;

    for (int i = 0; i < time; i++)
    {
        currentTemp = A * currentTemp + B * warm;

        cout << "y(" << i + 1 << ") = " << currentTemp << endl;
    }

    cout << endl;
}

void nonLinearModel(float A, float B, float C, float D, float temp, float warm, int time)
{
    cout << "NonLinearModel:" << endl << endl;

    vector<float> temps;
    temps.resize(time);

    for (int i = 0; i < time; i++)
    {
        float currentTemp;
        float prevTemp;

        if (i == 0)
        {
            currentTemp = temp;
            prevTemp = temp;
        }
        else if (i == 1)
        {
            currentTemp = temps[i - 1];
            prevTemp = temp;
        }
        else
        {
            currentTemp = temps[i - 1];
            prevTemp = temps[i - 2];
        }

        temps[i] = A * currentTemp - B * (float)pow(prevTemp, 2) + C * warm + D * sin(warm);

        cout << "y(" << i + 1 << ") = " << temps[i] << endl;
    }
}

int main()
{
    const float A = 0.8f;
    const float B = 0.5f;
    const float C = 2.1f;
    const float D = 1.3f;

    float temp;
    float warm;
    int time;

    cout << "Input object temperature: ";
    cin >> temp;

    cout << "Input warm:";
    cin >> warm;

    cout << "Input time limit:";
    cin >> time;

    linearModel(A, B, temp, warm, time);
    nonLinearModel(A, B, C, D, temp, warm, time);

    return 0;
}
Вывод:
Input object temperature: 10
Input warm:5
Input time limit:10

LinearModel:

y(1) = 10.5
y(2) = 10.9
y(3) = 11.22
y(4) = 11.476
y(5) = 11.6808
y(6) = 11.8446
y(7) = 11.9757
y(8) = 12.0806
y(9) = 12.1645
y(10) = 12.2316

NonLinearModel:

y(1) = -32.7466
y(2) = -66.9439
y(3) = -580.472
y(4) = -2695.87
y(5) = -170621
y(6) = -3.77033e+06
y(7) = -1.45588e+10
y(8) = -7.11936e+12
y(9) = -1.05979e+20
y(10) = -2.53427e+25
<p style="text-align: center;">Министерство образования Республики Беларусь</p>
<p style="text-align: center;">Учреждение образования</p>
<p style="text-align: center;">“Брестский Государственный технический университет”</p>
<p style="text-align: center;">Кафедра ИИТ</p>
<div style="margin-bottom: 10em;"></div>
<p style="text-align: center;">Лабораторная работа №2</p>
<p style="text-align: center;">По дисциплине “Теория и методы автоматического управления”</p>
<p style="text-align: center;">Тема: “ПИД-регуляторы”</p>
<div style="margin-bottom: 10em;"></div>
<p style="text-align: right;">Выполнил:</p>
<p style="text-align: right;">Студент 3 курса</p>
<p style="text-align: right;">Группы АС-63</p>
<p style="text-align: right;">Куликович И. С.</p>
<p style="text-align: right;">Проверила:</p>
<p style="text-align: right;">Ситковец Я. С.</p>
<div style="margin-bottom: 10em;"></div>
<p style="text-align: center;">Брест 2024</p>

---

***Задание***:
1.  На C++  реализовать программу, моделирующую рассмотренный выше ПИД-регулятор.  В качестве объекта управления использовать математическую модель, полученную в предыдущей работе. Использовать ООП, в программе должно быть не менее 3-х классов (+наследование).
2.  Написать отчет по выполненной лабораторной работе №2 в .md формате (*readme.md*) и с помощью **pull request** разместить его в следующем каталоге: **trunk\as000xxyy\task_02\doc**. В отчете также привести графики для разных заданий температуры объекта, пояснить полученные результаты.
3.  В отчет с помощью [Doxygen](https://doxygen.nl/) (в .md формате) добавить информацию о разработанной программе (диаграмма классов и т.п.).
4.  Исходный код написанной программы разместить в каталоге: **trunk\as000xxyy\task_02\src**.
<br>
---

# Выполнение задания #

Код программы:

```cpp
#include <iostream>
#include <cmath>

using namespace std;

class Model {
private:
    double a, b, c, d;
    double Prew_Y = 0;
    double Prew_U = 0;
    bool is_linear;
public:
    Model(double a, double b, double c = 0, double d = 0, bool is_linear = true)
        : a(a), b(b), c(c), d(d), is_linear(is_linear) {}

    double get_temperature(double Y, double U) {
        if (is_linear) {
            return a * Y + b * U;
        }
        else {
            double res = a * Y - b * pow(Prew_Y, 2) + c * U + d * sin(Prew_U);
            Prew_Y = Y;
            Prew_U = U;
            return res;
        }
    }
};

class PID_Regulator {
private:
    const double T_0 = 50;
    const double Time = 10;
    double Uk = 0;
    const double k = 0.1;
    const double T = 10;
    const double T_d = 10;
 
    double get_Uk(double e, double e1, double e2) {
        double q0 = k * (1 + (T_d/T_0));
        double q1 = -k * (1 + 2 * (T_d/T_0) - (T_0/T));
        double q2 = k * (T_d/T_0);
        Uk += q0 * e + q1 * e1 + q2 * e2;
        return Uk;
    }

public:

    void regulator(double w, double y0, Model& model) {
        double e2 = 0, e1 = 0, y = y0;
        for (int i = 1; i <= Time; i++) {
            double e = w - y;
            Uk = get_Uk(e, e1, e2);
            y = model.get_temperature(y0, Uk);
            cout << "E = " << e << ", Yt = " << y << ", Uk = " << Uk << std::endl;
            e2 = e1;
            e1 = e;
        }
        Uk = 0;
    }
};

void input_parameters(double& a, double& b, double& c, double& d, bool is_nonlinearModel) {
    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;
    if (is_nonlinearModel) {
        cout << "Enter c: "; cin >> c;
        cout << "Enter d: "; cin >> d;
    }
}

int main() {
    const double w = 10;
    const double y0 = 5;
    const double a = 0.21;
    const double b = 0.64;
    const double c = 0.80;
    const double d = 0.07;
    Model linear_model{ a, b, true };
    Model nonlinear_model{ a, b, c, d, false };
    PID_Regulator pid_regulator;

    cout << "Not Linear mode" << endl;
    pid_regulator.regulator(w, y0, nonlinear_model);
    cout << "Linear mode" << endl;
    pid_regulator.regulator(w, y0, linear_model);

    return 0;
}
Вывод:
Not Linear mode
E = 5, Yt = 1.53, Uk = 0.6
E = 8.47, Yt = -12.1774, Uk = 3.4164
E = 22.1774, Yt = -7.58749, Uk = 9.22688
E = 17.5875, Yt = 0.656266, Uk = 19.4906
E = 9.34373, Yt = 7.0014, Uk = 27.3869
E = 2.9986, Yt = 10.2741, Uk = 31.4622
E = -0.274078, Yt = 11.2098, Uk = 32.6957
E = -1.20982, Yt = 11.1265, Uk = 32.5119
E = -1.12654, Yt = 10.6608, Uk = 31.9357
E = -0.660775, Yt = 10.226, Uk = 31.4266
Linear mode
E = 5, Yt = 1.434, Uk = 0.6
E = 8.566, Yt = 3.24387, Uk = 3.42792
E = 6.75613, Yt = 5.80035, Uk = 7.42242
E = 4.19965, Yt = 7.78914, Uk = 10.5299
E = 2.21086, Yt = 9.01301, Uk = 12.4422
E = 0.98699, Yt = 9.65195, Uk = 13.4405
E = 0.348051, Yt = 9.93438, Uk = 13.8818
E = 0.0656189, Yt = 10.0322, Uk = 14.0348
E = -0.032245, Yt = 10.0493, Uk = 14.0615
E = -0.0493422, Yt = 10.039, Uk = 14.0453

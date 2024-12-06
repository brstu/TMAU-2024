<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">По дисциплине “Теория и методы автоматического управления”</p>
<p align="center">Тема: “Modeling controlled object”</p>
<br><br><br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-63</p>
<p align="right">Колодич М.П.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br><br><br>
<p align="center">Брест-2024</p>

---

**Задание**:

We want to simulate the modeling controlled object described by the following differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where:
- $\tau$ represents time,
- $y(\tau)$ is the numbers of the object,
- $u(\tau)$ is the input numbers,
- $Y_0$ is the numbers,
- $C$ and $RC$ are constants.

After transforming the equation, we arrive at two models: a linear model (2) and a nonlinear model (3):

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)

$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ denotes discrete time steps ($1, 2, 3, \ldots, n$) and $a, b, c, d$ are constants.

Your task is to write a C++ program that simulates the modeling controlled object.

Пример вывода программы:

``` bash
Введите константу a: 15
Введите константу b: 6
Введите константу c: 78
Введите константу d: 7
Введите подаваемое число: 45
Введите число: 4
Введите количество тактов работы : 8
        ---Линейна модель---
y1 = 12.1
y2 = 8.15
y3 = 4.3
y4 = 2.73
y5 = 3.005
        ---Нелинейная модель---
y1 = -50.001
y2 = -11.2665
y3 = -1.2654
y4 = 0.66035
y5 = 1.9354
```

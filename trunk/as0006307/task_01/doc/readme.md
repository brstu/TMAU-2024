<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">По дисциплине “Теория и методы автоматического управления”</p>
<<<<<<< Updated upstream
<p align="center">Тема: “Моделирования объекта управления”</p>
=======
<p align="center">Тема: “Modeling controlled object”</p>
>>>>>>> Stashed changes
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
- $y(\tau)$ is the number of the object,
- $u(\tau)$ is the input number,
- $Y_0$ is the number,
- $C$ and $RC$ are constants.

After transforming the equation, we arrive at two models: a linear model (2) and a nonlinear model (3):

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)

$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ denotes discrete time steps ($1, 2, 3, \ldots, n$) and $a, b, c, d$ are constants.

Your task is to write a C++ program that simulates the modeling controlled object.
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
Пример вывода программы:

``` bash
Введите константу a: 0.5
Введите константу b: 0.1
<<<<<<< Updated upstream
Введите константу c: 0.05
Введите константу d: 0.01
Введите подаваемое число: 17
Введите число   : 25
Введите количество тактов работы: 6
        ---Линейна температурная модель---
y1 = 13.1
y2 = 7.16
y3 = 4.2
y4 = 2.73
y5 = 2.005
        ---Нелинейная температурная модель---
y1 = -49.7076
y2 = -10.3088
y3 = -1.23838
y4 = 0.650169
y5 = 0.939878
=======
Введите константу c: 0.04
Введите константу d: 0.02
Введите подаваемое число: 17
Введите число: 24
Введите количество тактов работы: 4
        ---Линейна модель---
y1 = 13.2
y2 = 79.1
y3 = 1.45
y4 = 2.96
y5 = 2.0001
        ---Нелинейная модель---
y1 = -50.005
y2 = -11.006
y3 = -1.23547
y4 = 0.0654
y5 = 0.94568
>>>>>>> Stashed changes
```

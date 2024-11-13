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
<p align="right">Колодич М.П.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br><br><br>
<p align="center">Брест-2024</p>

---

**Задание**:

We want to simulate the temperature control of an object described by the following differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where:
- $\tau$ represents time,
- $y(\tau)$ is the temperature of the object,
- $u(\tau)$ is the input heat,
- $Y_0$ is the ambient room temperature,
- $C$ and $RC$ are constants.

After transforming the equation, we arrive at two models: a linear model (2) and a nonlinear model (3):

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)

$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ denotes discrete time steps ($1, 2, 3, \ldots, n$) and $a, b, c, d$ are constants.

Your task is to write a C++ program that simulates the temperature of this object.

Пример вывода программы:

``` bash
Введите константу a: 1
Введите константу b: 2
Введите константу c: 3
Введите константу d: 4
Введите подаваемое тепло: 10
Введите температуру: 5
Введите количество тактов работы модели: 5
        ---Линейна температурная модель---
y1 = 25
y2 = 45
y3 = 65
y4 = 85
y5 = 105
        ---Нелинейная температурная модель---
y1 = 35
y2 = 12.8239
y3 = -2409.35
y4 = -2710.43
y5 = -1.16126e+07
```

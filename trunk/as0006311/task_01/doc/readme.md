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
<p align="right">Крагель А. М.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2024</p>

---

**Задание**:

Let's consider the wrong object, the control of which consists of controlling its temperature, described by the following differential equations:

After transformations we have the following linear (2) and nonlinear (3) models:

The goal is to write a program in C++ that will simulate the temperature of a given object.

Пример вывода программы:

``` bash
Enter the constant alpha for the model: 0.08
Enter the constant beta for the linear model: 0.06
Enter the constant gamma for the nonlinear model: 0.02
Enter the constant delta for the nonlinear model: 0.01
Enter the initial temperature (initialTemp): 20
Enter the number of discrete time moments: 5
Enter the heat values (heatInput) for each time moment:
heatInput[1]: 10
heatInput[2]: 15
heatInput[3]: 20
heatInput[4]: 25
heatInput[5]: 30

Linear Model Simulation:
Time 1: Temperature = 20
Time 2: Temperature = 2.2
Time 3: Temperature = 1.076
Time 4: Temperature = 1.28608
Time 5: Temperature = 1.60289

Non-linear Model Simulation:
Time 1: Temperature = 20
Time 2: Temperature = -22.2054
Time 3: Temperature = -31.0548
Time 4: Temperature = -59.9394
Time 5: Temperature = -219.86
```

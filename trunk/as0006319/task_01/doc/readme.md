﻿<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">«Брестский Государственный технический университет»</p>       
<p align="center">Кафедра ИИТ</p>
<br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">Тема: моделирование управляемого объекта</p>
<br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3-го курса</p>
<p align="right">Группы АС-64</p>
<p align="right">Игнаткевич К.С.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br>
<p align="center">Брест 2024</p>

---


**Цель:** Моделирование температуры контролируемого объекта с использованием C++. Температура описывается дифференциальным уравнением, и мы реализуем как линейные, так и нелинейные дискретные модели, выведенные из этого уравнения.

Исходная функция:

dy(τ)/dτ = f(τ)/C + (Y₀ - y(τ))/RC


Программа выводит смоделированные значения температуры на каждом временном шаге для обеих моделей: линейной (1) и нелинейной (2).

y<sub>τ+1</sub> = ay<sub>τ</sub> + bu<sub>τ</sub> (1)

y<sub>τ+1</sub> = ay<sub>τ</sub> - by<sup>2</sup><sub>τ-1</sub> + cu<sub>τ</sub> + d * sin(u<sub>τ-1</sub>) (2)

Код программы находится в папке *src* под названием *laba1_ef.cpp*

Пример вывода (будет варьироваться в зависимости от параметров):
```markdown
Enter model coefficients (a, b, c, d):
3 2 1 2
Enter initial temperature: 5
Enter heat flow: 12
Enter number of steps: 5
Choose model (1 - linear, 2 - nonlinear): 1

Simulation results:
Step 0: Temperature = 5
Step 1: Temperature = 39
Step 2: Temperature = 141
Step 3: Temperature = 447
Step 4: Temperature = 1365
Step 5: Temperature = 4119


Enter model coefficients (a, b, c, d):
3 2 1 2
Enter initial temperature: 5
Enter heat flow: 12
Enter number of steps: 5
Choose model (1 - linear, 2 - nonlinear): 2

Simulation results:
Step 0: Temperature = 5
Step 1: Temperature = -24.0731
Step 2: Temperature = -1220.33
Step 3: Temperature = -2.98204e+06
Step 4: Temperature = -1.77851e+13
Step 5: Temperature = -6.3262e+26
```

**Вывод:** В ходе лабораторной работы были протестированы две модели: линейная и нелинейная. Линейная модель показала приемлемые результаты, с увеличением температуры на каждом шаге. Однако нелинейная модель выдала нестабильные результаты, что привело к некорректным значениям температуры, включая отрицательные и бесконечные. Это указывает на необходимость корректировки коэффициентов модели или метода решения для достижения более стабильных результатов.
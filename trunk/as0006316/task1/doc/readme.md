<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">«Брестский Государственный технический университет»</p>       
<p align="center">Кафедра ИИТ</p>
<br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">Тема: моделирование управляемого объекта</p>
<br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3-го курса</p>
<p align="right">Группы АС-63</p>
<p align="right">Мороз Е. В.</p>
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
Enter model coefficients (a, b, c, d): 1 4 3 5
Enter initial temperature: 10
Enter heat flow: 4
Enter number of steps: 4
Choose model (1 - linear, 2 - nonlinear): 1

Simulation results:
Step 0: Temperature = 10
Step 1: Temperature = 26
Step 2: Temperature = 42
Step 3: Temperature = 58
Step 4: Temperature = 74


Enter model coefficients (a, b, c, d): 1 4 3 5
Enter initial temperature: 10
Enter heat flow: 4
Enter number of steps: 4
Choose model (1 - linear, 2 - nonlinear): 2

Simulation results:
Step 0: Temperature = 10
Step 1: Temperature = -381.784
Step 2: Temperature = -583410
Step 3: Temperature = -1.36147e+12
Step 4: Temperature = -7.41438e+24
```

**Вывод:** В ходе лабораторной работы линейная модель показала стабильные результаты с увеличением температуры на каждом шаге, в то время как нелинейная модель выдала нестабильные значения, включая отрицательные и бесконечные. Это указывает на необходимость корректировки коэффициентов модели или методов решения для повышения стабильности.

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
<p align="right">Ярмолович А. С.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2024</p>

---

Задание

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation

$$Largefrac{dy(tau)}{dtau}=frac{u(tau)}{C}+frac{Y_0-y(tau)}{RC} $$ (1)

where $tau$ – time; $y(tau)$ – input temperature; $u(tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

After transformation we get these linear (2) and nonlinear (3) models

$$Large y_{tau+1}=ay_{tau}+bu_{tau}$$ (2)

$$Large y_{tau+1}=ay_{tau}-by_{tau-1}^2+cu_{tau}+dsin(u_{tau-1})$$ (3)

where $tau$ – time discrete moments ($1,2,3{dots}n$); $a,b,c,d$ – some constants.

Task is to write program (С++), which simulates this object temperature.

Пример вывода программы

``` bash
Enter the constant a for the model 0.07
Enter the constant b for the linear model 0.02
Enter the constant c for the nonlinear model 0.011
Enter the constant d for the nonlinear model 0.06
Enter the initial temperature (y0) 25
Enter the number of discrete time moments 7
Enter the heat values (u) for each time moment
u[1] 10 
u[2] 15
u[3] 20
u[4] 25
u[5] 30
u[6] 35
u[7] 40

Linear Model Simulation:
Time 1: Temperature = 25
Time 2: Temperature = 1.95
Time 3: Temperature = 0.4365
Time 4: Temperature = 0.430555
Time 5: Temperature = 0.530139
Time 6: Temperature = 0.63711
Time 7: Temperature = 0.744598

Non-linear Model Simulation:
Time 1: Temperature = 25
Time 2: Temperature = -10.6726
Time 3: Temperature = -2.82117
Time 4: Temperature = -0.0818857
Time 5: Temperature = 0.261193
Time 6: Temperature = 0.287637
Time 7: Temperature = 0.377789
```

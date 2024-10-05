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

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

After transformation we get these linear (2) and nonlinear (3) models:

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)

$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ – time discrete moments ($1,2,3{\dots}n$); $a,b,c,d$ – some constants.

Task is to write program (**С++**), which simulates this object temperature.

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

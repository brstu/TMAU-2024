
p align=center Министерство образования Республики Беларусьp
p align=centerУчреждение образованияp
p align=center“Брестский Государственный технический университет”p
p align=centerКафедра ИИТp
brbrbrbrbrbrbr
p align=centerЛабораторная работа №1p
p align=centerПо дисциплине “Теория и методы автоматического управления”p
p align=centerТема “Моделирования температуры объекта”p
brbrbrbrbr
p align=rightВыполнилp
p align=rightСтудент 3 курсаp
p align=rightГруппы АС-63p
p align=rightЯрмолович А.С.p
p align=rightПроверилаp
p align=rightСитковец Я. С.p
brbrbrbrbr
p align=centerБрест 2024p

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
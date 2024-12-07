
<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный Технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">По дисциплине “Теория и методы автоматического управления”</p>
<p align="center">Тема: “Моделирования температуры объекта”</p>
<br><br><br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-63</p>
<p align="right">Ващук А. В.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2024</p>

---

**Задание**:

The rate of change of temperature with respect to time depends on the input heat, the room temperature, and certain constants that characterize the system's behavior. After some transformations, we obtain both linear and nonlinear models:

The linear model expresses the next temperature value as a function of the current temperature and input heat, along with system constants.
The nonlinear model adds complexity by including terms that account for more intricate dependencies on the previous temperature and input heat, incorporating non-linearities like squared terms and trigonometric functions.
The goal is to use these models to control the temperature over discrete time intervals.

Пример вывода программы:

``` bash
Enter the constant a for the model: 0.08
Enter the constant b for the linear model: 0.02
Enter the constant c for the nonlinear model: 0.01
Enter the constant d for the nonlinear model: 0.05
Enter the initial temperature (y0): 20
Enter the number of discrete time moments: 10
Enter the heat values (u) for each time moment:
u[1]: 10 
u[2]: 15
u[3]: 20
u[4]: 25
u[5]: 30
u[6]: 35
u[7]: 40
u[8]: 45
u[9]: 50
u[10]: 55

Linear Model Simulation:
Time 1: Temperature = 20
Time 2: Temperature = 1.8
Time 3: Temperature = 0.444
Time 4: Temperature = 0.43552
Time 5: Temperature = 0.534842
Time 6: Temperature = 0.642787
Time 7: Temperature = 0.751423
Time 8: Temperature = 0.860114
Time 9: Temperature = 0.968809
Time 10: Temperature = 1.0775

Non-linear Model Simulation:
Time 1: Temperature = 20
Time 2: Temperature = -6.3272
Time 3: Temperature = -1.12433
Time 4: Temperature = 0.130418
Time 5: Temperature = 0.253476
Time 6: Temperature = 0.269591
Time 7: Temperature = 0.348705
Time 8: Temperature = 0.46272
Time 9: Temperature = 0.525281
Time 10: Temperature = 0.523385
```

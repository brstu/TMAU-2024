
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
<p align="right">Тунчик А.Д.</p>
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
Введите коэффициент A для модели: 0.02
Введите коэффициент B для линейной модели: 0.06
Введите коэффициент C для нелинейной модели: 0.03
Введите коэффициент D для нелинейной модели: 0.01
Введите начальную температуру: 20
Введите количество временных моментов: 5
Введите теплоемкость (u) на каждый временной момент:
u[1]: 1
u[2]: 2
u[3]: 3
u[4]: 4
u[5]: 5

Линейная модель:
Время 1: Температура = 20
Время 2: Температура = 0.46
Время 3: Температура = 0.1292
Время 4: Температура = 0.182584
Время 5: Температура = 0.243652

Нелинейная модель:
Время 1: Температура = 20
Время 2: Температура = -23.5616
Время 3: Температура = -33.711
Время 4: Температура = -68.7688
Время 5: Температура = -285.012
```

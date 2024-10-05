# Лабораторная работа №1              
<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">«Брестский государственный технический университет»</p>       
<p align="center">Кафедра ИИТ</p>
<br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">По дисциплине: «ТИМАУ»</p>
<br><br><br>
<p align="right">Выполнил</p> 
<p align="right">Студент 3-го курса</p>
<p align="right">Группы АС-64</p>
<p align="right">Горкавчук Н.М.</p>
<p align="right">Проверил</p>
<p align="right">Иванюк Д.С.</p>
<br><br><br>
<p align="center">Брест 2024</p>

---

## Task 1. Modeling controlled object:
 
Написать программу на C++, которая симулирует температуру.

### Реализация
Расчеты температуры проводились благодаря двум моделям

1. Линейная: $$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$
2. Ниленейная: $$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$

#### Результат:
```console 
Step 1: Linear y = 13.1, Nonlinear y = -49.7076
Step 2: Linear y = 7.16, Nonlinear y = -10.3088
Step 3: Linear y = 4.2, Nonlinear y = -1.23838
Step 4: Linear y = 2.73, Nonlinear y = 0.650169
Step 5: Linear y = 2.005, Nonlinear y = 0.939878
Step 6: Linear y = 1.6525, Nonlinear y = 0.926663
Step 7: Linear y = 1.48625, Nonlinear y = 0.885326
Step 8: Linear y = 1.41312, Nonlinear y = 0.860347
Step 9: Linear y = 1.38656, Nonlinear y = 0.850919
Step 10: Linear y = 1.38328, Nonlinear y = 0.850967
Step 11: Linear y = 1.39164, Nonlinear y = 0.856078
Step 12: Linear y = 1.40582, Nonlinear y = 0.863724
Step 13: Linear y = 1.42291, Nonlinear y = 0.872567
Step 14: Linear y = 1.44146, Nonlinear y = 0.881924
Step 15: Linear y = 1.46073, Nonlinear y = 0.891453
Step 16: Linear y = 1.48036, Nonlinear y = 0.900978
Step 17: Linear y = 1.50018, Nonlinear y = 0.910414
```

### Как запускать проект

1. Для начала требуется сделать git clone репозитория
2. Перейти в папку "trunk\as64-220038\task_01\src".
3. Запустить в терминале ниже приведенные комманды

```console 
mkdir build
cd build
cmake ..
make
./as64_lab1
```




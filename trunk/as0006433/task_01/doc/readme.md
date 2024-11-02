# Лабораторная работа №1              
<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">«Брестский государственный технический университет»</p>       
<p align="center">Кафедра ИИТ</p>
<br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">По дисциплине: «ТИМАУ»</p>
<br><br><br>
<p align="right">Выполнила</p> 
<p align="right">Студентка 3-го курса</p>
<p align="right">Группы АС-64</p>
<p align="right">Будник А.А.</p>
<p align="right">Проверил</p>
<p align="right">Иванюк Д.С.</p>
<br><br><br>
<p align="center">Брест 2024</p>

---

## Task 1. Modeling controlled object:
 
Написать программу на C++, которая симулирует температуру.

### Реализация
Расчеты температуры проводились благодаря двум представленным моделям

1. Линейная: $$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$
2. Ниленейная: $$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$

#### Результат:
```console 
Step 1: Temperature = 12.5
Step 2: Temperature = 7.75
Step 3: Temperature = 5.375
Step 4: Temperature = 4.1875
Step 5: Temperature = 3.59375
Step 6: Temperature = 3.29688
Step 7: Temperature = 3.14844
Step 8: Temperature = 3.07422
Step 9: Temperature = 3.03711
Step 10: Temperature = 3.01855
```

### Метод запуска проекта

1. Создать git clone репозитория
2. Перейти к папке "trunk\as006433\task_01\src".
3. Выполнить запуск приведенных команд ниже в терминале 

```console 
mkdir build 
cd build 
cmake .. 
cmake --build . 
./lab1
```




<p align="center">Министерство Образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">«Брестский Государственный Технический Университет»</p>       
<p align="center">Кафедра ИИТ</p>
<br><br><br><br>
<p align="center">Лабораторная работа №2</p>
<br><br><br>
<p align="right">Выполнил студент 3 курса</p> 
<p align="right">Факультета Электронных Информационных Систем</p>
<p align="right">Группы АС-63 Мороз Е. В.</p>
<p align="right">Проверила Ситковец Я. С.</p>
<br><br><br>
<p align="center">Брест 2024</p>

------------------------------------------------------
## Введение

Цель данной лабораторной работы заключалась в изучении возможностей использования систем контроля версий Git и платформы GitHub для управления кодом и совместной работы над проектами. Мы также ознакомились с инструментом Doxygen, который позволяет создавать документацию для программного кода, и научились оформлять её в формате Markdown.

## Цели и задачи

1. **Изучение Git и GitHub**:
   - Создание репозиториев.
   - Работа с ветками.
   - Коммит изменений и отслеживание истории.
   - Объединение изменений из разных веток.

2. **Изучение Doxygen**:
   - Оформление документации.
   - Использование комментариев для описания функций и классов.
   - Применение директив Doxygen для автоматизации документирования.

## Ход работы

### Задача 2: Моделирование ПИД-регулятора

В рамках этой задачи была реализована программа на языке C++, которая моделирует ПИД-регулятор. Мы использовали объектно-ориентированные принципы и создали три класса с наследованием.

#### Установленные параметры для ПИД-регулятора:
- **K** = 0.1
- **T** = 10
- **TD** = 80
- **T0** = 50

### Результат выполнения программы

В результате работы программы были получены следующие данные:</p>

```console
------
---Please enter parameters for the linear model---
Enter parameter a: 1
Enter parameter b: 1
---Please enter parameters for the nonlinear model---
Enter parameter c: 1
Enter parameter d: 3
Enter parameter a: 4
Enter parameter b: 2
        ---Nonlinear Model---
Error = 5, Current Temp = 13.3, Control Signal = 1.3
Error = -5.3, Current Temp = 38.4127, Control Signal = 0.322
Error = -30.4127, Current Temp = -206.389, Control Signal = -7.2093
Error = 214.389, Current Temp = -3733.77, Control Signal = 45.2509
Error = 3741.77, Current Temp = -99094.8, Control Signal = 1030.4
Error = 99102.8, Current Temp = -2.82513e+07, Control Signal = 27130.8
Error = 2.82513e+07, Current Temp = -1.97452e+10, Control Signal = 7.38101e+06
Error = 1.97452e+10, Current Temp = -1.59635e+15, Control Signal = 5.14341e+09
Error = 1.59635e+15, Current Temp = -7.79751e+20, Control Signal = 4.15058e+14
Error = 7.79751e+20, Current Temp = -5.09667e+30, Control Signal = 2.02736e+20
Error = 5.09667e+30, Current Temp = -1.21602e+42, Control Signal = 1.32513e+30
Error = 1.21602e+42, Current Temp = -5.1952e+61, Control Signal = 3.16166e+41
Error = 5.1952e+61, Current Temp = -2.95743e+84, Control Signal = 1.35075e+61
Error = 2.95743e+84, Current Temp = -5.39803e+123, Control Signal = 7.68932e+83
Error = 5.39803e+123, Current Temp = -1.74928e+169, Control Signal = 1.40349e+123
Error = 1.74928e+169, Current Temp = -5.82775e+247, Control Signal = 4.54813e+168
Error = 5.82775e+247, Current Temp = -inf, Control Signal = 1.51521e+247
Error = inf, Current Temp = -nan(ind), Control Signal = inf
Error = -nan(ind), Current Temp = -nan(ind), Control Signal = -nan(ind)
Error = -nan(ind), Current Temp = -nan(ind), Control Signal = -nan(ind)
Error = -nan(ind), Current Temp = -nan(ind), Control Signal = -nan(ind)
Error = -nan(ind), Current Temp = -nan(ind), Control Signal = -nan(ind)
Error = -nan(ind), Current Temp = -nan(ind), Control Signal = -nan(ind)
Error = -nan(ind), Current Temp = -nan(ind), Control Signal = -nan(ind)
Error = -nan(ind), Current Temp = -nan(ind), Control Signal = -nan(ind)
Error = -nan(ind), Current Temp = -nan(ind), Control Signal = -nan(ind)
Error = -nan(ind), Current Temp = -nan(ind), Control Signal = -nan(ind)
Error = -nan(ind), Current Temp = -nan(ind), Control Signal = -nan(ind)
Error = -nan(ind), Current Temp = -nan(ind), Control Signal = -nan(ind)
Error = -nan(ind), Current Temp = -nan(ind), Control Signal = -nan(ind)
        ---Linear Model---
Error = 5, Current Temp = 4.3, Control Signal = 1.3
Error = 3.7, Current Temp = 6.962, Control Signal = 2.662
Error = 1.038, Current Temp = 10.9899, Control Signal = 4.02788
Error = -2.98988, Current Temp = 14.9154, Control Signal = 3.92555
Error = -6.91543, Current Temp = 16.9699, Control Signal = 2.05443
Error = -8.96986, Current Temp = 15.6605, Control Signal = -1.30935
Error = -7.66051, Current Temp = 10.5354, Control Signal = -5.12514
Error = -2.53537, Current Temp = 2.70301, Control Signal = -7.83235
Error = 5.29699, Current Temp = -5.18064, Control Signal = -7.88365
Error = 13.1806, Current Temp = -9.61922, Control Signal = -4.43858
Error = 17.6192, Current Temp = -7.57484, Control Signal = 2.04438
Error = 15.5748, Current Temp = 2.03744, Control Signal = 9.61228
Error = 5.96256, Current Temp = 17.265, Control Signal = 15.2276
Error = -9.26505, Current Temp = 33.0527, Control Signal = 15.7877
Error = -25.0527, Current Temp = 42.5395, Control Signal = 9.48677
Error = -34.5395, Current Temp = 39.5594, Control Signal = -2.98012
Error = -31.5594, Current Temp = 21.6022, Control Signal = -17.9572
Error = -13.6022, Current Temp = -7.94258, Control Signal = -29.5448
Error = 15.9426, Current Temp = -39.48, Control Signal = -31.5374
Error = 47.48, Current Temp = -59.5735, Control Signal = -20.0936
Error = 67.5735, Current Temp = -55.7488, Control Signal = 3.82477
Error = 63.7488, Current Temp = -22.3466, Control Signal = 33.4021
Error = 30.3466, Current Temp = 34.8573, Control Signal = 57.2039
Error = -26.8573, Current Temp = 97.7059, Control Signal = 62.8486
Error = -89.7059, Current Temp = 139.938, Control Signal = 42.2319
Error = -131.938, Current Temp = 136.392, Control Signal = -3.54554
Error = -128.392, Current Temp = 74.5568, Control Signal = -61.8355
Error = -66.5568, Current Temp = -35.9649, Control Signal = -110.522
Error = 43.9649, Current Temp = -160.923, Control Signal = -124.958
Error = 168.923, Current Temp = -249.093, Control Signal = -88.17
------------------------------------------------------
Вывод: в ходе выполнения лабораторной работы были освоены навыки работы с Git и GitHub, что значительно упростило процесс совместной работы над проектами. Также был получен ценный опыт в использовании Doxygen для документирования кода, что позволит в будущем создавать качественную и понятную документацию.


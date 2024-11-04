# Laboratory work №.2    
<p align="center">MINISTRY OF EDUCATION OF THE REPUBLIC OF BELARUS</p>
<p align="center">EDUCATIONAL INSTITUTION</p>
<p align="center">«BREST STATE TECHNICAL UNIVERSITY»</p>       
<p align="center">Department of IIT</p>
<br><br><br><br>
<p align="center">Laboratory work №.2 </p>
<br><br><br>
<p align="right">Completed by the 3rd year student of</p> 
<p align="right">the Faculty of Electronic Information Systems</p>
<p align="right">the group AC-63 Kukharchuk I.N.</p>
<p align="right">Checked by Ivanuk D.S.</p>
<br><br><br>
<p align="center">Brest 2024</p>

---

------------------------------------------------------
Цель работы: Целью данной лабораторной работы является изучение возможностей использования Git и GitHub для управления версиями кода и совместной работы над проектами. В ходе работы будет изучено, как создавать репозитории на GitHub, работать с ветками, коммитить изменения, отслеживать историю изменений, объединять изменения из разных веток, а также как использовать различные инструменты для упрощения совместной работы над проектом.
Целью данной лабораторной работы является изучение возможностей использования инструмента Doxygen для документирования кода программного обеспечения. В ходе работы будет изучено, как правильно оформлять документацию, какие разделы должны быть включены в документацию, как использовать комментарии в коде для документирования функций и классов, а также как использовать специальные директивы Doxygen для упрощения оформления документации.
------------------------------------------------------
Ход работы:
------------------------------------------------------


## Task 2. PID-regulators :
------------------------------------------------------
На языке C++ реализовать программу, моделирующую рассматриваемый ПИД-регулятор. В качестве объекта управления используйте математическую модель, полученную в предыдущей задаче. Используйте ООП, в программе должно быть минимум 3 класса (+наследование). Приведите графики для разных параметров температуры объекта, поясните результаты (отчет получен с помощью Doxygen в формате .md).
------------------------------------------------------
### Реализация
В программе реализовано 4 класса:
1. Model это абстрактная модель. 
2. LinearModel представляет линейную модель.
3. NonlinearModel представляет нелинейную модель.
4. PIDregulator.
------------------------------------------------------





The following values were set for the PID-regulator: __K = 0.1 , T = 10, TD = 80, T0 = 50__ 

<p align="center" style="font-size:25px;font-weight: bold">
Результат выполнения программы</p>

```console
--- Parameters for Linear Model ---
Enter parameter 1: 5
Enter parameter 2: 2
--- Parameters for Nonlinear Model ---
Enter parameter 1: 11
Enter parameter 2: 9
Enter parameter 3: 2
Enter parameter 4: 4

--- Linear Model Simulation ---
Step 1 -> Error: 5, Temp: 17.6, Control Signal: 1.3
Step 2 -> Error: -9.6, Temp: 13.408, Control Signal: -0.796
Step 3 -> Error: -5.408, Temp: 10.6598, Control Signal: -2.17008
Step 4 -> Error: -2.65984, Temp: 5.33944, Control Signal: -4.83028
Step 5 -> Error: 2.66056, Temp: 4.5668, Control Signal: -5.2166
Step 6 -> Error: 3.4332, Temp: 5.9266, Control Signal: -4.5367
Step 7 -> Error: 2.0734, Temp: 8.40546, Control Signal: -3.29727
Step 8 -> Error: -0.40546, Temp: 9.62499, Control Signal: -2.68751
Step 9 -> Error: -1.62499, Temp: 9.37861, Control Signal: -2.8107
Step 10 -> Error: -1.37861, Temp: 8.27199, Control Signal: -3.36401
Step 11 -> Error: -0.271986, Temp: 7.38998, Control Signal: -3.80501
Step 12 -> Error: 0.61002, Temp: 7.22252, Control Signal: -3.88874
Step 13 -> Error: 0.777482, Temp: 7.63738, Control Signal: -3.68131
Step 14 -> Error: 0.362624, Temp: 8.14554, Control Signal: -3.42723
Step 15 -> Error: -0.145544, Temp: 8.37668, Control Signal: -3.31166
Step 16 -> Error: -0.376675, Temp: 8.27356, Control Signal: -3.36322
Step 17 -> Error: -0.273557, Temp: 8.02447, Control Signal: -3.48777
Step 18 -> Error: -0.024465, Temp: 7.84744, Control Signal: -3.57628
Step 19 -> Error: 0.152562, Temp: 7.83532, Control Signal: -3.58234
Step 20 -> Error: 0.164682, Temp: 7.93753, Control Signal: -3.53123
Step 21 -> Error: 0.0624664, Temp: 8.04519, Control Signal: -3.47741
Step 22 -> Error: -0.0451851, Temp: 8.08438, Control Signal: -3.45781
Step 23 -> Error: -0.0843818, Temp: 8.05326, Control Signal: -3.47337
Step 24 -> Error: -0.0532629, Temp: 7.99761, Control Signal: -3.5012
Step 25 -> Error: 0.00239414, Temp: 7.96333, Control Signal: -3.51834
Step 26 -> Error: 0.0366734, Temp: 7.96574, Control Signal: -3.51713
Step 27 -> Error: 0.0342643, Temp: 7.99019, Control Signal: -3.50491
Step 28 -> Error: 0.00981299, Temp: 8.01251, Control Signal: -3.49375
Step 29 -> Error: -0.0125075, Temp: 8.01854, Control Signal: -3.49073
Step 30 -> Error: -0.0185383, Temp: 8.01004, Control Signal: -3.49498

--- Nonlinear Model Simulation ---
Step 1 -> Error: 5, Temp: 35.6, Control Signal: 1.3
Step 2 -> Error: -27.6, Temp: -55.0978, Control Signal: -5.476
Step 3 -> Error: 63.0978, Temp: -26.0678, Control Signal: 9.52142
Step 4 -> Error: 34.0678, Temp: -10.3642, Control Signal: 19.0109
Step 5 -> Error: 18.3642, Temp: 25.8557, Control Signal: 36.6066
Step 6 -> Error: -17.8557, Temp: 26.2172, Control Signal: 38.8841
Step 7 -> Error: -18.2172, Temp: 27.021, Control Signal: 35.6575
Step 8 -> Error: -19.021, Temp: 1.23071, Control Signal: 26.3977
Step 9 -> Error: 6.76929, Temp: 3.25708, Control Signal: 23.7213
Step 10 -> Error: 4.74292, Temp: -7.04397, Control Signal: 22.4527
Step 11 -> Error: 15.044, Temp: 5.872, Control Signal: 27.8266
Step 12 -> Error: 2.128, Temp: 14.4162, Control Signal: 30.3423
Step 13 -> Error: -6.41619, Temp: 10.9869, Control Signal: 31.2513
Step 14 -> Error: -2.98692, Temp: 11.9485, Control Signal: 30.3019
Step 15 -> Error: -3.94852, Temp: 4.42968, Control Signal: 28.0098
Step 16 -> Error: 3.57032, Temp: 9.33448, Control Signal: 28.1443
Step 17 -> Error: -1.33448, Temp: 7.42113, Control Signal: 27.4512
Step 18 -> Error: 0.578868, Temp: 11.0655, Control Signal: 28.0662
Step 19 -> Error: -3.06555, Temp: 7.03051, Control Signal: 27.1019
Step 20 -> Error: 0.969491, Temp: 10.0895, Control Signal: 27.2014
Step 21 -> Error: -2.08948, Temp: 8.00483, Control Signal: 26.2452
Step 22 -> Error: -0.00483079, Temp: 8.05083, Control Signal: 26.2319
Step 23 -> Error: -0.0508326, Temp: 7.33114, Control Signal: 25.8839
Step 24 -> Error: 0.668857, Temp: 6.83611, Control Signal: 26.053
Step 25 -> Error: 1.16389, Temp: 7.98506, Control Signal: 26.401
Step 26 -> Error: 0.0149402, Temp: 9.02836, Control Signal: 26.605
Step 27 -> Error: -1.02836, Temp: 9.03071, Control Signal: 26.5251
Step 28 -> Error: -1.03071, Temp: 8.29084, Control Signal: 26.1772
Step 29 -> Error: -0.290844, Temp: 7.16776, Control Signal: 25.8546
Step 30 -> Error: 0.832244, Temp: 6.40863, Control Signal: 25.8828

D:\PROGRAMMING\2024\c++\ConsoleApplication1\x64\Debug\ConsoleApplication1.exe (process 22424) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

------------------------------------------------------
Вывод: В ходе выполнения лабораторной работы, были получены навыки в работе с гитхабом, незаменимый опыт работы с Doxygen и его переводчиком на язык .md Moxygen.

<p align="center" style="font-size:25px;font-weight: bold">

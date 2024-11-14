                        Ministry of Education of the Republic of Belarus

                                        Educational Institution

                                 “Brest State Technical University”

                        Department of Information and Intelligent Technologies



                                          Laboratory work №2

                        On the discipline “Theory and methods of automatic control”

                                Topic: "PID-Regulator"



                                                                Performed by:

                                                                Student of the 3rd course

                                                                Group AS-64

                                                                YARMALIUK A. S.

                                                                Supervised by:

                                                                Sitkovets J. S.


                                             Brest 2024

---

## Task:

- На C++ реализовать программу, моделирующую рассмотренный выше ПИД-регулятор. В качестве объекта управления использовать математическую модель, полученную в предыдущей работе. Использовать ООП, в программе должно быть не менее 3-х классов (+наследование).
- Написать отчет по выполненной лабораторной работе №2 в .md формате (readme.md) и с помощью pull request разместить его в следующем каталоге: trunk\as000xxyy\task_02\doc. В отчете также привести графики для разных заданий температуры объекта, пояснить полученные результаты.
- В отчет с помощью Doxygen (в .md формате) добавить информацию о разработанной программе (диаграмма классов и т.п.).
- Исходный код написанной программы разместить в каталоге: trunk\as000xxyy\task_02\src.

```
---Input parameters for SimpleModel---
Enter parameter a: 0.99
Enter parameter b: 0.09
---Input parameters for ComplexModel---
Enter parameter a: 0.99
Enter parameter b: 0.001
Enter parameter c: 0.09
Enter parameter d: 0.01
	---Simulation with SimpleModel---
Error = 5, Current Temp = 3.087, Control Output = 1.3
Error = 4.913, Current Temp = 3.23796, Control Output = 2.97738
Error = 4.76204, Current Temp = 3.45677, Control Output = 5.40855
Error = 4.54323, Current Temp = 3.66811, Control Output = 7.75683
Error = 4.33189, Current Temp = 3.87077, Control Output = 10.0085
Error = 4.12923, Current Temp = 4.064, Control Output = 12.1556
Error = 3.936, Current Temp = 4.24821, Control Output = 14.2024
Error = 3.75179, Current Temp = 4.42381, Control Output = 16.1534
Error = 3.57619, Current Temp = 4.59118, Control Output = 18.0131
Error = 3.40882, Current Temp = 4.75072, Control Output = 19.7858
Error = 3.24928, Current Temp = 4.90279, Control Output = 21.4755
Error = 3.09721, Current Temp = 5.04775, Control Output = 23.0861
Error = 2.95225, Current Temp = 5.18592, Control Output = 24.6214
Error = 2.81408, Current Temp = 5.31763, Control Output = 26.0848
Error = 2.68237, Current Temp = 5.44317, Control Output = 27.4797
Error = 2.55683, Current Temp = 5.56284, Control Output = 28.8093
Error = 2.43716, Current Temp = 5.6769, Control Output = 30.0767
Error = 2.3231, Current Temp = 5.78563, Control Output = 31.2847
Error = 2.21437, Current Temp = 5.88926, Control Output = 32.4363
Error = 2.11074, Current Temp = 5.98805, Control Output = 33.5339
Error = 2.01195, Current Temp = 6.08222, Control Output = 34.5802
Error = 1.91778, Current Temp = 6.17197, Control Output = 35.5775
Error = 1.82803, Current Temp = 6.25753, Control Output = 36.5281
Error = 1.74247, Current Temp = 6.33908, Control Output = 37.4342
Error = 1.66092, Current Temp = 6.41682, Control Output = 38.2979
Error = 1.58318, Current Temp = 6.49091, Control Output = 39.1212
Error = 1.50909, Current Temp = 6.56154, Control Output = 39.906
Error = 1.43846, Current Temp = 6.62886, Control Output = 40.654
Error = 1.37114, Current Temp = 6.69304, Control Output = 41.3671
Error = 1.30696, Current Temp = 6.75421, Control Output = 42.0467

	---Simulation with ComplexModel---
Error = 5, Current Temp = 3.087, Control Output = 1.3
Error = 4.913, Current Temp = 3.2386, Control Output = 2.97738
Error = 4.7614, Current Temp = 3.44939, Control Output = 5.40838
Error = 4.55061, Current Temp = 3.65159, Control Output = 7.75853
Error = 4.34841, Current Temp = 3.8723, Control Output = 10.015
Error = 4.1277, Current Temp = 4.05021, Control Output = 12.1642
Error = 3.94979, Current Temp = 4.23662, Control Output = 14.2171
Error = 3.76338, Current Temp = 4.42644, Control Output = 16.172
Error = 3.57356, Current Temp = 4.5796, Control Output = 18.0341
Error = 3.4204, Current Temp = 4.73675, Control Output = 19.8115
Error = 3.26325, Current Temp = 4.90468, Control Output = 21.5053
Error = 3.09532, Current Temp = 5.04633, Control Output = 23.1184
Error = 2.95367, Current Temp = 5.17102, Control Output = 24.6561
Error = 2.82898, Current Temp = 5.3075, Control Output = 26.1232
Error = 2.6925, Current Temp = 5.44636, Control Output = 27.5221
Error = 2.55364, Current Temp = 5.5647, Control Output = 28.8541
Error = 2.4353, Current Temp = 5.66654, Control Output = 30.1224
Error = 2.33346, Current Temp = 5.77131, Control Output = 31.3325
Error = 2.22869, Current Temp = 5.88411, Control Output = 32.4883
Error = 2.11589, Current Temp = 5.99289, Control Output = 33.5901
Error = 2.00711, Current Temp = 6.08663, Control Output = 34.6378
Error = 1.91337, Current Temp = 6.16729, Control Output = 35.6344
Error = 1.83271, Current Temp = 6.24485, Control Output = 36.5851
Error = 1.75515, Current Temp = 6.3265, Control Output = 37.4942
Error = 1.6735, Current Temp = 6.41163, Control Output = 38.3629
Error = 1.58837, Current Temp = 6.49432, Control Output = 39.1906
Error = 1.50568, Current Temp = 6.56889, Control Output = 39.9769
Error = 1.43111, Current Temp = 6.63373, Control Output = 40.7236
Error = 1.36627, Current Temp = 6.69125, Control Output = 41.4342
Error = 1.30875, Current Temp = 6.74556, Control Output = 42.1128
```

### The source code

The source code is located in the src folder.

    CMakeLists.txt - this is a file that contains CMake commands to control the project build process.
    main.cpp - source file, contains the main function that controls the program execution.

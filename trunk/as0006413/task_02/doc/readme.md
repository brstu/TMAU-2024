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

                                                                Kuzhyr U. V.

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
---Input parameters for LinearModel---
Enter parameter a: 0.95
Enter parameter b: 0.05

---Input parameters for NonlinearModel---
Enter parameter a: 0.95
Enter parameter b: 0.001
Enter parameter c: 0.05
Enter parameter d: 0.01

        ---Simulation with SimpleModel---
Error = 5, Current Temp = 2.915, Control Output = 1.3
Error = 5.085, Current Temp = 3.0011, Control Output = 3.0221    
Error = 4.9989, Current Temp = 3.12643, Control Output = 5.52861 
Error = 4.87357, Current Temp = 3.25046, Control Output = 8.00925
Error = 4.74954, Current Temp = 3.37169, Control Output = 10.4338
Error = 4.62831, Current Temp = 3.48985, Control Output = 12.7969
Error = 4.51015, Current Temp = 3.60499, Control Output = 15.0998
Error = 4.39501, Current Temp = 3.71719, Control Output = 17.3438
Error = 4.28281, Current Temp = 3.82653, Control Output = 19.5306
Error = 4.17347, Current Temp = 3.93307, Control Output = 21.6615
Error = 4.06693, Current Temp = 4.0369, Control Output = 23.738  
Error = 3.9631, Current Temp = 4.13808, Control Output = 25.7615 
Error = 3.86192, Current Temp = 4.23667, Control Output = 27.7334
Error = 3.76333, Current Temp = 4.33275, Control Output = 29.6549
Error = 3.66725, Current Temp = 4.42637, Control Output = 31.5274
Error = 3.57363, Current Temp = 4.5176, Control Output = 33.352
Error = 3.4824, Current Temp = 4.60651, Control Output = 35.1301
Error = 3.39349, Current Temp = 4.69314, Control Output = 36.8628
Error = 3.30686, Current Temp = 4.77756, Control Output = 38.5512
Error = 3.22244, Current Temp = 4.85983, Control Output = 40.1966
Error = 3.14017, Current Temp = 4.94, Control Output = 41.7999
Error = 3.06, Current Temp = 5.01812, Control Output = 43.3623
Error = 2.98188, Current Temp = 5.09424, Control Output = 44.8848
Error = 2.90576, Current Temp = 5.16842, Control Output = 46.3685
Error = 2.83158, Current Temp = 5.24071, Control Output = 47.8143
Error = 2.75929, Current Temp = 5.31116, Control Output = 49.2231
Error = 2.68884, Current Temp = 5.3798, Control Output = 50.596
Error = 2.6202, Current Temp = 5.44669, Control Output = 51.9339
Error = 2.55331, Current Temp = 5.51188, Control Output = 53.2375
Error = 2.48812, Current Temp = 5.5754, Control Output = 54.508

        ---Simulation with ComplexModel---
Error = 5, Current Temp = 2.915, Control Output = 1.3
Error = 5.085, Current Temp = 3.00174, Control Output = 3.0221
Error = 4.99826, Current Temp = 3.11861, Control Output = 5.52845
Error = 4.88139, Current Temp = 3.2347, Control Output = 8.01107
Error = 4.7653, Current Temp = 3.37289, Control Output = 10.4403
Error = 4.62711, Current Temp = 3.47278, Control Output = 12.8056
Error = 4.52722, Current Temp = 3.59913, Control Output = 15.1153
Error = 4.40087, Current Temp = 3.71469, Control Output = 17.362
Error = 4.28531, Current Temp = 3.80867, Control Output = 19.5526
Error = 4.19133, Current Temp = 3.93193, Control Output = 21.6893
Error = 4.06807, Current Temp = 4.03237, Control Output = 23.768
Error = 3.96763, Current Temp = 4.12099, Control Output = 25.7956
Error = 3.87901, Current Temp = 4.23578, Control Output = 27.7725
Error = 3.76422, Current Temp = 4.33063, Control Output = 29.6963
Error = 3.66937, Current Temp = 4.40972, Control Output = 31.5721
Error = 3.59028, Current Temp = 4.51263, Control Output = 33.4014
Error = 3.48737, Current Temp = 4.60928, Control Output = 35.1825
Error = 3.39072, Current Temp = 4.68102, Control Output = 36.9175
Error = 3.31898, Current Temp = 4.76444, Control Output = 38.6097
Error = 3.23556, Current Temp = 4.86185, Control Output = 40.2589
Error = 3.13815, Current Temp = 4.93973, Control Output = 41.8647
Error = 3.06027, Current Temp = 5.00392, Control Output = 43.4291
Error = 2.99608, Current Temp = 5.0835, Control Output = 44.9551
Error = 2.9165, Current Temp = 5.1714, Control Output = 46.4427
Error = 2.8286, Current Temp = 5.24184, Control Output = 47.8908
Error = 2.75816, Current Temp = 5.2991, Control Output = 49.3009
Error = 2.7009, Current Temp = 5.3666, Control Output = 50.6763
Error = 2.6334, Current Temp = 5.44591, Control Output = 52.0184
Error = 2.55409, Current Temp = 5.5171, Control Output = 53.3253
Error = 2.4829, Current Temp = 5.57164, Control Output = 54.5965
```

### The source code

The source code is located in the src folder.

    CMakeLists.txt - this is a file that contains CMake commands to control the project build process.
    main.cpp - source file, contains the main function that controls the program execution.

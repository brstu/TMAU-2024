                        Ministry of Education of the Republic of Belarus

                                        Educational Institution

                                 “Brest State Technical University”

                        Department of Information and Intelligent Technologies



                                          Laboratory work №1

                        On the discipline “Theory and methods of automatic control”

                                Topic: “Temperature modeling of an object”



                                                                Performed by:

                                                                Student of the 3rd course

                                                                Group AS-64

                                                                YARMALIUK A. S.

                                                                Supervised by:

                                                                Sitkovets J. S.


                                             Brest 2024

## Task:

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$$
\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC}(1)
$$

where τ – time; y ( τ ) – input temperature; u ( τ ) – input warm; Y 0 – room temperature; C , R C – some constants.

After transformation we get these linear (2) and nonlinear (3) models:

$$
\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}(2)
$$

$$
\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})(3)
$$

where τ – time discrete moments ( 1 , 2 , 3 … n ); a , b , c , d – some constants.

Task is to write program (С++), which simulates this object temperature.
Example of program output:

```
Choose an option (0 - exit, 1 - linear model, 2 - nonlinear model): Input choice: 1
Input A: 10
Input B: 3
Input current temperature: 35
Input heat input: 5
Input simulation time: 10
TIME      Linear Model
=========================
1         438
2         5238
3         62838
4         754038
5         9.04844e+06
6         1.08581e+08
7         1.30297e+09
8         1.56357e+10
9         1.87628e+11
10        2.25154e+12

Choose an option (0 - exit, 1 - linear model, 2 - nonlinear model): Input choice: 2
Input A: 4
Input B: 10
Input C: 25
Input D: 30
Input current temperature: 28
Input heat input: 40
Input simulation time: 20
TIME      Nonlinear Model
=========================
1         812.912
2         -7896.35
3         -9.7409e+06
4         -9.40969e+08
5         -1.42328e+15
6         -1.32856e+19
7         -3.03859e+31
8         -2.64761e+39

artyomyarmoluk@Artyoms-MacBook-Air uni/TMAU-2024/as006426/task_01/src> ./lab_01.exe

Choose an option (0 - exit, 1 - linear model, 2 - nonlinear model): Input choice: 1
Input A: 1.0
Input B: 0.6
Input current temperature: 26
Input heat input: 12
Input simulation time: 5
TIME      Linear Model
=========================
1         32.8
2         41.68
3         51.344
4         61.1175
5         71.8385

Choose an option (0 - exit, 1 - linear model, 2 - nonlinear model): Input choice: 2
Input A: 1.3
Input B: 0.2
Input C: 0.4
Input D: 0.1
Input current temperature: 32
Input heat input: 18
Input simulation time: 5
TIME      Nonlinear Model
=========================
1         42.5325
2         -37.9285
3         -210.95
4         -380.841
```

## Input erroe handling

```
Choose an option (0 - exit, 1 - linear model, 2 - nonlinear model): Input choice: p

*** Incorrect input ***
Input choice: 5
*** Invalid input ***
```

## Exit the program

```
Choose an option (0 - exit, 1 - linear model, 2 - nonlinear model): Input choice: 0
artyomyarmoluk@Artyoms-MacBook-Air uni/TMAU-2024trunk/as006426/task_01/src> ^C
```

The source code

The source code is located in the src folder.

    CMakeLists.txt - this is a file that contains CMake commands to control the project build process.
    main.cpp - source file, contains the main function that controls the program execution.

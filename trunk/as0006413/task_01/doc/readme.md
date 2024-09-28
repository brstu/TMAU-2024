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

                                                                Kuzhyr U. V.

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
Input A: 12
Input B: 2
Input current temperature: 36
Input heat input: 2
Input simulation time: 10
TIME      Linear Model
=========================
1         436
2         5236
3         62836
4         754036
5         9.04844e+06
6         1.08581e+08
7         1.30297e+09
8         1.56357e+10
9         1.87628e+11
10        2.25154e+12

Choose an option (0 - exit, 1 - linear model, 2 - nonlinear model): Input choice: 2
Input A: 3
Input B: 15
Input C: 20
Input D: 25
Input current temperature: 27
Input heat input: 37
Input simulation time: 20
TIME      Nonlinear Model
1         804.912
2         -7796.35
3         -9.7409e+06
4         -9.40969e+08
5         -1.42328e+15
6         -1.32856e+19
7         -3.03859e+31
8         -2.64761e+39
PS C:\Users\user\Desktop\TMAU-2024\build\trunk\as006417\task_01\src> ./lab_01.exe

Choose an option (0 - exit, 1 - linear model, 2 - nonlinear model): Input choice: 1
Input A: 1.1
Input B: 0.5
Input current temperature: 25
Input heat input: 10
Input simulation time: 5
TIME      Linear Model
=========================
1         32.5
2         40.75
3         49.825
4         59.8075
5         70.7883

Choose an option (0 - exit, 1 - linear model, 2 - nonlinear model): Input choice: 2
Input A: 1.2
Input B: 0.1
Input C: 0.3
Input D: 0.05
Input current temperature: 30
Input heat input: 15
Input simulation time: 5
TIME      Nonlinear Model
=========================
1         40.5325
2         -36.8285
3         -203.95
4         -375.841
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
PS C:\Users\user\Desktop\TMAU-2024\build\trunk\as006417\task_01\src> ^C
```

The source code

The source code is located in the src folder.

    CMakeLists.txt - this is a file that contains CMake commands to control the project build process.
    main.cpp - source file, contains the main function that controls the program execution.

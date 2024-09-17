<p style="font-size: 120%; text-align: center">Ministry of Education of the Republic of Belarus</p>
<p style="font-size: 120%; text-align: center">Educational Institution</p>
<p style="font-size: 120%; text-align: center">“Brest State Technical University”</p>
<p style="font-size: 120%; text-align: center">Department of Computer Systems and Information Technologies</p>
<br><br><br><br><br><br><br>
<p style="font-size: 120%; text-align: center">Laboratory work No. 1</p>
<p style="font-size: 120%; text-align: center">on the discipline “Theory and methods of automatic control”</p>
<p style="font-size: 120%; text-align: center">Theme: “Temperature modeling of an object”</p>
<br><br><br><br><br>
<p style="font-size: 120%; text-align: right">Performed by:</p>
<p style="font-size: 120%; text-align: right">Student of the 3rd year</p>
<p style="font-size: 120%; text-align: right">Group AS-63</p>
<p style="font-size: 120%; text-align: right">Loganov G. A.</p>
<p style="font-size: 120%; text-align: right">Checked by:</p>
<p style="font-size: 120%; text-align: right">Sitkovets Yu. S.</p>
<br><br><br><br><br>
<p style="font-size: 120%; text-align: center">Brest 2024</p>

---

## Task:

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

After transformation we get these linear (2) and nonlinear (3) models:

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)

$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ – time discrete moments ($1,2,3{\dots}n$); $a,b,c,d$ – some constants.

Task is to write program (**С++**), which simulates this object temperature.

## Example of program output:

``` bash
        Input choice (0 - exit, 1 - linear model, 2 - nonlinear model)
Input choice: 1
Input A: 2
Input B: 3.96
Input current_temperature: 12
Input warm: 40
Input time: 5
TIME      LINEAR MODEL
=========================
1         182.4
2         523.2
3         1204.8
4         2568
5         5294.4

        Input choice (0 - exit, 1 - linear model, 2 - nonlinear model)
Input choice: 2
Input A: 8
Input B: 3
Input C: 0.1
Input D: 2.015
Input current_temperature: 1
Input warm: 12
Input time: 7
TIME      NONLINEAR MODEL
=========================
1         8.11881
2         62.0693
3         298.928
4         -9166.23
5         -341403
6         -2.54791e+08
7         -3.51707e+11
```

### Input error handling has also been added:
``` bash
        Input choice (0 - exit, 1 - linear model, 2 - nonlinear model)
Input choice: 5 

                ***Input value is not correct***

Input choice: р

                ***Input value is not correct***
```

### And exit the program:

``` bash
        Input choice (0 - exit, 1 - linear model, 2 - nonlinear model)
Input choice: 0
PS C:\Users\kseni\Documents\Универ\3курс\ТМАУ\TMAU-2024-my\TMAU-2024\tasks\task_01\build>
```

## The source code

#### The source code is located in the [src folder](/trunk/as0006315/task_01/src).

- [CMakeLists.txt](/trunk/as0006315/task_01/src/CMakeLists.txt) - this is a file that contains CMake commands to control the project build process.
- [models.h](/trunk/as0006315/task_01/src/models.h) - header file, contains functions declarations for linear and nonlinear models simulation.
- [models.cpp](/trunk/as0006315/task_01/src/models.cpp) - source file, contains functions definitions for linear and nonlinear models simulation.
- [main.cpp](/trunk/as0006315/task_01/src/main.cpp) - source file, contains the main function that controls the program execution.


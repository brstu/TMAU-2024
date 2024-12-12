<p align="center">Ministry of Education of the Republic of Belarus</p>
<p align="center">Educational Institution</p>
<p align="center">“Brest State Technical University”</p>
<p align="center">Department of Information and Intelligent Technologies</p>
<br><br><br><br><br><br><br>
<p align="center">Laboratory work №2</p>
<p align="center">On the discipline “Theory and methods of automatic control”</p>
<p align="center">Topic: “PID controllers”</p>
<br><br><br><br><br>
<p align="right">Performed by:</p>
<p align="right">Student of the 3rd course</p>
<p align="right">Group AS-63</p>
<p align="right">Loginov G. O.</p>
<p align="right">Supervised by:</p>
<p align="right">Sitkovets J. S.</p>
<br><br><br><br><br>
<p align="center">Brest 2024</p>

---

## Task:

In C++, implement a program that simulates the PID controller discussed above. Use the mathematical model obtained in the previous work as the control object. To use OOP, the program must have at least 3 classes (+inheritance).

 Add information about the developed program (class diagram, etc.) to the report using Doxygen (in .md format).

## Example of program output:

``` bash
        Input choice (0 - exit, 1 - start)
Input choice: 1    
Enter the algorithm of the system functioning
Input w(t): 3
Enter the step
Input T0: 20
        Fill in the data for the Linear model
Input A: 0.2
Input B: 0.4
Input current_temperature: 0.1
Input warm: 0.9
        Fill in the data for the Nonlinear model
Input A: 0.45
Input B: 0.998
Input C: 0.876
Input D: 1.2
Input current_temperature: 1.1
Input warm: 0.8

                                RESULTS

                              Linear model

TIME (T0)      DEVIATION (e)       OUTPUT VARIABLE (Yt)       CONTROLLING INFLUENCE (Uk)
=====================================================================================
1              2.62                0.38                       91.7
2              2.564               0.436                      5264.24
3              2.5528              0.4472                     10393.2
4              2.55056             0.44944                    15499
5              2.55011             0.449888                   20600.2
6              2.55002             0.449978                   25700.4
7              2.55                0.449996                   30800.5
8              2.55                0.449999                   35900.5
9              2.55                0.45                       41000.5
10             2.55                0.45                       46100.5
11             2.55                0.45                       51200.5
12             2.55                0.45                       56300.5
13             2.55                0.45                       61400.5
14             2.55                0.45                       66500.5
15             2.55                0.45                       71600.5
16             2.55                0.45                       76700.5
17             2.55                0.45                       81800.5
18             2.55                0.45                       86900.5
19             2.55                0.45                       92000.5
20             2.55                0.45                       97100.5

                                RESULTS

                              Nonlinear model

TIME (T0)      DEVIATION (e)       OUTPUT VARIABLE (Yt)       CONTROLLING INFLUENCE (Uk)
=====================================================================================
1              0.943373            2.05663                    33.018
2              1.72047             1.27953                    1923.38
3              5.08384             -2.08384                   5462.61
4              4.01002             -1.01002                   15508.6
5              6.22659             -3.22659                   23633.1
6              3.90844             -0.908444                  35949.7
7              12.2372             -9.23724                   44116.1
8              6.41875             -3.41875                   68178.7
9              88.1327             -85.1327                   84021.6
10             51.4126             -48.4126                   256959
11             7256.31             -7253.31                   612874
12             5604.52             -5601.52                   1.48876e+07
13             5.25078e+07         -5.25078e+07               1.86372e+09
14             5.49428e+07         -5.49428e+07               1.05652e+11
15             2.75156e+15         -2.75156e+15               9.63047e+16
16             4.25087e+15         -4.25087e+15               5.5831e+18
17             7.55592e+30         -7.55592e+30               2.64457e+32
18             2.14339e+31         -2.14339e+31               1.56731e+34
19             5.69777e+61         -5.69777e+61               1.99422e+63
20             4.84134e+62         -4.84134e+62               1.29476e+65
```

### Input error handling has also been added:
``` bash
        Input choice (0 - exit, 1 - start)
Input choice: 1  
Enter the algorithm of the system functioning
Input w(t): h

                ***Input valu1e is not correct***

Input w(t): 5
Enter the step
Input T0: g

                ***Input value is not correct***
```

## Graphs

### A graph for a linear model
![](../images/Linear_model.png)

### A graph for a nonlinear model
![](../images/Nonlinear_model.png)

## Documents
Information about the developed program, created using [Doxygen](https://doxygen.nl/) to generate XML and [Moxygen](https://github.com/sourcey/moxygen) to turn XML into Markdown.

The resulting file is [doxygen.md](doxygen.md)

## The source code

#### The source code is located in the [src folder](/trunk/as0006315/task_02/src).

- [CMakeLists.txt](/trunk/as0006315/task_01/src/CMakeLists.txt) - this is a file that contains CMake commands to control the project build process.
- [models.h](/trunk/as0006315/task_01/src/models.h) - header file, contains functions declarations for linear and nonlinear models simulation.
- [models.cpp](/trunk/as0006315/task_01/src/models.cpp) - source file, contains functions definitions for linear and nonlinear models simulation.
- [main.cpp](/trunk/as0006315/task_01/src/main.cpp) - source file, contains the main function that controls the program execution.
- [PID.h](/trunk/as0006315/task_01/src/PID.h) - header file, contains the declaration of the `PID` class, which is used to control the system by the PID algorithm.
- [PID.cpp](/trunk/as0006315/task_01/src/PID.cpp) - source file, contains the definition of the `PID` class, which is used to control the system by the PID algorithm.

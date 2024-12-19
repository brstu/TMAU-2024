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
<p align="right">Kulikovich I. S.</p>
<p align="right">Supervised by:</p>
<p align="right">Sitkovets J. S.</p>
<br><br><br><br><br>
<p align="center">Brest 2024</p>

---

## Task:

In C++, implement a program that simulates the PID controller discussed above. Use the mathematical model obtained in the previous work as the control object. To use OOP, the program must have at least 3 classes (+inheritance).

 Add information about the developed program (class diagram, etc.) to the report using Doxygen (in .md format).

<p align="center" style="font-size:25px;font-weight: bold">Вывод из консоли</p>

                                RESULTS

                              Linear Model Parameters
Input a: 4
Input b: 5
Nonlinear Model Parameters
Input a: 6
Input b: 7
Input c: 3
Input d: 9
        Linear Model
E = 5, Yt = 18.5, Uk = 1.3
E = -10.5, Yt = 6.85, Uk = -1.03
E = 1.15, Yt = 8.145, Uk = -0.771
E = -0.145, Yt = 0.0165, Uk = -2.3967
E = 7.9835, Yt = 11.257, Uk = -0.14859
E = -3.25705, Yt = 10.1003, Uk = -0.379943
E = -2.10028, Yt = 12.4539, Uk = 0.0907789
E = -4.45389, Yt = 3.21808, Uk = -1.75638
E = 4.78192, Yt = 5.97279, Uk = -1.20544
E = 2.02721, Yt = 6.95782, Uk = -1.00844
E = 1.04218, Yt = 12.9491, Uk = 0.189815
E = -4.94908, Yt = 8.55392, Uk = -0.689216
E = -0.553918, Yt = 6.68794, Uk = -1.06241
E = 1.31206, Yt = 4.21279, Uk = -1.55744
E = 3.78721, Yt = 9.21785, Uk = -0.556429
E = -1.21785, Yt = 10.1992, Uk = -0.360165
E = -2.19918, Yt = 9.88287, Uk = -0.423425
E = -1.88287, Yt = 5.58119, Uk = -1.28376
E = 2.41881, Yt = 6.21315, Uk = -1.15737
E = 1.78685, Yt = 7.99728, Uk = -0.800544
E = 0.00272022, Yt = 10.6506, Uk = -0.269879
E = -2.65061, Yt = 8.63538, Uk = -0.672923
E = -0.635383, Yt = 6.75132, Uk = -1.04974
E = 1.24868, Yt = 5.99997, Uk = -1.20001
E = 2.00003, Yt = 8.59118, Uk = -0.681765
E = -0.591176, Yt = 9.62161, Uk = -0.475679
E = -1.62161, Yt = 8.87707, Uk = -0.624585
E = -0.877075, Yt = 6.61529, Uk = -1.07694
E = 1.38471, Yt = 6.7673, Uk = -1.04654
E = 1.2327, Yt = 8.22203, Uk = -0.755593

     Nonlinear Model
E = 5, Yt = 21.9, Uk = 1.3
E = -13.9, Yt = -42.07, Uk = -1.914
E = 50.07, Yt = -21.0986, Uk = 10.7922
E = 29.0986, Yt = 6.60374, Uk = 20.1394
E = 1.39626, Yt = 56.1717, Uk = 30.8415
E = -48.1717, Yt = 19.363, Uk = 23.0843
E = -11.363, Yt = -3.49403, Uk = 16.4996
E = 11.494, Yt = -18.789, Uk = 10.8715
E = 26.789, Yt = -3.11647, Uk = 16.9381
E = 11.1165, Yt = 17.9488, Uk = 23.8106
E = -9.94883, Yt = 25.4751, Uk = 26.3994
E = -17.4751, Yt = 32.103, Uk = 22.8386
E = -24.103, Yt = -11.0005, Uk = 13.582
E = 19.0005, Yt = 4.04228, Uk = 13.7979
E = 3.95772, Yt = 0.95852, Uk = 12.4905
E = 7.04148, Yt = 7.35163, Uk = 17.678
E = 0.648371, Yt = 3.83701, Uk = 19.0431
E = 4.16299, Yt = 20.643, Uk = 21.304
E = -12.643, Yt = 16.0698, Uk = 18.4536
E = -8.06984, Yt = -0.441223, Uk = 16.0101
E = 8.44122, Yt = -1.06876, Uk = 15.5363
E = 9.06876, Yt = 8.37229, Uk = 17.2783
E = -0.372286, Yt = 3.77282, Uk = 19.2576
E = 4.22718, Yt = 23.9051, Uk = 21.7779
E = -15.9051, Yt = 10.6683, Uk = 17.9212
E = -2.66834, Yt = -2.31173, Uk = 16.6314
E = 10.3117, Yt = -2.51649, Uk = 16.5541
E = 10.5165, Yt = 7.32056, Uk = 19.6864
E = 0.679443, Yt = 28.7458, Uk = 22.3543
E = -20.7458, Yt = 7.89532, Uk = 18.6974
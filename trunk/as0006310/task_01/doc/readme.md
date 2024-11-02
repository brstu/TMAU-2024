<p align="center">Ministry of Education of the Republic of Belarus</p>
<p align="center">Educational institution</p>
<p align="center">“Brest State Technical University”</p>
<p align="center">Department of IIT</p>
<br><br><br><br><br><br>
<p align="center"><strong>Laboratory work No. 1</strong></p>
<p align="center"><strong>On the discipline</strong> “Theory and methods of automation control”</p>
<p align="center"><strong>Topic:</strong> “Modeling of object temperature”</p>
<br><br><br><br><br><br>
<p align="right"><strong>Performed by:</strong></p>
<p align="right">Student of 3 course</p>
<p align="right">Group AS-63</p>
<p align="right">Kozlovskaya A. G.</p>
<p align="right"><strong>Verified by:</strong></p>
<p align="right">Sitkovets Y. S.</p>
<br><br><br><br><br>
<p align="center"><strong>Brest 2024</strong></p>

---
***Goal:***
learn to work with cross-platform build system CMake, learn some commands for working with Git and GitHub, write a report in Markdown format. realize the meaning of working with GitHub, Git and CMake, learn basic data management tools.
<br><br><br>
***Task:***
<br><br><br>
Let's take some object for control. We want to control its temperature, which can be described by this differential equation:
$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)
Where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input heating; $Y_0$ – room temperature; $C,RC$ – other constants.
<br><br><br>
After transformation we get linear (2) and nonlinear (3) models:
$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)
$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)
Where $\tau$ – discrete moments of time ($1,2,3{\dots}n$); $a,b,c,d$ – other constants.
<br><br><br>
The task is to write a program (**C++**) that simulates the temperature of this object.
<br><br><br><br>
***Example output of the program:***
<br><br>
Linear Model Parameters
Enter a:        1
Enter b:        2
Enter y:        2
Enter u:        1

Number of tests
Linear model: 3
Nonlinear model: 1

Linear model
Enter Ut: 1
iteration: 1; Yt: 4
Enter Ut: 2
iteration: 2; Yt: 8
Enter Ut: 3
iteration: 3; Yt: 14

Nonlinear model
Enter Ut: 1
iteration: 1; Yt: 7.05
<br><br>
<strong><em>Conclusion:</em></strong>
 <p>In the course of the laboratory work, I learned to work with cross-platform build system CMake, wrote a report in Markdown format and learned some commands for working with Git and GitHub: learned to copy a repository, add changes and etc. </p>

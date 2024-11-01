<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br>
<p align="center"><strong>Лабораторная работа №3</strong></p>
<p align="center"><strong>По дисциплине</strong> “Теория и методы автоматического управления”</p>
<p align="center"><strong>Тема:</strong> “Работа с контроллером AXC F 2152”</p>
<br><br><br><br><br><br>
<p align="right"><strong>Выполнил</strong>:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-63</p>
<p align="right">Ярмолович А.C.</p>
<p align="right"><strong>Проверил:</strong></p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center"><strong>Брест 2024</strong></p>

---
**Target:** use Visual Code and create a test project “Hello PLCnext from AS0xxyy!”, assemble it and show its functionality on a test controller.

**Exercise:**

1. Read general information about the platform **PLCnext**.
1. Explore [руководство](https://github.com/savushkin-r-d/PLCnext-howto/tree/master/HowTo%20build%20program%20Hello%20PLCnext).
1. Using **Visual Code** create a test project *"Hello PLCnext from AS0xxyy!"*,assemble it and demonstrate its functionality on a test controller.
1. Write a report on the work performed in .md format (readme.md) and use a pull request to place it in the following directory: trunk\as000xxyy\task_03\doc.

**Work progress:**

To complete the task, we initially need to assemble the *hello_PLCnext* file in Visual Studio. To do this you need to use the commands:

1) cmake --preset=build-windows-AXCF2152-2021.9.0.40 .
1) cmake --build --preset=build-windows-AXCF2152-2021.9.0.40 --target all .
1) cmake --build --preset=build-windows-AXCF2152-2021.9.0.40 --target install .\

We get a file «hello_PLCnext».
After completing this step, we go to the laboratory and connect to the controller via the Internet connection.

<p align="center"><img style='border:2px solid #000000'src="images/img1.png"/>

To connect to the controller, you first need to configure the network:

<p align="center"><img style='border:2px solid #000000'src="images/img2.png"/>

Then we check the connection to the controller:

<p align="center"><img style='border:2px solid #000000'src="images/img3.png"/>

Open the PuTTY Configuration program to connect to the controller:

<p align="center"><img style='border:2px solid #000000'src="images/img4.png"/>

Enter your login and password (specified on the controller itself) to connect to the controller:

<p align="center"><img style='border:2px solid #000000'src="images/img5.png"/>

Open the WinCP program and connect to the controller:

<p align="center"><img style='border:2px solid #000000'src="images/img6.png"/>

To launch the controller, add the assembled project to its root and change the resolution:

<p align="center"><img style='border:2px solid #000000'src="images/img7.png"/>

We run the project and get the output:

<p align="center"><img style='border:2px solid #000000'src="images/img8.png"/>

<p align="center"><img style='border:2px solid #000000'src="images/img9.png"/>

**Conclusion:** During this laboratory work, we created and assembled a test project and demonstrated its functionality on the controllerAXC F 2152.

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
<p align="right">Ващук А.В.</p>
<p align="right"><strong>Проверил:</strong></p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center"><strong>Брест 2024</strong></p>

---
**Цель:** воспользоваться Visual Code и создать тестовый проект "Hello PLCnext from AS0xxyy!", собрать его и показать работоспособность на тестовом контроллере.

**Задание:**

1. Ознакомиться с общей информацией о платформе **PLCnext**.
1. Изучить [руководство](https://github.com/savushkin-r-d/PLCnext-howto/tree/master/HowTo%20build%20program%20Hello%20PLCnext).
1. Используя **Visual Code** создать тестовый проект *"Hello PLCnext from AS0xxyy!"*, собрать его и продемонстрировать работоспособность на тестовом контроллере.
1. Написать отчет по выполненной работе в .md формате (readme.md) и с помощью pull request разместить его в следующем каталоге: trunk\as000xxyy\task_03\doc.

**Ход работы:**

Для выполнения поставленной задачи нам изначально нужно собрать файл *hello_PLCnext* в Visual Studio. Для этого необходимо воспользоваться командами:

1) cmake --preset=build-windows-AXCF2152-2021.9.0.40 .
1) cmake --build --preset=build-windows-AXCF2152-2021.9.0.40 --target all .
1) cmake --build --preset=build-windows-AXCF2152-2021.9.0.40 --target install .\

У нас получается файл «hello_PLCnext».

![](Aspose.Words.0e358cb3-9e4d-44f5-bffa-8cdb61d98377.001.png)

После выполнения данного пункта, мы идем в лабораторию и подключаемся к контроллеру через  Интернет соединение.



Для подключения к контроллеру сначала нужно настроить сеть:

![](Aspose.Words.0e358cb3-9e4d-44f5-bffa-8cdb61d98377.002.png)

Затем проверяем подключение к контроллеру:

![](Aspose.Words.0e358cb3-9e4d-44f5-bffa-8cdb61d98377.003.png)


После выполнения данного пункта, мы идем в лабораторию и подключаемся к контроллеру через  Интернет соединение.

<p align="center"><img style='border:2px solid #000000'src="images/Снимок экрана 1.png"/>

Для подключения к контроллеру сначала нужно настроить сеть:

<p align="center"><img style='border:2px solid #000000'src="images/Снимок экрана 2.png"/>

Затем проверяем подключение к контроллеру:

<p align="center"><img style='border:2px solid #000000'src="images/Снимок экрана 3.png"/>



Открываем программу PuTTY Configuration для подключения к контроллеру:

![](Aspose.Words.0e358cb3-9e4d-44f5-bffa-8cdb61d98377.004.png)

Вводим логин и пароль (указанный на самом контроллере) для подключения к контроллеру:

![](Aspose.Words.0e358cb3-9e4d-44f5-bffa-8cdb61d98377.005.png)



Открываем программу WinCP и подключаемся к контроллеру:

![](Aspose.Words.0e358cb3-9e4d-44f5-bffa-8cdb61d98377.006.png)

Для запуска контроллера добавляем собранный проект в его корень и меняем разрешение:

![](Aspose.Words.0e358cb3-9e4d-44f5-bffa-8cdb61d98377.007.png)

Запускаем проект и получаем вывод:

![](Aspose.Words.0e358cb3-9e4d-44f5-bffa-8cdb61d98377.008.png)

![](Aspose.Words.0e358cb3-9e4d-44f5-bffa-8cdb61d98377.009.png)

**Вывод:** В ходе выполнения данной лабораторной работы мы создали и собрали тестовый проект, показали его работоспособность на контроллере AXC F 2152.

<p align="center"><img style='border:2px solid #000000'src="images/Снимок экрана 4.png"/>

Вводим логин и пароль (указанный на самом контроллере) для подключения к контроллеру:

<p align="center"><img style='border:2px solid #000000'src="images/Снимок экрана 5.png"/>

Открываем программу WinCP и подключаемся к контроллеру:

<p align="center"><img style='border:2px solid #000000'src="images/Снимок экрана 6.png"/>

Для запуска контроллера добавляем собранный проект в его корень и меняем разрешение:

<p align="center"><img style='border:2px solid #000000'src="images/Снимок экрана 7.png"/>

Запускаем проект и получаем вывод:

<p align="center"><img style='border:2px solid #000000'src="images/Снимок экрана 8.png"/>

<p align="center"><img style='border:2px solid #000000'src="images/Снимок экрана 9.png"/>

**Вывод:** В ходе выполнения данной лабораторной работы мы создали и собрали тестовый проект, показали его работоспособность на контроллере AXC F 2152.


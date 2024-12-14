<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br>
<p align="center"><strong>Лабораторная работа №4</strong></p>
<p align="center"><strong>По дисциплине</strong> “Теория и методы автоматического управления”</p>
<p align="center"><strong>Тема:</strong> “Работа с контроллером AXC F 2152”</p>
<br><br><br><br><br><br>
<p align="right"><strong>Выполнил</strong>:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-63</p>
<p align="right">Колодич М.П.</p>
<p align="right"><strong>Проверил:</strong></p>
<p align="right">Ситковец Я.С.</p>
<br><br><br><br><br>
<p align="center"><strong>Брест-2024</strong></p>

---
**Задание**

1. Ознакомиться с общей информацией о платформе **PLCnext** [здесь](https://www.plcnext.help/te/About/Home.htm).

2. Изучить проект [ptusa_main](https://github.com/savushkin-r-d/ptusa_main).

3. Используя **Visual Studio** собрать данные проект и продемонстрировать работоспособность на тестовом контроллере.

4. Написать отчет по выполненной работе в .md формате (readme.md) и с помощью pull request разместить его в следующем каталоге: trunk\as000xxyy\task04\doc.


<p> <strong>Цель:</strong> собрать проект <em>ptusa_main</em> и продемонстрировать его работу на тестовом контроллере.</p>

<p>Для достижения цели первым шагом будет создание файла <em>ptusa_main</em> в среде **Visual Studio**. Начнем с клонирования git-репозитория, введя следующую команду в терминале или командной строке:</p>


git clone --recurse-submodules https://github.com/savushkin-r-d/ptusa_main.git

<p>После успешного клонирования репозитория, можно приступить к сборке данного проекта.</p>

<p>Когда сборка завершится, появится  исполняемый файл <em>ptusa_main</em>.</p>

<p>Теперь необходимо установить соединение с контроллером при помощи Ethernet.</p>

<p>После подтверждения успешного подключения , запускаем исполняемый файл.</p>

<p align="center"><img style='border:2px solid #010001' src="./images/results.png"/></p>

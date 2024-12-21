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
<p align="right">Поплавский В. В.</p>
<p align="right"><strong>Проверил:</strong></p>
<p align="right">Ситковец Я.С.</p>
<br><br><br><br><br>
<p align="center"><strong>Брест 2024</strong></p>

---
**Задание**

а) Ознакомьтесь с общей информацией о платформе PLCnext здесь.
б) Изучите проект ptusa_main.
в) Соберите проект в Visual Studio и продемонстрируйте его работоспособность на тестовом контроллере.
г) Напишите отчет о выполненной работе в формате .md (readme.md) и с помощью pull request разместите его в каталоге: trunk\as000xxyy\task_04\doc.

<p><strong>Цель:</strong> собрать проект ptusa_main и продемонстрировать его функциональность на тестовом контроллере.</p>

<p>Для выполнения задачи начнем с компиляции файла <em>ptusa_main</em> в Visual Studio. Для этого клонируйте git-репозиторий с помощью следующей команды, которую можно ввести в терминале или командной строке:</p>

bash

Copy
git clone --recurse-submodules https://github.com/savushkin-r-d/ptusa_main.git
<p>После успешного клонирования репозитория переходите к сборке проекта.</p>

<p>По завершении сборки вы получите исполняемый файл <em>ptusa_main</em>.</p>

<p>После сборки необходимо установить соединение с контроллером через Ethernet.</p>

<p>Убедившись в успешном подключении к контроллеру, запустите исполняемый файл.</p>

<p align="center"><img style='border:2px solid #000000' src="./images/result.png"/></p>
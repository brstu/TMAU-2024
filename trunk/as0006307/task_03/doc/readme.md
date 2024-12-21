<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br>
<p align="center"><strong>Лабораторная работа 3</strong></p>
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
2. Изучить [руководство](https://github.com/savushkin-r-d/PLCnext-howto/tree/master/HowTo%20build%20program%20Hello%20PLCnext).
3. Используя Visual Code создать тестовый проект *"Hello PLCnext from AS0xxyy!"*, собрать его и продемонстрировать работоспособность на тестовом контроллере.
4. Написать отчет по выполненной работе в .md формате (readme.md) и с помощью pull request разместить его в следующем каталоге: trunk\as000xxyy\task03\doc.


<p> <strong>Цель:</strong> Разработать тестовый проект "Привет, PLCnext от AS0xxyy!", собрать его и продемонстрировать функциональность на тестовом контроллере.</p>

<p> <strong>Решение:</strong> </p>

<p>В соответствии с заданием, первым шагом будет клонирование репозитория.</p>

<p>Для компиляции файла <em>hello_PLCnext</em> используем:</p>


cmake --preset=build-windows-AXCF2152-2021.0.3.35554 .

cmake --build --preset=build-windows-AXCF2152-2021.0.3.35554 --target all

cmake --build --preset=build-windows-AXCF2152-2021.0.3.35554 --target install

<p>Подключаем контроллер и настраиваем сетевые параметры для взаимодействия с ним.</p>

![](images/conect.png) 

<p>Важно проверить, что соединение с контроллером установлено корректно.

![](images/network_conf.png) 

<p>Запускаем программу <em>PuTTY Configuration</em> и подключаемся к контроллеру.</p>

![](images/PuTTY_conect.png)

<p>Вводим логин и пароль для доступа к контроллеру.</p>

![](images/PuTTY_log_pass.png)

<p>Запускаем <em>WinCP</em> для подключения к контроллеру.</p>

![](images/WinCP_conect.png) 

<p>Копируем собранный проект в корневую папку контроллера и изменяем разрешения для возможности его запуска.</p>

![](images/hi_PLCnext_settings.png)

<p>Запускаем проект и получаем результат.</p>

![](images/result.png) 

<p> <strong>Вывод:</strong> В ходе выполнения данной лабораторной работы был разработан тестовый проект "Привет, PLCnext от AS0xxyy!", что позволило получить ценные знания для работы с контроллером <em>AXC F 2152</em>.</p>
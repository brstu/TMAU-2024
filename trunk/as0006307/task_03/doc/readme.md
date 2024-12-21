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


<p><strong>Цель:</strong> Создать и протестировать проект "Привет, PLCnext от AS0xxyy!", собрать его и продемонстрировать функциональность на целевом контроллере.</p>

<p><strong>Решение:</strong></p>

<p>Для выполнения задания, первым шагом будет клонирование нужного репозитория.</p>

<p>Для компиляции исходного файла <em>hello_PLCnext</em> применим следующие команды:</p>

<pre>
cmake --preset=build-windows-AXCF2152-2021.0.3.35554 .
cmake --build --preset=build-windows-AXCF2152-2021.0.3.35554 --target all
cmake --build --preset=build-windows-AXCF2152-2021.0.3.35554 --target install
</pre>

<p>Подключаем контроллер и настраиваем его сетевые параметры для корректного взаимодействия с ПК.</p>

<img src="images/conect.png" alt="Подключение контроллера">

<p>Обязательно проверяем правильность установленного соединения с устройством.</p>

<img src="images/network_conf.png" alt="Настройки сети">

<p>Используем программу <em>PuTTY Configuration</em> для подключения к контроллеру через терминал.</p>

<img src="images/PuTTY_conect.png" alt="Подключение через PuTTY">

<p>Вводим логин и пароль для авторизации на контроллере.</p>

<img src="images/PuTTY_log_pass.png" alt="Логин и пароль в PuTTY">

<p>Запускаем <em>WinCP</em> для копирования файлов на контроллер.</p>

<img src="images/WinCP_conect.png" alt="Подключение через WinCP">

<p>Перемещаем собранный проект в корневую директорию контроллера и устанавливаем необходимые права доступа для его выполнения.</p>

<img src="images/hi_PLCnext_settings.png" alt="Настройки прав доступа">

<p>Запускаем проект и проверяем его работу.</p>

<img src="images/result.png" alt="Результат работы проекта">

<p><strong>Вывод:</strong> В процессе выполнения проекта был создан тестовый проект "Привет, PLCnext от AS0xxyy!", что помогло углубить знания по работе с контроллером <em>AXC F 2152</em> и настройке взаимодействия с ним.</p>
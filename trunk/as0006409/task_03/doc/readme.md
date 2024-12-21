# Лабораторная работа №3              
<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">«Брестский государственный технический университет»</p>       
<p align="center">Кафедра ИИТ</p>
<br><br><br><br>
<p align="center">Лабораторная работа №3</p>
<p align="center">По дисциплине: «ТИМАУ»</p>
<p align="center">Тема:</strong> “Работа с контроллером AXC F 2152”</p>
<br><br><br>
<p align="right">Выполнил</p> 
<p align="right">Студент 3-го курса</p>
<p align="right">Группы АС-64</p>
<p align="right">Иванюк И.А.</p>
<p align="right">Проверил</p>
<p align="right">Иванюк Д.С.</p>
<br><br><br>
<p align="center">Брест 2024</p>

---

**Задание.**
1. Ознакомиться с общей информацией о платформе **PLCnext** [здесь](https://www.plcnext.help/te/About/Home.htm).
2. Изучить [руководство](https://github.com/savushkin-r-d/PLCnext-howto/tree/master/HowTo%20build%20program%20Hello%20PLCnext).
3. Используя **Visual Code** создать тестовый проект *"Hello PLCnext from AS0xxyy!"*, собрать его и продемонстрировать работоспособность на тестовом контроллере.
4. Написать отчет по выполненной работе в .md формате (readme.md) и с помощью pull request разместить его в следующем каталоге: trunk\as000xxyy\task_03\doc.

#### Решение:
Согласно заданию, клонируем репозитория проекта.</p>
<p>Собираем файл <em>hello_PLCnext</em>, используя следующие команды:</p>

```bash
cmake --preset=build-windows-AXCF2152-2021.0.3.35554 .

```bash
cmake --build --preset=build-windows-AXCF2152-2021.0.3.35554 --target all

```bash
cmake --build --preset=build-windows-AXCF2152-2021.0.3.35554 --target install

<p>Устанавливаем сетевое подключение к контроллеру.</p>

<img src="images/connection.png" alt="Подключение к контроллеру">  

<p>Проверяем соединение с контроллером.</p>

<img src="images/network_configurations.png" alt="Настройка сети">  

<p>Открываем <em>PuTTY Configuration</em> и подключаемся к контроллеру.</p>

<img src="images/PuTTY_connection.png" alt="Подключение через PuTTY"> 

<p>Авторизуемся на контроллере, вводя логин и пароль.</p>

<img src="images/PuTTY_login.png" alt="Авторизация в PuTTY"> 

<p>С помощью <em>WinCP</em> подключаемся к контроллеру.</p>

<img src="images/WinCP_connection.png" alt="Подключение через WinCP"> 

<p>Загружаем собранный проект в корневую директорию контроллера и настраиваем разрешения для его запуска.</p>

<img src="images/hello_settings.png" alt="Настройки проекта"> 

<p>Запускаем проект и наблюдаем следующий результат:</p>

<img src="images/results.png" alt="Результат выполнения"> 

<p><strong>Вывод:</strong> В ходе лабораторной работы был создан тестовый проект "Hello PLCnext from AS0xxyy!" и получены навыки работы с контроллером <em>AXC F 2152</em>.</p>
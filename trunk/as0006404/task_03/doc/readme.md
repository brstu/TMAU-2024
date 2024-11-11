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
<p align="right">Группы АС-64</p>
<p align="right">Булавский А.С.</p>
<p align="right"><strong>Проверила:</strong></p>
<p align="right">Ситковец Я.С.</p>
<br><br><br><br><br>
<p align="center"><strong>Брест 2024</strong></p>

---
<p> <strong>Цель:</strong> создать тестовый проект "Hello PLCnext from AS0xxyy!", собрать его и запустить на тестовом контроллере для подтверждения работоспособности.</p> 

<p> <strong>Решение:</strong> </p>
<p>В соответствии с заданием клонируем репозиторий проекта.</p>
<p>Собираем файл <em>hello_PLCnext</em> с помощью следующих команд:</p>



    cmake --preset=build-windows-AXCF2152-2021.0.3.35554 .


    cmake --build --preset=build-windows-AXCF2152-2021.0.3.35554 --target all


    cmake --build --preset=build-windows-AXCF2152-2021.0.3.35554 --target install


- Подключаемся к контролеру

![](images/connect.png)  

- Проверяем соединение

![](images/1.png)  

- В PuTTY Configuration подключаемся к контроллеру

![](images/2.png) 

- Авторизуемся на контроллере, вводя логин и пароль

![](images/3.png) 

- С помощью WinCP подключаемся к контроллеру

![](images/4.png) 

- Загружаем собранный проект в корневую директорию контроллера и настраиваем разрешения для его запуска.

![](images/5.png) 

- Результат:

![](images/result.png) 

<p> <strong> Вывод:</strong> В ходе лабораторной работы был создан тестовый проект "Hello PLCnext from AS0xxyy!" и приобретены навыки взаимодействия с контроллером <em>AXC F 2152</em>.</p>
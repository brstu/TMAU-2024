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
<p align="right">Ярмола А.О.</p>
<p align="right"><strong>Проверил:</strong></p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center"><strong>Брест 2024</strong></p>

---
<p> <strong>Цель:</strong> создать тестовый проект "Hello PLCnext from AS0xxyy!", собрать его и продемонстрировать работоспособность на тестовом контроллере.</p> 

<p> <strong>Решение:</strong> </p>
<p>Следуя заданию, клонируем репозиторий.</p>
<p>Собираем файл <em>hello_PLCnext</em> используя следующие команды:</p>


 ``` bash
cmake --preset=build-windows-AXCF2152-2021.0.3.35554 .
```


 ``` bash
cmake --build --preset=build-windows-AXCF2152-2021.0.3.35554 --target all
```



 ``` bash
cmake --build --preset=build-windows-AXCF2152-2021.0.3.35554 --target install
```

<p>Подключаемся к контроллеру и настраиваем сеть.</p>

![](images/connect.png)  

<p>Проверяем подключение к контроллеру.</p>

![](images/network_configuration.png)  

<p>Открываем программу <em>PuTTY Configuration</em> и подключаемся к контроллеру.</p>

![](images/PuTTY_connect.png) 

<p>Вводим логин и пароль для подключенияя к контроллеру.</p>

![](images/PuTTY_login_password.png) 

<p>Открываем программу <em>WinCP</em> и подключаемся к контроллеру.</p>

![](images/WinCP_connect.png) 

<p>Добавляем собраный проект в корень контролера и меняем его разрешения, для запуска.</p>

![](images/hello_PLCnext_settings.png) 

<p>Запускаем проект и получаем следующий вывод.</p>

![](images/result.png) 

<p> <strong> Вывод:</strong> В ходе данной лабораторной работы был создан тестовый проект "Hello PLCnext from AS0xxyy!" и получены знания для работы с контроллером <em>AXC F 2152</em></p>
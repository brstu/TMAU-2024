<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">«Брестский государственный технический университет»</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br><br>
<p align="center">Лабораторная работа №5</p>
<p align="center">По дисциплине «Теория и методы автоматического управления»</p>
<p align="center">Тема: «Работа с контроллером AXC F 2152»</p>
<br><br><br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3-го курса</p>
<p align="right">Группы АС-63</p>
<p align="right">Колодич М.П.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br><br><br>
<p align="center">Брест-2024</p>

---

# Задание:
1. Ознакомиться с общей информацией о платформе **PLCnext** [здесь](https://www.plcnext.help/te/About/Home.htm).
2. Изучить проект [T1-PLCnext-Demo](https://github.com/savushkin-r-d/T1-PLCnext-Demo).
3. Внести изменения в описание ([main.plua](https://github.com/savushkin-r-d/T1-PLCnext-Demo/blob/master/main.plua)) управляющей программы .
4. Развернуть данный проект локально и на тестовом контроллере и продемонстрировать работу.
5. Написать отчет по выполненной работе в .md формате (readme.md) и с помощью pull request разместить его в следующем каталоге: trunk\as000xxyy\task_05\doc.

# Ход работы

Разворачивание проекта T1-PLCnext-Demo на локальной машине
Подготовка
Сначала необходимо клонировать репозиторий проекта T1-PLCnext-Demo в выбранный локальный каталог с помощью команды:
sh
Копировать код
git clone --recurse-submodules https://github.com/savushkin-r-d/T1-PLCnext-Demo
Затем скачайте и установите последнюю версию утилиты Git LFS, если у вас её еще нет.

Далее нужно клонировать другой репозиторий, который включает компоненты EasyServer, Monitor и DbEditorXML, используя следующую команду:

sh
Копировать код
git clone --recurse-submodules https://github.com/savushkin-r-d/SCADA-ptusa-bin
После этого нужно настроить компонент DbEditorXML. Для этого откройте DbEditorXML.exe, добавьте драйвер T1_PLCNext_Demo.cdbx и убедитесь, что IP-адрес установлен на 127.0.0.1. Затем запустите приложение Bugger.exe для проверки правильности загрузки сервера.

Следующий шаг — настройка EasyServer. Запустите соответствующий компонент из клонированного репозитория и следуйте инструкциям для настройки файла. Когда настройка будет завершена, запустите проект в программе EasyServer, путь к проекту (в моем случае) будет следующим: "C:\Users\user\Documents\GitHub\SCADA-ptusa-bin\projects\T1_PLCNext_Demo.mpr".

После завершения настройки можно приступать к установке и настройке компонента Monitor. Откройте файл Monitor.exe, добавьте проект T1_PLCNext_Demo.mpr через меню проектов. Для подключения используйте логин user и укажите сервер как localhost.

Сборка и запуск проекта
Для тестирования откройте проект через меню "Файл" -> "Открыть рабочую область из файла" и выберите рабочую область: (D:\PTUSA-projects\T1_PLCNext_Demo\project.code-workspace).

Запустите компоненты EasyServer и Monitor. После этого можно активировать проект, для чего используется Visual Studio Code.

В приложении Monitor будет отображаться информация обо всех устройствах тестового стенда T1_PLCNext_Demo с возможностью управления их состоянием.


Monitor

Запуск на контроллере
Для работы с контроллером потребуется файл ptusa_main, который является результатом Лабораторной работы №4. В этом документе также приведены инструкции по сборке и подключению.

В рамках задания был изменен файл main.plau, в который были внесены следующие корректировки:

plau
Копировать код
function user_init()
    local interval = 200  -- Устанавливаем интервал времени
    A5HL8_info.start_time = get_millisec()  -- Записываем текущее время для A5HL8
    A5HL6_info.start_time = A5HL8_info.start_time - interval  -- Вычисляем время для A5HL6
    A5HL4_info.start_time = A5HL6_info.start_time - interval  -- Вычисляем время для A5HL4
    A5HL2_info.start_time = A5HL4_info.start_time - interval  -- Вычисляем время для A5HL2
    A5HL7_info.start_time = A5HL2_info.start_time - interval  -- Вычисляем время для A5HL7
    A5HL5_info.start_time = A5HL7_info.start_time - interval  -- Вычисляем время для A5HL5
    A5HL3_info.start_time = A5HL5_info.start_time - interval  -- Вычисляем время для A5HL3
    A5HL1_info.start_time = A5HL3_info.start_time - interval  -- Вычисляем время для A5HL1
end
Ключевые моменты:
local interval = 200 — задаёт временной интервал в 200 миллисекунд между запуском каждого из объектов.
A5HL8_info.start_time = get_millisec() — инициализирует время старта для объекта A5HL8 на текущее значение времени в миллисекундах.
A5HL6_info.start_time = A5HL8_info.start_time - interval — время старта для A5HL6 будет на 200 миллисекунд меньше, чем у A5HL8.
A5HL4_info.start_time = A5HL6_info.start_time - interval — аналогично для A5HL4, с уменьшением на 200 миллисекунд по сравнению с A5HL6.
И так далее для остальных объектов. Этот подход позволяет создать последовательность, при которой объекты начинают "свечения" с небольшими задержками друг от друга.

Таким образом, код настраивает последовательность включения лампочек с небольшими временными интервалами, что изменяет порядок их активации.
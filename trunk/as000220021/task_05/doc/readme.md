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
<p align="right">Поплавский В.В.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2024</p>

---

# Задание:
1. Ознакомьтесь с общей информацией о платформе **PLCnext** [здесь](https://www.plcnext.help/te/About/Home.htm).
2. Изучите проект [T1-PLCnext-Demo](https://github.com/savushkin-r-d/T1-PLCnext-Demo).
3. Внесите изменения в описание  управляющей программы([main.plua](https://github.com/savushkin-r-d/T1-PLCnext-Demo/blob/master/main.plua)) .
4. Разверните проект локально и на тестовом контроллере, а затем продемонстрируйте его работу.
5. Напишите отчет о выполненной работе в формате .md (readme.md) и разместите его в каталоге: trunk\as000xxyy\task_05\doc.

# Ход работы

## Развертывание проекта T1-PLCnext-Demo локально

### Подготовка

1. Сначала клонируйте репозиторий T1-PLCnext-Demo в локальный каталог:
```sh
git clone --recurse-submodules https://github.com/savushkin-r-d/T1-PLCnext-Demo
```

2. Затем скачайте и установите последнюю версию приложения [Git LFS](https://git-lfs.com/).
3. После этого клонируйте репозиторий, содержащий компоненты EasyServer, Monitor и DbEditorXML, выполнив команду:
```sh
git clone --recurse-submodules https://github.com/savushkin-r-d/SCADA-ptusa-bin
```
 4. Следующий шаг — настройка **DbEditorXML**. Запустите DbEditorXML.exe. Добавьте драйвер T1_PLCNext_Demo.cdbx и убедитесь, что IP-адрес установлен на 127.0.0.1. Затем запустите приложение Bugger.exe для проверки корректной загрузки сервера.
 5. После этого настройте EasyServer. Запустите этот компонент из клонированного репозитория и следуйте инструкции для настройки файла. Когда настройка завершена, запустите проект в EasyServer, который находится по адресу (например):: `"C:\Users\user\Documents\GitHub\SCADA-ptusa-bin\projects\T1_PLCNext_Demo.mpr"`.
 6. Теперь перейдите к установке и настройке Monitor. Запустите файл Monitor.exe, в меню проектов добавьте файл T1_PLCNext_Demo.mpr. Откройте проект, используя следующие данные: Имя пользователя: user; Сервер: localhost.


### Сборка и запуск

Для тестирования проекта выполните следующие шаги:

В верхнем меню выберите:
Файл -> Открыть рабочую область из файла
Затем выберите файл рабочей области:
D:\PTUSA-projects\T1_PLCNext_Demo\project.code-workspace

Запустите EasyServer и Monitor. После этого можно запустить проект в Visual Studio Code.

В Monitor будут отображаться все устройства тестового стенда T1_PLCNext_Demo с возможностью управления.

![](../img/monitor_done.png)
<br>
| _Monitor_

## Запуск на контроллере

Для запуска на контроллере необходим файл ptusa_main, который является результатом Лабораторной работы №4.(../../task_04/doc/readme.md)В этом документе также указана инструкция по сборке и подключению.

В соответствии с условиями задания необходимо было изменить файл main.plua. Были внесены следующие изменения:
```plau
function user_init()
    local DELTA = 200
    A5HL8_info.start_time = get_millisec()
    A5HL6_info.start_time = A5HL8_info.start_time - DELTA
    A5HL4_info.start_time = A5HL6_info.start_time - DELTA
    A5HL2_info.start_time = A5HL4_info.start_time - DELTA
    A5HL7_info.start_time = A5HL2_info.start_time - DELTA
    A5HL5_info.start_time = A5HL7_info.start_time - DELTA
    A5HL3_info.start_time = A5HL5_info.start_time - DELTA
    A5HL1_info.start_time = A5HL3_info.start_time - DELTA
end
```

Основные моменты:
- `local DELTA = 200` - устанавливает интервал в 200 миллисекунд между стартовыми временами объектов.
- `A5HL8_info.start_time = get_millisec()` - устанавливает стартовое время для A5HL8_info как текущее время в миллисекундах.
- `A5HL6_info.start_time = A5HL8_info.start_time - DELTA` - устанавливает стартовое время для A5HL6_info на 200 миллисекунд меньше, чем у A5HL8_info.
- `A5HL4_info.start_time = A5HL6_info.start_time - DELTA` - устанавливает стартовое время для A5HL4_info на 200 миллисекунд меньше, чем у A5HL6_info.
<br>И так далее для остальных объектов.

Таким образом, представленный код изменяет порядок свечения лампочек, что позволяет управлять их состоянием в соответствии с новыми требованиями.
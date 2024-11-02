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
<p align="right">Карпеш Н.П.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2024</p>

---

# Задание:
1. Ознакомиться с общей информацией о платформе **PLCnext** [здесь](https://www.plcnext.help/te/About/Home.htm).
2. Изучить проект [T1-PLCnext-Demo](https://github.com/savushkin-r-d/T1-PLCnext-Demo).
3. Внести изменения в описание ([main.plua](https://github.com/savushkin-r-d/T1-PLCnext-Demo/blob/master/main.plua)) управляющей программы .
4. Развернуть данный проект локально и на тестовом контроллере и продемонстрировать работу.
5. Написать отчет по выполненной работе в .md формате (readme.md) и с помощью pull request разместить его в следующем каталоге: trunk\as000xxyy\task_05\doc.

# Ход работы

## Развернуть проект **T1-PLCnext-Demo** локально

### Подготовка

1. В первую очередь, необходимо клонировать репозиторий T1-PLCnext-Demo в локальный каталог:
```sh
git clone --recurse-submodules https://github.com/savushkin-r-d/T1-PLCnext-Demo
```

2. Затем следует скачать и установить последнюю версию приложения [Git LFS](https://git-lfs.com/).
3. Далее нужно клонировать репозиторий, содержащий компоненты **EasyServer**, **Monitor** и **DbEditorXML**, выполнив команду:
```sh
git clone --recurse-submodules https://github.com/savushkin-r-d/SCADA-ptusa-bin
```
 4. Следующий шаг — настройка **DbEditorXML**. Запустите **DbEditorXML.exe**, добавьте драйвер *T1_PLCNext_Demo.cdbx* и убедитесь, что IP-адрес установлен на `127.0.0.1`. Затем запустите приложение **Bugger.exe** для проверки корректной загрузки сервера.
 5. После этого необходимо настроить **EasyServer**. Запустите этот компонент из клонированного репозитория и следуйте [инструкции](https://github.com/savushkin-r-d/T1-PLCnext-Demo?tab=readme-ov-file#клонирование-проекта) для настройки файла.
<br> Когда настройка завершена, запустите проект в программе EasyServer, который находится по адресу (в моем случае): `"C:\Users\user\Documents\GitHub\SCADA-ptusa-bin\projects\T1_PLCNext_Demo.mpr"`.
 6. Теперь можно перейти к установке и настройке Monitor. Запустите файл Monitor.exe, в меню проектов добавьте файл T1_PLCNext_Demo.mpr. Откройте проект, используя данные Имя пользователя - user и Сервер - localhost.


### Сборка и запуск

Для тестирования проекта в верхнем меню выберите "Файл" -> "Открыть рабочую область из файла" -> "Выберите файл рабочей области: (D:\PTUSA-projects\T1_PLCNext_Demo\project.code-workspace)".

Запускаем **EasyServer** и **Monitor**. После чего можно запустить проект. Для этого использовался _Visual Studio Code_.

В Monitor будут отображаться все устройства тестового стенда T1_PLCNext_Demo с возможностью управления.

![](../img/monitor_done.png)
<br>
| _Monitor_

## Запуск на контроллере

Для запуска на контроллере необходим файл _ptusa_main_ - результат [Лабораторной работы №4](../../task_04/doc/readme.md). Там же указана инструкция для сборки и подключения.

По условиям, необходимо было изменить файл _main.plau_. Были внесены следующие изменения:
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

Таким образом представленный код меняет порядок свечения лампочек.
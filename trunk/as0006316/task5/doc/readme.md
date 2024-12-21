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
<p align="right">Мороз Е. В.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2024</p>

---

# Отчет о выполненной работе по проекту **T1-PLCnext-Demo**

## Задача

1. Ознакомиться с общей информацией о платформе **PLCnext**.
2. Изучить проект **T1-PLCnext-Demo**.
3. Внести изменения в описание управляющей программы (файл [main.plua](https://github.com/savushkin-r-d/T1-PLCnext-Demo/blob/master/main.plua)).
4. Развернуть проект локально и на тестовом контроллере, продемонстрировав его работу.
5. Подготовить отчет в формате .md (readme.md) и разместить его с помощью pull request в каталоге: `trunk\as000xxyy\task_05\doc`.

## Ход работы

### Развертывание проекта **T1-PLCnext-Demo** локально

#### Подготовка

1. Для начала клонируем репозиторий **T1-PLCnext-Demo** в локальную директорию:
   ```sh
   git clone --recurse-submodules https://github.com/savushkin-r-d/T1-PLCnext-Demo
   ```

2. Устанавливаем последнюю версию **Git LFS** из [официального сайта](https://git-lfs.com/).

3. Затем клонируем репозиторий с компонентами **EasyServer**, **Monitor** и **DbEditorXML**:
   ```sh
   git clone --recurse-submodules https://github.com/savushkin-r-d/SCADA-ptusa-bin
   ```

4. Настраиваем **DbEditorXML**: запускаем **DbEditorXML.exe**, добавляем драйвер *T1_PLCNext_Demo.cdbx* и проверяем, что IP-адрес установлен на `127.0.0.1`. После этого запускаем **Bugger.exe** для проверки загрузки.

5. Настраиваем **EasyServer**: запускаем компонент и следуем [инструкциям](https://github.com/savushkin-r-d/T1-PLCnext-Demo?tab=readme-ov-file#клонирование-проекта). После настройки запускаем проект из EasyServer (путь к файлу: `"C:\Users\user\Documents\GitHub\SCADA-ptusa-bin\projects\T1_PLCNext_Demo.mpr"`).

6. Устанавливаем и настраиваем **Monitor**: запускаем **Monitor.exe**, добавляем файл T1_PLCNext_Demo.mpr и открываем проект, используя имя пользователя - user и сервер - localhost.

#### Сборка и запуск

Для тестирования проекта в Visual Studio Code выбираем "Файл" -> "Открыть рабочую область из файла" и указываем путь к файлу: `(D:\PTUSA-projects\T1_PLCNext_Demo\project.code-workspace)`.

Запускаем **EasyServer** и **Monitor**, после чего можно запустить проект. В **Monitor** будут отображаться все устройства тестового стенда **T1_PLCNext_Demo**, предоставляя возможность их управления.

 _Monitor_ Запуск на контроллереДля запуска на контроллере необходим файл _ptusa_main_ из [Лабораторной работы №4](../../task_04/doc/readme.md), где указана инструкция по сборке и подключению.В соответствии с заданием, в файл _main.plua_ были внесены следующие изменения:```luafunction user_init()    local DELTA = 200    A5HL8_info.start_time = get_millisec()    A5HL6_info.start_time = A5HL8_info.start_time - DELTA    A5HL4_info.start_time = A5HL6_info.start_time - DELTA    A5HL2_info.start_time = A5HL4_info.start_time - DELTA    A5HL7_info.start_time = A5HL2_info.start_time - DELTA    A5HL5_info.start_time = A5HL7_info.start_time - DELTA    A5HL3_info.start_time = A5HL5_info.start_time - DELTA    A5HL1_info.start_time = A5HL3_info.start_time - DELTAend```Краткое описание изменений:- `local DELTA = 200` — устанавливает интервал в 200 миллисекунд между стартовыми временами объектов.- `A5HL8_info.start_time = get_millisec()` — задает стартовое время для `A5HL8_info` как текущее время в миллисекундах.- `A5HL6_info.start_time = A5HL8_info.start_time - DELTA` — устанавливает стартовое время для `A5HL6_info` на 200 миллисекунд меньше, чем у `A5HL8_info`, и так далее для остальных объектов.Таким образом, данный код изменяет порядок свечения лампочек.
 ### Заключение 
 Все этапы выполнения задания были успешно завершены. Проект **T1-PLCnext-Demo** был развернут локально и на тестовом контроллере, изменения в файле **main.plua** были успешно реализованы и протестированы. Весь процесс документирован, и отчет будет размещен в указанном каталоге через pull request.
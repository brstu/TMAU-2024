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
<p align="right">Группы АС-64</p>
<p align="right">Хомич В. Г.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2024</p>

---

# Задание:
Развернуть проект **T1-PLCnext-Demo** локально и на тестовом контроллере и проверить его работу . Также внести изменения в описание управляющей программы.

# Ход работы

## Развернуть проект **T1-PLCnext-Demo** локально

### Подготовка

1. Сначала необходимо клонировать репозиторий **T1-PLCnext-Demo** в локальный файловый каталог:
```sh
git clone --recurse-submodules https://github.com/savushkin-r-d/T1-PLCnext-Demo
```

2. После этого необходимо скачать и установить последнюю версию приложения [Git LFS](https://git-lfs.com/).
3. Теперь нужно клонировать рпеозиторий, в котором находятся компоненты **EasyServer**, **Monitor** и **DbEditorXML**, командной:
```sh
git clone --recurse-submodules https://github.com/savushkin-r-d/SCADA-ptusa-bin
```
 4. Следующий этап - настройка **DbEditorXML**. Запускаем **DbEditorXML.exe**, добавляем драйвер *T1_PLCNext_Demo.cdbx* и сверяем IP-адрес, который должен быть `127.0.0.1`. После чего следует зaпустить приложение **Bugger.exe** для проверки корректности загрузки сервера.
 5. Далее необходимо настроить **EasyServer**. Запускаем этот компонент из клонированного репозитория, после чего, следуя [инструкции](https://github.com/savushkin-r-d/T1-PLCnext-Demo?tab=readme-ov-file#клонирование-проекта), настраиваем этот файл.
<br> После настройки можно запустить проект в программе **EasyServer**, находящийся по алресу (в моем случае): `"C:\Users\kseni\Documents\GitHub\SCADA-ptusa-bin\projects\T1_PLCNext_Demo.mpr"`.
 6. Теперь можно приступить к установке и настройке **Monitor**. Запускаем файл **Monitor.exe**, в меню  проектов добавляем файл *T1_PLCNext_Demo.mpr*. Открываем проект с данными `Имя пользователя` - `user` и `Сервеp` - `localhost`.


### Сборка и запуск

Для тестирования проекта в меню сверху выбираем "Файл" -> "Открыть рабочую область из файла" -> "Выбираем файл рабочей области: (D:\PTUSA-projects\T1_PLCNext_Demo\project.code-workspace)".

Запускаем **EasyServer** и **Monitor**. После чего можно запустить проект. Для этого использовался _Visual Studio Code_.

В **Monitor** будут видны все устройства проекта тестового стенда *T1_PLCNext_Demo* с возможностью управления.

![](img/schema.png)
<br>
| _Monitor_

## Запуск на контроллере

Для запуска на контроллере необходим файл _ptusa_main_. Там же указана инструкция для сборки и подключения.

По условиям, необходимо было изменить файл _main.plau_. Были внесены следующие изменения:
```plau
function user_init()
    local DELTA = 300
    A5HL8_info.start_time = get_millisec()
    A5HL6_info.start_time = A5HL8_info.start_time * DELTA / 2
    A5HL4_info.start_time = A5HL6_info.start_time / DELTA * 4
    A5HL2_info.start_time = A5HL4_info.start_time + DELTA + 3
    A5HL7_info.start_time = A5HL2_info.start_time * DELTA * 2
    A5HL5_info.start_time = A5HL7_info.start_time * DELTA * 5
    A5HL3_info.start_time = A5HL5_info.start_time * DELTA / 5
    A5HL1_info.start_time = A5HL3_info.start_time - DELTA 
end
```
Мы изменеили входные параметры функции, в итоге получив разное время включения лампочек.
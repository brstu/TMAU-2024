                        Ministry of Education of the Republic of Belarus

                                        Educational Institution

                                 “Brest State Technical University”

                        Department of Information and Intelligent Technologies



                                          Laboratory work №5

                        On the discipline “Theory and methods of automatic control”

                                Topic: "Work with controller AXC F 2152”



                                                                Performed by:

                                                                Student of the 3rd course

                                                                Group AS-64

                                                                Kuzhyr U. V.

                                                                Supervised by:

                                                                Sitkovets J. S.


                                             Brest 2024

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

1. клонируем репозиторий:
```sh
git clone --recurse-submodules https://github.com/savushkin-r-d/T1-PLCnext-Demo
```

2. Скачиваем и устанавливаем последнюю версию приложения [Git LFS](https://git-lfs.com/).
3. Клонируем репозиторий, содержащий компоненты **EasyServer**, **Monitor** и **DbEditorXML**:
```sh
git clone --recurse-submodules https://github.com/savushkin-r-d/SCADA-ptusa-bin
```
 4. Настраиваем **DbEditorXML**. Запускаем **DbEditorXML.exe**, добавляем драйвер *T1_PLCNext_Demo.cdbx* и убеждаемся, что IP-адрес установлен на `127.0.0.1` или `localhost`. Запускаем приложение **Bugger.exe** для проверки корректной загрузки сервера.
 5. Настраиваем **EasyServer**. Запускаем этот компонент из клонированного репозитория следуем инструкции [инструкция](https://github.com/savushkin-r-d/T1-PLCnext-Demo?tab=readme-ov-file#клонирование-проекта) конфигурации файла.
<br> Когда настройка завершена, запускаем проект в программе EasyServer
 6. Теперь перейдем к установке и настроим Monitor. Запускаем файл Monitor.exe, в меню проектов добавляем файл T1_PLCNext_Demo.mpr. Открываем проект, используя данные Имя пользователя - user и Сервер - localhost.


### Сборка и запуск

Для тестирования в верхнем меню выберираем "Файл" -> "Открыть рабочую область из файла" -> "Выберите файл рабочей области: (D:\PTUSA-projects\T1_PLCNext_Demo\project.code-workspace)".

Запускаем **EasyServer** и **Monitor**. После чего запускаем проект.

В Monitor будут отображаться все устройства тестового стенда T1_PLCNext_Demo с возможностью управления.

![](../img/doned.png)
<br>
| _Monitor_

## Запуск на контроллере

Для запуска на контроллере необходим файл _ptusa_main_ - результат 4 лабараторной.

По условиям, необходимо было изменить файл _main.plau_. Были внесены следующие изменения:
```plau
function initialize_users()
    local OFFSET = 200
    local startTimes = {}

    startTimes.A5HL8 = get_millisec()
    startTimes.A5HL6 = startTimes.A5HL8 - OFFSET
    startTimes.A5HL4 = startTimes.A5HL6 - OFFSET
    startTimes.A5HL2 = startTimes.A5HL4 - OFFSET
    startTimes.A5HL7 = startTimes.A5HL2 - OFFSET
    startTimes.A5HL5 = startTimes.A5HL7 - OFFSET
    startTimes.A5HL3 = startTimes.A5HL5 - OFFSET
    startTimes.A5HL1 = startTimes.A5HL3 - OFFSET

    foreach (name, time in startTimes) do
        _G[name .. "_info"] = {start_time = time}
    end
end
```

Таким образом представленный код меняет порядок свечения лампочек.
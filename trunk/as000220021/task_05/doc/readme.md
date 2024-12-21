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
1. Review the general information about the **PLCnext** platform [here](https://www.plcnext.help/te/About/Home.htm).
2. Study the [T1-PLCnext-Demo](https://github.com/savushkin-r-d/T1-PLCnext-Demo) project.
3. Make changes to the description of the control program ([main.plua](https://github.com/savushkin-r-d/T1-PLCnext-Demo/blob/master/main.plua)) .
4. Deploy the project locally and on the test controller, and then demonstrate its operation.
5. Write a report on the completed work in .md format (readme.md) and place it in the directory: trunk\as000xxyy\task_05\doc.

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
4. The next step is to configure **DbEditorXML**. Run DbEditorXML.exe. Add the T1_PLCNext_Demo.cdbx driver and make sure the IP address is set to 127.0.0.1. Then run the Bugger.exe application to check if the server boots correctly.
5. After that, configure EasyServer. Run this component from the cloned repository and follow the instructions to configure the file. Once the configuration is complete, run the project in EasyServer, which is located at (for example): `"C:\Users\user\Documents\GitHub\SCADA-ptusa-bin\projects\T1_PLCNext_Demo.mpr"`.
6. Now proceed to installing and configuring Monitor. Run the Monitor.exe file, in the projects menu add the T1_PLCNext_Demo.mpr file. Open the project using the following details: Username: user; Server: localhost.


### Сборка и запуск

To test the project, follow these steps:

In the top menu, select:
File -> Open Workspace from File
Then select the workspace file:
D:\PTUSA-projects\T1_PLCNext_Demo\project.code-workspace

Start EasyServer and Monitor. After that, you can run the project in Visual Studio Code.

In the monitor, all devices are tested on the T1_PLCNext_Demo stand from the control point of view.

![](../img/monitor_done.png)
<br>
| _Monitor_

## Запуск на контроллере

To run on the controller, you need the ptusa_main file, which is the result of Laboratory Work No. 4.(../../task_04/doc/readme.md) This document also contains assembly and connection instructions.

In accordance with the conditions of the task, it was necessary to change the main.plua file. The following changes have been made:
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
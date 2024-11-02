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
<p align="right">Ващук А. В.</p>
<p align="right">Проверила:</p>
<p align="right">Ситковец Я. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2024</p>

---

# Task:
Deploy the **T1-PLCnext-Demo** project locally and on the test controller and demonstrate its operation. Also, make changes to the control program description.

# Work Progress

## Deploy the **T1-PLCnext-Demo** Project Locally

### Preparation

1. First, clone the **T1-PLCnext-Demo** repository to a local directory:
```sh
git clone --recurse-submodules https://github.com/savushkin-r-d/T1-PLCnext-Demo
```

2. After that, download and install the latest version of Git LFS. [Git LFS](https://git-lfs.com/).
3. Next, clone the repository containing the **EasyServer**, **Monitor**, and **DbEditorXML** components::
```sh
git clone --recurse-submodules https://github.com/savushkin-r-d/SCADA-ptusa-bin
```
 4. The next step is to configure DbEditorXML. Run DbEditorXML.exe, add the driver T1_PLCNext_Demo.cdbx, and verify the IP address, which should be 127.0.0.1. Then, launch Bugger.exe to check if the server is loaded correctly.
 5. Next, configure EasyServer. Start this component from the cloned repository, and follow the instructions to set it up. [instructions](https://github.com/savushkin-r-d/T1-PLCnext-Demo?tab=readme-ov-file#клонирование-проекта).
<br> After the configuration, you can launch the project in the **EasyServer** program, located at (in my case):: `"C:\Users\kseni\Documents\GitHub\SCADA-ptusa-bin\projects\T1_PLCNext_Demo.mpr"`.
 6. Now you can proceed with the installation and configuration of **Monitor**. Run the **Monitor.exe** file, add the *T1_PLCNext_Demo.mpr* file in the projects menu. Open the project with the credentials Username - user and Server - localhost.


### Building and Running

To test the project, from the top menu select "File" -> "Open workspace from file" -> "Select the workspace file: (D:\PTUSA-projects\T1_PLCNext_Demo\project.code-workspace)".

Start **EasyServer** and **Monitor**, and then you can launch the project using Visual Studio Code.

In **Monitor**, you will see all the devices in the test bench project T1_PLCNext_Demo, with the ability to control them.

<p align="center"><img style='border:2px solid #000000'src="image/monitor_done.png"/>
<br>
| _Monitor_

## Running on the Controller

To run on the controller, you need the ptusa_main file, which is the result of Laboratory Work No. 4. Instructions for building and connecting are provided there.

According to the requirements, the main.plau file needed to be modified. The following changes were made:
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

Key points:
- `local DELTA = 200` - sets a 200-millisecond interval between the start times of the objects.
- `A5HL8_info.start_time = get_millisec()` - sets the start time for A5HL8_info to the current time in milliseconds.
- `A5HL6_info.start_time = A5HL8_info.start_time - DELTA` -  sets the start time for A5HL6_info to 200 milliseconds earlier than A5HL8_info.
- `A5HL4_info.start_time = A5HL6_info.start_time - DELTA` - sets the start time for A5HL4_info to 200 milliseconds earlier than A5HL6_info. <br>And so on for the other objects.

Thus, the presented code changes the sequence of the indicator lights.

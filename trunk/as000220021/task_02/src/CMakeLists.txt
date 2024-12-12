cmake_minimum_required(VERSION 3.10)
<<<<<<< HEAD

project(Task02_18)

add_executable(Task02_18 main.cpp)
=======
project(task_02)

# Добавляем исходные файлы
add_executable(${PROJECT_NAME} main.cpp models.cpp PID.cpp)

# Добавляем заголовочные файлы
include_directories(${SRC_DIR})
>>>>>>> ImRaDeR1/lab2

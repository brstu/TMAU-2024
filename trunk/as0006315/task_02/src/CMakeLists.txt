cmake_minimum_required(VERSION 3.10)
project(Task_02_220021)

# Добавляем исходные файлы
add_executable(${PROJECT_NAME} main.cpp models.cpp PID.cpp)

# Добавляем заголовочные файлы
include_directories(${SRC_DIR})
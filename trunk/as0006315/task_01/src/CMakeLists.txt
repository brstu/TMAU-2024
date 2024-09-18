cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Добавляем исходные файлы
add_executable(${PROJECT_NAME} main.cpp models.cpp)

# Добавляем заголовочные файлы
include_directories(${SRC_DIR})
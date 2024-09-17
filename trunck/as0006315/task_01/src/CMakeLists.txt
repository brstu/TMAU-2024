cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Устанавливаем переменную SRC_DIR
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

# Добавляем исходные файлы
add_executable(${PROJECT_NAME} ${SRC_DIR}/main.cpp ${SRC_DIR}/models.cpp)

# Добавляем заголовочные файлы
include_directories(${SRC_DIR})
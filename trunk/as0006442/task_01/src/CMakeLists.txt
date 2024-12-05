cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0002 NEW)
project(TMAU)

set(SOURCES
    src/main.cpp
)

add_executable(TMAU ${SOURCES})
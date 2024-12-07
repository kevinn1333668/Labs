cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME example)  # Задать имя проекта
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)  # Используем стандарт C++17
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)



include_directories("./")


# Добавляем исполняемый файл и все .cpp файлы
add_executable("${PROJECT_NAME}" functions.cpp main.cpp)

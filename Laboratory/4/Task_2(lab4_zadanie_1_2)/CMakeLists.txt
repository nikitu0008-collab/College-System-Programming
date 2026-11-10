# Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.16)

# Имя проекта
project(lab4_task2)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)  # Обязательно требование стандарта

# Список исходных файлов
set(SOURCES
    src/main.cpp
    src/printToConsole.cpp
)

# Создаём исполняемый файл
add_executable(main ${SOURCES})


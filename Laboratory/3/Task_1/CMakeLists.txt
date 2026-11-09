# Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.16)

# Имя проекта
project(lab3_task1)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)  # Обязательно требование стандарта

# Список исходных файлов
set(SOURCES
    src/funcPrintVector.cpp
    src/main.cpp
    src/myInit.cpp
)

# Создаём исполняемый файл
add_executable(main ${SOURCES})


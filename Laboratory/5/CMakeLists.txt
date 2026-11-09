# Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.16)

# Имя проекта
project(lab5_file_io)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)  # Обязательно требование стандарта

# Список исходных файлов (у лабы 5 один main.cpp без подкаталогов src/include)
set(SOURCES
    main.cpp
)

# Создаём исполняемый файл
add_executable(main ${SOURCES})

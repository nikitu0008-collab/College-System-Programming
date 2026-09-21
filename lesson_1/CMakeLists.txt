cmake_minimum_required(VERSION 3.10)
project(main)

set(CMAKE_CXX_STANDARD 23)

# Находим пакет wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(MyWxApp main.cpp)

# Связываем библиотеки
target_link_libraries(MyWxApp PRIVATE ${wxWidgets_LIBRARIES})

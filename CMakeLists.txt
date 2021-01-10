cmake_minimum_required(VERSION 3.17)
project(figure_drawer)

set(CMAKE_CXX_STANDARD 17)

file(GLOB LIB_SRC src/*.cpp)
add_library(figure_drawer ${LIB_SRC})
target_include_directories(figure_drawer PUBLIC include)

add_executable(figure_drawer_example example/main.cpp)
target_link_libraries(figure_drawer_example figure_drawer gdiplus)
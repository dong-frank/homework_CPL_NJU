cmake_minimum_required(VERSION 3.26)
project(homework C)

set(CMAKE_C_STANDARD 17)

add_executable(temp temp.c)
add_subdirectory(1-types-io)
add_subdirectory(2-if-for-array)
add_subdirectory(3-for-a-while)
add_subdirectory(4-loops)
add_subdirectory(5-function)
add_subdirectory(1-exam)
add_subdirectory(6-recurison)
add_subdirectory(7-data-types)
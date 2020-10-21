cmake_minimum_required(VERSION 3.16)

project(TPCS2_2020)

set(CMAKE_CXX_STANDARD 20)

add_executable(TPCS2_2020 main.cpp)

project(2020_09_11_project01)
set(CMAKE_CXX_STANDARD 20)

add_executable(2020_09_11_project01 2020-09-11/Project01/main.cpp)

#  Project to load all headers
project(Headers)
set(CMAKE_CXX_STANDARD  20)
add_executable(Headers main.cpp cypher/shift_cypher_test.hpp)


project(2020_09_11_project02)
set(CMAKE_CXX_STANDARD 20)

add_executable(2020_09_11_project02 2020-09-11/Project02/main.cpp 2020-09-11/Project02/Point.hpp)


project(2020_10_linked_lists)

add_executable(2020_10_linked_lists LinkedLists/main.cpp)


add_subdirectory(GoogleTests)
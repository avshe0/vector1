cmake_minimum_required(VERSION 3.23)
project(vector C)

set(CMAKE_C_STANDARD 99)

add_executable(vector main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h)

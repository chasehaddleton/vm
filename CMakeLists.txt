cmake_minimum_required(VERSION 3.8)
project(vm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wall -Werror -Wextra)

set(SOURCE_FILES main.cpp)
add_executable(vm ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.8)
project(vm)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wall)

set(SOURCE_FILES vm.cpp library/vmwindow/VMDisplay.cpp library/vmwindow/VMDisplay.h library/Point.h library/input/VMKeyboard.cpp library/input/VMKeyboard.h)
add_executable(vm ${SOURCE_FILES})
target_link_libraries(vm ${CURSES_LIBRARIES})

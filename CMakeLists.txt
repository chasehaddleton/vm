cmake_minimum_required(VERSION 3.8)
project(vm)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wall)

set(SOURCE_FILES vm.cpp library/window/display/VMDisplay.cpp library/window/display/VMDisplay.h library/MatchType.h
        library/abstractions/Model.h library/abstractions/command/Command.cpp library/abstractions/command/Command.h
        library/abstractions/command/CompositeCommand.cpp library/abstractions/command/CompositeCommand.h
        library/commands/Delete.cpp library/commands/Delete.h
        library/abstractions/Display.h library/window/model/VMModel.cpp library/window/model/VMLine.h
        library/window/history/HistoryStack.h library/window/history/HistoryFrame.h library/window/model/VMLine.cpp
        library/window/model/VMDataSource.h library/window/model/VMDataSource.cpp
        library/window/history/HistoryFrame.cpp library/window/history/HistoryStack.cpp
        library/window/VMWindow.h library/window/VMWindow.cpp library/window/model/Cursor.h
        library/window/model/Cursor.cpp library/input/VMKeyboard.cpp library/input/VMKeyboard.h library/ModeType.h
        library/abstractions/Event.h library/events/VMStateChange.cpp library/events/VMStateChange.h)
add_executable(vm ${SOURCE_FILES})
target_link_libraries(vm ${CURSES_LIBRARIES})

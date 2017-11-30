cmake_minimum_required(VERSION 3.8)
project(vm)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wall)

set(SOURCE_FILES vm.cpp library/vmwindow/VMDisplay.cpp library/vmwindow/VMDisplay.h library/Point.h library/abstractions/Command.h
        library/abstractions/Command.cpp library/MatchType.h library/commands/DeleteMotion.cpp library/commands/DeleteMotion.h
        library/abstractions/CompositeCommand.cpp library/abstractions/CompositeCommand.h library/commands/Delete.cpp
        library/commands/Delete.h library/commands/Macro.cpp library/commands/Macro.h library/abstractions/Subscribeable.h library/FileStructure.cpp library/FileStructure.h library/abstractions/Undoable.h library/abstractions/Model.h library/abstractions/Display.h library/abstractions/DataSource.h library/vmwindow/VMModel.cpp library/abstractions/Line.h library/abstractions/HistoryStack.h library/abstractions/HistoryFrame.h library/abstractions/VMModel.h library/vmwindow/Line.cpp library/abstractions/VMDataSource.h library/vmwindow/VMDataSource.cpp library/abstractions/VMDataSource.h library/vmwindow/HistoryFrame.cpp library/vmwindow/HistoryStack.cpp library/abstractions/VMWindow.h library/vmwindow/VMWindow.cpp library/abstractions/Cursor.h library/vmwindow/Cursor.cpp)
add_executable(vm ${SOURCE_FILES})
target_link_libraries(vm ${CURSES_LIBRARIES})

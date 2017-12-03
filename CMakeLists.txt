cmake_minimum_required(VERSION 3.8)
project(vm)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wall )

set(SOURCE_FILES main.cpp library/window/display/VMDisplay.cpp library/window/display/VMDisplay.h library/status/MatchType.h
        library/abstractions/command/Command.cpp library/abstractions/command/Command.h
        library/abstractions/command/CompositeCommand.cpp library/abstractions/command/CompositeCommand.h
        library/abstractions/Display.h library/window/model/VMModel.cpp library/window/model/VMLine.h
        library/window/history/HistoryStack.h library/window/history/HistoryFrame.h library/window/model/VMLine.cpp
        library/window/model/VMDataSource.h library/window/model/VMDataSource.cpp
        library/window/history/HistoryFrame.cpp library/window/history/HistoryStack.cpp
        library/window/model/Cursor.h
        library/window/model/Cursor.cpp library/input/VMKeyboard.cpp library/input/VMKeyboard.h library/status/ModeType.h
        library/window/model/VMChar.h library/window/model/VMChar.cpp library/status/VMState.cpp library/status/VMState.h
        library/status/VMStatusBar.cpp library/status/VMStatusBar.h library/VM.cpp library/VM.h
        library/abstractions/observer/Observer.cpp library/abstractions/observer/Observer.h library/abstractions/observer/Subject.cpp
        library/abstractions/observer/Subject.h library/commands/Exit.cpp library/commands/Exit.h library/input/VMKeyMap.cpp library/input/VMKeyMap.h library/commands/Save.cpp library/commands/Save.h library/abstractions/Display.cpp library/abstractions/Display.h library/abstractions/Model.cpp library/abstractions/Model.h library/abstractions/Saveable.cpp library/abstractions/Saveable.h)
add_executable(vm ${SOURCE_FILES})
target_link_libraries(vm ${CURSES_LIBRARIES})

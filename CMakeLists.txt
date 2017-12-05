cmake_minimum_required(VERSION 3.5.1)
project(vm)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wall )

set(SOURCE_FILES main.cpp library/window/display/VMDisplay.cpp library/window/display/VMDisplay.h library/status/MatchType.h
        library/abstractions/command/Command.cpp library/abstractions/command/Command.h
        library/abstractions/command/CompositeCommand.cpp library/abstractions/command/CompositeCommand.h
        library/abstractions/Display.h library/window/model/VMModel.cpp library/window/model/VMLine.h
        library/window/model/VMLine.cpp library/window/model/VMDataSource.h library/window/model/VMDataSource.cpp
        library/window/model/Cursor.h  library/window/model/Cursor.cpp library/input/VMKeyboard.cpp library/input/VMKeyboard.h
        library/window/model/VMChar.h library/window/model/VMChar.cpp library/status/VMState.cpp library/status/VMState.h
        library/status/VMStatusBar.cpp library/status/VMStatusBar.h library/VM.cpp library/VM.h library/status/ModeType.h
        library/abstractions/observer/Observer.cpp library/abstractions/observer/Observer.h library/abstractions/observer/Subject.cpp
        library/abstractions/observer/Subject.h library/commands/Quit.cpp library/commands/Quit.h library/input/VMKeyMap.cpp
        library/input/VMKeyMap.h library/commands/Write.cpp library/commands/Write.h library/abstractions/Display.cpp
        library/abstractions/Display.h library/abstractions/Model.cpp library/abstractions/Model.h
        library/abstractions/Saveable.cpp library/abstractions/Saveable.h library/input/VMKeyBuffer.cpp library/input/VMKeyBuffer.h
        library/commands/FileInfo.cpp library/commands/FileInfo.h library/commands/MoveToLastLine.cpp library/commands/MoveToLastLine.h
        library/commands/DeleteLine.cpp library/commands/DeleteLine.h library/commands/WriteQuit.cpp library/commands/WriteQuit.h
        library/commands/ReplaceChar.cpp library/commands/ReplaceChar.h library/commands/MoveToLineNum.cpp library/commands/MoveToLineNum.h
        library/commands/ScrollDownLine.cpp library/commands/ScrollDownLine.h library/commands/ScrollUpLine.cpp library/commands/ScrollUpLine.h
        library/commands/Insert.cpp library/commands/Insert.h library/commands/ScrollDownPage.cpp library/commands/ScrollDownPage.h
        library/commands/ScrollUpPage.cpp library/commands/ScrollUpPage.h library/commands/MoveToFirstNonBlank.cpp
        library/commands/MoveToFirstNonBlank.h library/commands/SearchForward.cpp library/commands/SearchForward.h
        library/commands/SearchBackward.cpp library/commands/SearchBackward.h library/commands/StartOfLine.h
        library/commands/StartOfLine.cpp library/commands/MotionWordFront.cpp library/commands/MotionWordFront.h
        library/commands/MotionWordBack.cpp library/commands/MotionWordBack.h library/commands/MotionDown.cpp library/commands/MotionDown.h
        library/commands/MotionUp.cpp library/commands/MotionUp.h library/commands/MotionLeft.cpp library/commands/MotionLeft.h
        library/commands/MotionRight.cpp library/commands/MotionRight.h library/commands/EndOfLine.h library/commands/EndOfLine.cpp
        library/commands/CharType.h)
add_executable(vm ${SOURCE_FILES})
target_link_libraries(vm ${CURSES_LIBRARIES})

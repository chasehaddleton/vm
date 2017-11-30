//
// Created by Slayorious on 2017-11-30.
//

#ifndef VM_CURSOR_H
#define VM_CURSOR_H

#include <cstddef>
#include "VMDataSource.h"

class Cursor {
    size_t xpos;
    size_t ypos;
    VMDataSource::iterator currentLine;
    size_t linePos;
    const VMDataSource& ds;

public:
    size_t getXPos();
    size_t getYPos();
    VMDataSource::iterator getIT();
    size_t getLinePos();

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};

#endif //VM_CURSOR_H

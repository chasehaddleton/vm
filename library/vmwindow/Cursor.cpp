//
// Created by Slayorious on 2017-11-30.
//

#include "../abstractions/Cursor.h"

size_t Cursor::getXPos() { return xpos; }
size_t Cursor::getYPos() { return ypos; }
VMDataSource::iterator Cursor::getIT() { return currentLine; }
size_t Cursor::getLinePos() { return linePos; }

void Cursor::moveLeft() {
    // If we're at the start of the line
    if (linePos == 0) {
        // If we're at the start of the data, cursor should not move
        if (currentLine == ds.cbegin()) {
            // TO DO: SOME KIND OF NOTIFICATION!
        }
        // Otherwise move up a line
        else {
            --currentLine;
            linePos = currentLine->length() - 1;
        }
    }
    // Otherwise we're not at the start of the line
    else {
        // If the line's length is less than linePos, update accordingly
        if (currentLine->length() - 1 < linePos) {
            linePos = currentLine->length() - 2;
        }
        // otherwise decrement linePos by 1
        else {
            --linePos;
        }
    }
}

void Cursor::moveRight() {
    // If we're at the start of the line
    if (linePos == currentLine->length() - 1) {
        // If we're at the end of the data, cursor should not move
        if (currentLine == ds.cend()) {
            // TO DO: SOME KIND OF NOTIFICATION!
        }
        // Otherwise move down a line
        else {
            ++currentLine;
            linePos = 0;
        }
    }
    // Otherwise we're not at the start of the line
    else {
        ++ linePos;
    }
}

void Cursor::moveUp() {
    // TO DO: WRITE ME!
}

void Cursor::moveDown() {
    // TO DO: WRITE ME!
}
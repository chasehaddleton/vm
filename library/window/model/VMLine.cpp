//
// Created by Slayorious on 2017-11-26.
//

#include <string>
#include "VMLine.h"

VMLine::VMLine() : {
}

VMLine::VMLine(std::string s) {
    size_t previousStartPos = 0;
    unsigned char previousWidth = 0;
    size_t startPos = 0;
    unsigned char width = 0;
    for (auto &c:s) {
        startPos = previousStartPos + previousWidth;
        if (c == '\t') {
            width = 8 - startPos % 8;
        }
        else {
            width = 1;
        }
        line.emplace_back(c, 0, startPos, width);
        previousStartPos = startPos;
        previousWidth = width;
    }
}

// adds the character at the given position
void VMLine::addChar(VMLine::iterator &it, char c) {
    unsigned char width = 1;
    size_t startPos;
    if (it == line.begin()) {
        startPos = 0;
    }
    else {
        std::advance(it, -1);
        startPos = it->getStartPos() + 1;
        std::advance(it, 1);
    }
    if (c == '\t') {
        width = 8 - startPos % 8;
    }
    line.insert(it, VMChar(c, DEFAUT_COLOUR, width, startPos));
}

// removes the character at the given position
void VMLine::removeChar(VMLine::const_iterator &it) {
    VMChar tmp = *it;
    line.erase(it);
    //VMLine::iterator updateIt = it;
    if (tmp.getChar() == '\t') { updateStartPos(it); } // TODO: how do I make this iterator not const?
}

// replaces the character at the given position
void VMLine::replaceChar(VMLine::iterator &it, char c) {
    VMChar tmp = *it;
    it->setChar(c);
    if (tmp.getChar() == '\t') { updateStartPos(it); }
}

//
void VMLine::updateStartPos(VMLine::iterator it) {
    size_t previousStartPos;
    unsigned char previousWidth;
    size_t newStartPos;
    unsigned char newWidth;
    // Get the information about the startPos of the previous character
    if (it != line.cbegin()) {
        std::advance(it, -1);
        previousStartPos = it->getStartPos();
        previousWidth = it->getWidth();
        std::advance(it, 1);
    }
    else {
        previousStartPos = 0;
        previousWidth = 0;
    }
    while (true) {
        newStartPos = previousStartPos + previousWidth;
        if (newStartPos == it->getStartPos()) {
            break;
        }
        else {
            it->setStartPos(newStartPos);
            // If it's a tab, then it's width may have changed
            if (it->getChar() == '\t') {
                newWidth = 8 - newStartPos % 8;
            }
            else {
                newWidth = 1;
            }
            it->setWidth(newWidth);
            previousStartPos = newStartPos;
            previousWidth = newWidth;
        }
    }
}

// returns the number of tabs in the line
size_t VMLine::tabCount() {
    size_t count = 0;
    for (auto c:line) {
        if (c.getChar() == '\t') ++count;
    }
    return count;
}

// returns the number of tabs prior to this position
size_t VMLine::tabCount(size_t pos) {
    size_t count = 0;
    for (auto c:line) {
        if (c.getChar() == '\t') ++count;
    }
    return count;
}

// returns the length of the line
size_t VMLine::length() {
    return line.size();
}

size_t VMLine::size() {
    return line.size();
}

// returns the VMLine as a string
std::string VMLine::toString() {
    std::string tmp;
    for (auto &c:line) {
        tmp.push_back(c.getChar());
    }
    return tmp;
}

std::string VMLine::operator*() {
    return toString();
}

std::ostream &operator<<(std::ostream &out, VMLine l) {
    out << *l << std::endl;
	return out;
}
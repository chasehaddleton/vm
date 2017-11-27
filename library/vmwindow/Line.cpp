//
// Created by Slayorious on 2017-11-26.
//

#include <string>
#include "../abstractions/Line.h"

Line::Line(std::string s): line(std::move(s)) {}

void Line::addChar(size_t col, char c) {
    std::string::iterator it = line.begin();
    it += col;
    line.insert(it, c);
}

void Line::removeChar(size_t col) {
    line.erase(col);
}

// returns the number of tabs in the line
size_t Line::tabCount() {
    size_t count = 0;
    for (auto c:line) {
        if (c == '\t') ++count;
    }
    return count;
}

// returns the number of tabs prior to this position
size_t Line::tabCount(size_t pos) {
    size_t count = 0;
    for (auto c:line) {
        if (c == '\t') ++count;
    }
    return count;
}

// returns the length of the line
size_t Line::length() {
    return line.length();
}

// returns the Line as a string
std::string Line::toString() {
    return line;
}
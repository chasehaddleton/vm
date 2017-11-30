//
// Created by Slayorious on 2017-11-26.
//

#include <string>
#include "../abstractions/Line.h"

Line::Line() {}

Line::Line(std::string s): line(std::move(s)) {}

// adds the character at the given position
void Line::addChar(size_t pos, char c) {
    line.insert(pos, 1, c);
}

// removes the character at the given position
void Line::removeChar(size_t pos) {
    line.erase(pos);
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

std::ostream &operator<<(std::ostream &out, Line l) {
    out << l.line;
}


// SOME LEGACY CODE! DELETE BEFORE SUBMISSION!
// probably deprecated iterator wrapper
/*
Line::iterator::iterator(std::string::iterator inputIt) { it = inputIt; }

bool Line::iterator::operator!=(const iterator &other) const { return *it != *other; }

char& Line::iterator::operator*() const { return *it; }

char* Line::iterator::operator->() const { return &*it; }

iterator Line::iterator::operator++() {
    ++it;
    return *this;
}

iterator Line::iterator::operator--() {
    --it;
    return *this;
}
*/
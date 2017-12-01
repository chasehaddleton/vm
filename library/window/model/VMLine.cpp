//
// Created by Slayorious on 2017-11-26.
//

#include <string>
#include "VMLine.h"

VMLine::VMLine() {}

VMLine::VMLine(std::string s) : line(std::move(s)) {}

// adds the character at the given position
void VMLine::addChar(size_t pos, char c) {
    line.insert(pos, 1, c);
}

// removes the character at the given position
void VMLine::removeChar(size_t pos) {
    line.erase(pos);
}

// returns the number of tabs in the line
size_t VMLine::tabCount() {
    size_t count = 0;
    for (auto c:line) {
        if (c == '\t') ++count;
    }
    return count;
}

// returns the number of tabs prior to this position
size_t VMLine::tabCount(size_t pos) {
    size_t count = 0;
    for (auto c:line) {
        if (c == '\t') ++count;
    }
    return count;
}

// returns the length of the line
size_t VMLine::length() {
    return line.length();
}

size_t VMLine::size() {
	return length();
}

// returns the VMLine as a string
std::string VMLine::toString() {
    return line;
}

std::string &VMLine::operator*() {
	return line;
}

std::ostream &operator<<(std::ostream &out, VMLine l) {
    out << *l << std::endl;
	return out;
}


// SOME LEGACY CODE! DELETE BEFORE SUBMISSION!
// probably deprecated iterator wrapper
/*
VMLine::iterator::iterator(std::string::iterator inputIt) { it = inputIt; }

bool VMLine::iterator::operator!=(const iterator &other) const { return *it != *other; }

char& VMLine::iterator::operator*() const { return *it; }

char* VMLine::iterator::operator->() const { return &*it; }

iterator VMLine::iterator::operator++() {
    ++it;
    return *this;
}

iterator VMLine::iterator::operator--() {
    --it;
    return *this;
}
*/
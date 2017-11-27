//
// Created by Slayorious on 2017-11-26.
//

#include "../abstractions/VMDataSource.h"
#include "../abstractions/Line.h"

void VMDataSource::addChar(size_t line, size_t col, char c) {
    lines[line-1].addChar(col, c);
}

void VMDataSource::removeChar(size_t line, size_t col){
    lines[line-1].removeChar(col);
}

void VMDataSource::addLine(const size_t index, const std::string &s) {
    std::vector::iterator it;
    it = lines.begin();
    lines.insert(it[index], Line(s));
}

void VMDataSource::removeLine(const size_t index) {
    std::vector::iterator it;
    it = lines.begin();
    lines.erase(it[index]);
}
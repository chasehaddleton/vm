//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_LINE_H
#define VM_LINE_H


#include <cstddef>
#include <vector>
#include <string>

class Line {
    std::string line;

public:
    explicit Line(std::string str);

    void addChar(size_t col, char c);   // inserts the given character into the position
    void removeChar(size_t col);        // removes the character at the given position
    size_t tabCount();                  // returns number of tabs on line
    size_t tabCount(size_t pos);        // returns number of tabs prior to pos on line
    size_t length();                    // returns length of line
    std::string toString();             // returns line as a string
};

#endif //VM_LINE_H

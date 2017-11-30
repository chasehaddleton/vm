//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_LINE_H
#define VM_LINE_H

#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

class VMLine {
    std::string line;

public:
    VMLine();

    explicit VMLine(std::string str);

    void addChar(size_t pos, char c);   // inserts the given character at the iterator position
    void removeChar(size_t pos);        // removes the character at the given position
    size_t tabCount();                  // returns number of tabs on line
    size_t tabCount(size_t pos);        // returns number of tabs prior to pos on line
    size_t length();                    // returns length of line
	size_t size();

	std::string toString();             // returns line as a string
	std::string &operator*();
    using iterator = std::string::iterator;

};

std::ostream &operator<<(std::ostream &out, VMLine line);

#endif //VM_LINE_H



// TODO: SOME LEGACY CODE DELETE BEFORE SUBMISSION
// possibly deprecated iterator wrapper
/*class iterator {
    std::string::iterator it;
    explicit iterator(std::string::iterator inputIt);

public:
    using iterator_tag = std::bidirectional_iterator_tag;

    bool operator!=(const iterator &other) const;
    char &operator*() const;
    char *operator->() const;

    iterator operator++();
    iterator operator--();
};*/
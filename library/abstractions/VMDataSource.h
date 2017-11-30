//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_VMDATASOURCE_H
#define VM_VMDATASOURCE_H

#include "DataSource.h"
//#include <ostream>
//#include <fstream>
#include <list>
#include <memory>

class VMDataSource {
    std::list<std::unique_ptr<Line>> lines;
    std::string fileName;

    using iterator = std::list::iterator;
    using const_iterator = std::list::const_iterator;

public:

    VMDataSource();
    explicit VMDataSource(const std::string &file);

    void addChar(iterator it, size_t linePos, char c);
    void removeChar(iterator it, size_t linePos);
    void addLine(iterator it, const std::string &str);
    void addLine(iterator it, std::unique_ptr<Line> line);
    std::unique_ptr<Line> removeLine(iterator it);

    void saveFile();
    void saveFile(std::string fileName);

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
};

std::ostream &operator<<(std::ostream &out, VMDataSource &ds);

#endif //VM_VMDATASOURCE_H



// SOME LEGACY CODE, DELETE BEFORE SUBMISSION!

/*class iterator : DataSource::iterator {
    std::list::iterator it;
    explicit iterator(std::list::iterator inputIt);

public:
    using iterator_tag = std::bidirectional_iterator_tag;

    bool operator!=(const iterator &other) const;
    Line &operator*() const;
    Line *operator->() const;
    iterator operator++();
    iterator operator--();

    friend class VMDataSource;
};*/
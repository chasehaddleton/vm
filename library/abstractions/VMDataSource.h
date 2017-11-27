//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_VMDATASOURCE_H
#define VM_VMDATASOURCE_H

#include "DataSource.h"
#include <vector>

class VMDataSource : DataSource {
    std::vector<Line> lines;

public:
    void addChar(size_t line, size_t col, char c);
    void removeChar(size_t line, size_t col);
    void addLine(size_t index, const std::string &str) override;
    void removeLine(size_t index) override;
};

#endif //VM_VMDATASOURCE_H

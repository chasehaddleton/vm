//
// Created by Slayorious on 2017-11-23.
//

#ifndef VM_DATASOURCE_H
#define VM_DATASOURCE_H

#include <vector>
#include "Line.h"

class DataSource {
    virtual void addLine(size_t index, const std::string &str) = 0;
    virtual void removeLine(size_t index) = 0;
};

#endif //VM_DATASOURCE_H

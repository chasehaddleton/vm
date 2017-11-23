//
// Created by Slayorious on 2017-11-23.
//

#ifndef VM_DATASOURCE_H
#define VM_DATASOURCE_H

class DataSource {
    Vector<Line> lines;

    virtual void addLine() = 0;
    virtual void removeLine() = 0;
};

#endif //VM_DATASOURCE_H

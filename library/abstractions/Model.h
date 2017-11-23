//
// Created by Slayorious on 2017-11-23.
//

#ifndef VM_MODEL_H
#define VM_MODEL_H

class Model {
    std::string name;
    DataSource ds;
    HistoryStack undo;
    HistoryStack redo;

    virtual void addLine() = 0;
    virtual void removeLine() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
};

#endif //VM_MODEL_H

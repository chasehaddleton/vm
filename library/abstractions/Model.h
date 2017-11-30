//
// Created by Slayorious on 2017-11-23.
//

#ifndef VM_MODEL_H
#define VM_MODEL_H

#include "DataSource.h"
#include "../vmwindow/history/HistoryStack.h"

class Model {
    virtual void doAddLine() = 0;
    virtual void doRemoveLine() = 0;
    virtual void doUndo() = 0;
    virtual void doRedo() = 0;
public:
    void addLine() { doAddLine(); }
    void removeLine() { doRemoveLine(); }
    void undo() { doUndo(); }
    void redo() { doRedo(); }
};

#endif //VM_MODEL_H

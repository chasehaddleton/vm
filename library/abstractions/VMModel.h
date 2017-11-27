//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_VMMODEL_H
#define VM_VMMODEL_H

#include "Model.h"

class VMModel : Model {
    std::string name;
    DataSource ds;
    HistoryStack undoStack;
    HistoryStack redoStack;

    void doAddLine() override {};
    void doRemoveLine() override {};
    void doUndo() override {};
    void doRedo() override {};
};

#endif //VM_VMMODEL_H

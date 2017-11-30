//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_VMMODEL_H
#define VM_VMMODEL_H

//#include "Model.h"
#include <memory>
#include "VMDataSource.h"
#include "HistoryStack.h"

class VMModel {
    VMDataSource ds;
    Cursor cursor;
    // TO DO:
    // HistoryStack undoStack;
    // HistoryStack redoStack;
    // InfoBar statusBar;

public:
    VMModel();
    explicit VMModel(const std::string &fileName);

    void addChar(size_t linePos, char c);
    void removeChar(size_t linePos);
    void addLine(std::string);
    void addLine(std::unique_ptr<Line> line);
    void removeLine();
    void undo();
    void redo();
    void saveHistFrame();

    void saveFile();
    void saveFile(std::string);
};

#endif //VM_VMMODEL_H

//
// Created by Slayorious on 2017-11-23.
//

#include "../abstractions/VMModel.h"

void VMModel::doRemoveLine(){}

void VMModel::doAddLine(){}

void VMModel::doRedo(){}

void VMModel::doUndo(){
    redoStack.push(undoStack.pop());
}
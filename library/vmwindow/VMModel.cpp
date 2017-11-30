//
// Created by Slayorious on 2017-11-23.
//

#include "../abstractions/VMModel.h"

VMModel::VMModel() = default;

VMModel::VMModel(const std::string &fileName): ds{fileName} {
}

void VMModel::addChar(size_t linePos, char c) {
    ds.addChar(cursor.it, cursor.linePos, c);
    ++cursor.linePos;
}

void VMModel::removeChar(size_t linePos) {
    ds.removeChar(cursor.it, cursor.linePos);
    --cursor.linePos;
}

void VMModel::removeLine(){
    ds.removeLine(cursor.it);
}

void VMModel::addLine(std::string s){
    ds.addLine(cursor.it, s);
}

void VMModel::redo(){}

void VMModel::undo(){}

void VMModel::saveFile() {
    try {
        ds.saveFile();
    }
    catch(std::invalid_argument ia) {
        throw;
    }
}
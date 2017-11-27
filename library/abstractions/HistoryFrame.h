//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_HISTORYFRAME_H
#define VM_HISTORYFRAME_H

#include "../abstractions/Line.h"
#include <vector>
#include <memory>

class HistoryFrame {
    size_t startLine;
    std::unique_ptr<std::vector<Line>> oldLines;
    std::unique_ptr<std::vector<Line>> newLines;

public:
    explicit HistoryFrame(size_t start);

    void addLineAddition(std::string s);
    void addLineRemoval(std::string s);
    void invert();
};

#endif //VM_HISTORYFRAME_H


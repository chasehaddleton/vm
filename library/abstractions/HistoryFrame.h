//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_HISTORYFRAME_H
#define VM_HISTORYFRAME_H

#include "../abstractions/Line.h"
#include <deque>
#include <memory>

class HistoryFrame {
    size_t startLine;
    std::unique_ptr<std::deque<Line>> oldLines;
    std::unique_ptr<std::deque<Line>> newLines;

public:
    explicit HistoryFrame(size_t start);

    void pushNewLine(std::string s);
    void pushOldLine(std::string s);
    void invert();
};

#endif //VM_HISTORYFRAME_H


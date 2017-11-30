//
// Created by Slayorious on 2017-11-26.
//

#include "HistoryFrame.h"

HistoryFrame::HistoryFrame(size_t start): startLine(start) {}

void HistoryFrame::pushNewLine(std::string s) {
    newLines->emplace_back(std::move(s));
}

void HistoryFrame::pushOldLine(std::string s) {
    oldLines->emplace_front(std::move(s));
}

void HistoryFrame::invert() {
    std::unique_ptr<std::vector<std::string>> tmp = oldLines.release();
    oldLines = newLines.release();
    newLines = tmp.release();
}
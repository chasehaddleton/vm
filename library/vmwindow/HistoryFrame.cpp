//
// Created by Slayorious on 2017-11-26.
//

#include "../abstractions/HistoryFrame.h"

HistoryFrame::HistoryFrame(size_t start): startLine(start) {}

void HistoryFrame::addLineAddition(std::string s) {
    newLines->emplace_back(std::move(s));
}

void HistoryFrame::addLineRemoval(std::string s) {
    oldLines->emplace_back(std::move(s));
}

void HistoryFrame::invert() {
    std::unique_ptr<std::vector<std::string>> tmp = oldLines.release();
    oldLines = newLines.release();
    newLines = tmp.release();
}
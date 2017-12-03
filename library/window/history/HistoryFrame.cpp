//
// Created by Slayorious on 2017-11-26.
//

#include "HistoryFrame.h"

HistoryFrame::HistoryFrame() : startLine{0} {}

HistoryFrame::HistoryFrame(size_t start): startLine(start) {}


void HistoryFrame::pushNewLine(VMLine line) {}


void HistoryFrame::pushOldLine(VMLine line) {}


bool HistoryFrame::oldLinesEmpty() {}


bool HistoryFrame::unchanged() {}

// Returns the number of lines in newLines
size_t HistoryFrame::numNewLines() {}

// Returns an iterator pointing to the start of newlines
std::list<VMLine>::iterator HistoryFrame::getNewLinesIter() {}

// Returns an iterator pointing to the start of oldLines
std::list<VMLine>::iterator HistoryFrame::getOldLinesIter() {}

// Reverse the order of newLines and oldLines and swaps them
void HistoryFrame::invert() {
    newLines.reverse();
    oldLines.reverse();
    std::swap(oldLines, newLines);
}
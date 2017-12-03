//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_HISTORYFRAME_H
#define VM_HISTORYFRAME_H

#include "../model/VMLine.h"
#include <deque>
#include <memory>

class HistoryFrame {
    size_t startLine;
	std::list<VMLine> oldLines;
	std::list<VMLine> newLines;

public:
	HistoryFrame();

	explicit HistoryFrame(size_t start);

	using iterator = std::list<VMLine>::iterator;
	using const_iterator = std::list<VMLine>::const_iterator;

	// Places the line into the back of newLines
	void pushNewLine(VMLine line);

	// Places the line into the back of oldLines
	void pushOldLine(VMLine line);

	// Returns true if oldLines is empty
	bool oldLinesEmpty();

	// Returns true if the HistoryFrame represents an unchanged file
	bool unchanged();

	// Returns the number of lines in newLines
	size_t numNewLines();

	// Returns an iterator pointing to the start of newlines
	std::list<VMLine>::iterator getNewLinesIter();

	// Returns an iterator pointing to the start of oldLines
	std::list<VMLine>::iterator getOldLinesIter();

	// Reverse the order of newLines and oldLines and swaps them
	void invert();
};

#endif //VM_HISTORYFRAME_H


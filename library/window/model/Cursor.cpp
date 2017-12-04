//
// Created by Slayorious on 2017-11-30.
//

#include "Cursor.h"

Cursor::Cursor(VMDataSource &ds, const VMState &vmState) : ds{ds}, state{vmState}, currentLine{ds.begin()},
                                                           currentLetter{currentLine->begin()} {}

// Returns the x position
size_t Cursor::getXPos() const { return xPos; }

// Returns the y position
size_t Cursor::getYPos() const { return yPos; }

// Returns a copy of the Cursor's DataSource iterator
VMDataSource::iterator &Cursor::getDSIter() { return currentLine; }

// Returns a copy of the Cursor's Line iterator
VMLine::iterator &Cursor::getLineIter() { return currentLetter; }

// Returns the line number
size_t Cursor::getLineNumber() const { return yPos; }

// Returns the lesser of the insertion position or the end of the line
size_t Cursor::getInsertPos() const { return insertPos; }

// Returns the first line to be displayed
size_t &Cursor::getFirstLineNumber() { return firstLineNumber; }

// TODO: Add alerts to all places marked alert

// Moves the cursor left one character
void Cursor::moveLeft() {
	// If we're at the start of the line, we don't move left
	if (xPos == 0) {
		// ALERT
	} else {
		if (state.getMode() == ModeType::INSERT) {
			--currentLetter;
			--insertPos;
			xPos -= currentLetter->getWidth();
			globalXPos = xPos;
		}
		else {
			if (currentLetter == currentLine->end()) {
				--xPos;
			}
			else {
				xPos -= currentLetter->getWidth();
			}
			globalXPos = xPos;
			--currentLetter;
			--insertPos;
		}
	}
}

// Move the cursor left one character
void Cursor::moveRight() {
	// If we're at the end of line, we don't move right
	size_t currentLineWidth = currentLine->lineWidth();
	if (state.isDisplayPastEnd()) ++currentLineWidth;

	if (xPos >= (currentLineWidth == 0 ? currentLineWidth : currentLineWidth - 1)) {
		// ALERT
	} else {
		// If we're in insert mode the cursor should move to the front of wide characters
		if (state.getMode() == ModeType::INSERT) {
			if (currentLetter == currentLine->end()) {
				++xPos;
			}
			else {
				xPos += currentLetter->getWidth();
			}
			globalXPos = xPos;
			++currentLetter;
			++insertPos;
		}
			// Otherwise the cursor should move to the back of wide characters
		else {
			++currentLetter;
			++insertPos;
			if (currentLetter == currentLine->end()) {
				++xPos;
			}
			else {
				xPos += currentLetter->getWidth();
			}
			globalXPos = xPos;
		}
	}
}

// Moves the cursor up one line
void Cursor::moveUp() {
	// If we're at the top, we don't move up
	if (currentLine == ds.cbegin()) {
		// ALERT
	} else {
		--currentLine;
		--yPos;
		updateHorizontalPos();
	}
}

// Moves the cursor down one line
void Cursor::moveDown() {
	if (currentLine == --ds.cend()) {
		// ALERT
	} else {
		++currentLine;
		++yPos;
		updateHorizontalPos();
	}
}

// Moves the cursor to the start of the line
void Cursor::moveSOL() {
	globalXPos = 0;
	xPos = 0;
	currentLetter = currentLine->begin();
	insertPos = 0;
}

// Moves the cursor to the end of the line
void Cursor::moveEOL() {
	globalXPos = currentLine->lineWidth();
	if (!state.isDisplayPastEnd()) { --globalXPos; }
	updateHorizontalPos();
}

// Moves the cursor to the start of the data
void Cursor::moveSOD() {
	currentLine = ds.begin();
	currentLetter = currentLine->begin();
	globalXPos = 0;
	xPos = 0;
	yPos = 0;
	insertPos = 0;
}

// Moves the cursor to the given line
void Cursor::moveToLine(size_t lineNum) {
	lineNum = std::max(size_t{1}, lineNum);
	--lineNum;

	if (lineNum > ds.size()) {
		return moveToLine(std::min(lineNum, ds.size()));
	}

	std::advance(currentLine, -(static_cast<std::ptrdiff_t>(yPos) - static_cast<std::ptrdiff_t>(lineNum)));

	currentLetter = currentLine->begin();
	xPos = 0;
	yPos = lineNum;
}

// Moves the cursor to the end of the data
void Cursor::moveEOD() {
	currentLine = --(ds.end());
	currentLetter = --(currentLine->end());
	globalXPos = currentLine->lineWidth();
	xPos = globalXPos;
	yPos = ds.size();
	insertPos = currentLine->size() - 1;
}

// Moves the cursor to the last line
void Cursor::moveToLastLine() {
	currentLine = --(ds.end());
	currentLetter = currentLine->begin();
	globalXPos = 0;
	xPos = 0;
	yPos = ds.size();
	insertPos = 0;
}

// Returns true if cursor is at the start of a line
bool Cursor::startOfLine() {
	return xPos == 0;
}

// Returns true if cursor is at the end of a line
bool Cursor::endOfLine() {
	size_t width = currentLine->lineWidth();
	if (state.isDisplayPastEnd()) { return xPos == width; }
	return xPos == width - 1;
}

// Returns true if cursor is at the start of the data
bool Cursor::startOfData() {
	return (yPos == 0) && (xPos == 0);
}

// Returns true if cursor is at the end of the data
bool Cursor::endOfData() {
	auto lastLineIter = ds.end();
	--lastLineIter;
	auto lastLetterIter = lastLineIter->end();
	--lastLetterIter;
	return (currentLine == lastLineIter) && (currentLetter == lastLetterIter);
}

// Updates the horizontal position of the cursor
void Cursor::updateHorizontalPos() {
	size_t currentLineWidth = currentLine->lineWidth();
	size_t tempPos;

	// Our position is the lesser of our global xPos or the length of the newLine
	if (state.isDisplayPastEnd()) {
		tempPos = std::min(globalXPos, currentLineWidth);
	} else if (currentLineWidth == 0) {
		if (state.getMode() == ModeType::INSERT) {
			tempPos = std::min(globalXPos, size_t{1});
		}
		else {
			tempPos = 0;
		}
	} else {
		tempPos = std::min(globalXPos, currentLineWidth - 1);
	}

	currentLetter = currentLine->begin();
	insertPos = 0;


	//std::cout << "here" << std::flush;
	//std::cout << "[" << (currentLetter->getStartPos() + currentLetter->getWidth()) << "," << tempPos << std::flush;
	if (currentLine->empty()) {
		xPos = tempPos;
	} else {
		while (currentLetter != currentLine->end()) {
			if ((currentLetter->getStartPos() + currentLetter->getWidth()) > tempPos) { break; }
			++currentLetter;
			++insertPos;
		}

		if (state.getMode() == ModeType::INSERT) {
			// If we're past the end of the end of the line xPos should be too
			if (currentLetter == currentLine->end()) {
				xPos = currentLineWidth;
				//std::cout << "here" << std::flush;
			}
			else {
				xPos = currentLetter->getStartPos();
			}
		}
		else {
			xPos = currentLetter->getStartPos() + currentLetter->getWidth() - 1;
		}
	}
}

std::string Cursor::toString() const {
	return "(" + std::to_string(yPos + 1) + ":" + std::to_string(xPos + 1) + ")";
}

void Cursor::moveFrameDown() {
	if (firstLineNumber + state.getWindowY() + 1 < ds.size()) {
		++firstLineNumber;
	}
	moveDown();
}

void Cursor::moveFrameUp() {
	if (firstLineNumber > 0) {
		--firstLineNumber;
	}
	moveUp();
}

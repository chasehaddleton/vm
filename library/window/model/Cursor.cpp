//
// Created by Slayorious on 2017-11-30.
//

#include "Cursor.h"

Cursor::Cursor(VMDataSource &ds, const VMState &vmState) : ds{ds}, state{vmState}, currentLine{ds.begin()},
                                                           currentLetter{currentLine->begin()} {}

// Returns the x position
size_t Cursor::getXPos() { return xPos; }

// Returns the y position
size_t Cursor::getYPos() { return yPos; }

// Returns a copy of the Cursor's DataSource iterator
VMDataSource::iterator Cursor::getDSIter() { return currentLine; }

// Returns a copy of the Cursor's Line iterator
VMLine::iterator Cursor::getLineIter() { return currentLetter; }

// Returns the line number
size_t Cursor::getLineNumber() { return yPos; }

// Returns the lesser of the insertion position or the end of the line
size_t Cursor::getInsertPos() { return insertPos; }

// Returns the first line to be displayed
size_t &Cursor::getFirstLineNumber() { return firstLineNumber; }

// TODO: Add alerts to all places marked alert

// Moves the cursor left one character
void Cursor::moveLeft() {
	// If we're at the start of the line, we don't move left
	if (xPos == 0) {
		// ALERT
	} else {
		xPos -= currentLetter->getWidth();
		globalXPos = xPos;
		--currentLetter;
		--insertPos;
	}
}

// Move the cursor left one character
void Cursor::moveRight() {
	// If we're at the end of line, we don't move right
	// TODO: make this if statement nicer if possible
	size_t currentLineWidth = currentLine->lineWidth();

	if (xPos >= (state.isDisplayPastEnd() ? currentLineWidth
	                                      : (currentLineWidth == 0 ? 0 : currentLineWidth - 1))) {
		// ALERT
	} else {
		++currentLetter;
		++insertPos;
		xPos += currentLetter->getWidth();
		globalXPos = xPos;
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

// Updates the horizontal position of the cursor
void Cursor::updateHorizontalPos() {
	// Our position is the lesser of our global xPos or the length of the newLine
	size_t currentLineWidth = currentLine->lineWidth();
	size_t tempPos;

	if (state.isDisplayPastEnd()) {
		tempPos = std::min(globalXPos, currentLineWidth);
	} else if (currentLineWidth == 0) {
		tempPos = 0;
	} else {
		tempPos = std::min(globalXPos, currentLineWidth - 1);
	}

	currentLetter = currentLine->begin();
	insertPos = 0;

	while (currentLetter->getStartPos() + currentLetter->getWidth() <= tempPos) {
		++currentLetter;
		++insertPos;
	}

	xPos = currentLetter->getStartPos() + currentLetter->getWidth() - 1;
}

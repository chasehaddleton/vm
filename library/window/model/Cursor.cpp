//
// Created by Slayorious on 2017-11-30.
//

#include "Cursor.h"

Cursor::Cursor(VMDataSource &ds) : ds{ds}, currentLine{ds.begin()} {}

// returns the x position
size_t Cursor::getXPos() { return xPos; }

// returns the y position
size_t Cursor::getYPos() { return yPos; }

// returns (a copy of?) the Cursor's DataSource iterator
VMDataSource::iterator Cursor::getIT() { return currentLine; }

// Returns the lesser of the insertion position or the end of the line
size_t Cursor::getInsertPos() { return std::min(insertPos, currentLine->length()); }

// TODO: Add alerts to all places marked alert

// Moves the cursor left one space
void Cursor::moveLeft() {
	// If we're at the start of the line, we don't move left
	if (insertPos == 0) {
		// ALERT
	}
	else {
		--currentLetter;
		--insertPos;
		xPos -= currentLetter->getWidth();
		globalXPos = xPos;
	}
}

// Move the cursor left one space
void Cursor::moveRight() {
	// If we're at the end of line, we don't move right
	// TODO: make this if statement nicer if possible
	if (insertPos >= (rightOfEnd ? currentLine->length()
	                             : (currentLine->length() == 0 ? 0 : currentLine->length() - 1))) {
		// ALERT
	}
	else {
		xPos += currentLetter->getWidth();
		globalXPos = xPos;
		++currentLetter;
		++insertPos;
	}
}

// Moves the cursor up one line
void Cursor::moveUp() {
	// If we're at the top, we don't move up
	if (currentLine == ds.cbegin()) {
		// ALERT
	}
	else {
		--currentLine;
		--yPos;
		updateHorizontalPos();
	}
}

// Moves the cursor down one line
void Cursor::moveDown() {
	// If we're at the bottom, we don't move down
	if (currentLine == ds.cend()) {
		// ALERT
	}
	else {
		++currentLine;
		++yPos;
		updateHorizontalPos();
	}
}

void Cursor::updateHorizontalPos() {
	// Our position is the lesser of our global xPos or the length of the newLine
	xPos = (rightOfEnd ? std::min(globalXPos, currentLine->length())
	                   : std::min(globalXPos, currentLine->length() - 1));
	currentLetter = currentLine->begin();
	insertPos = 0;
	while (currentLetter->getStartPos() + currentLetter->getWidth() <= xPos) {
		++currentLetter;
		++insertPos;
	}
}

// Allows the cursor to be positioned one space beyond the end of line
void Cursor::allowRightOfEnd() {
	rightOfEnd = true;
}

// Disables allowing the cursor to be positioned one space beyond the end of line
void Cursor::disableRightOfEnd() {
	rightOfEnd = false;
}
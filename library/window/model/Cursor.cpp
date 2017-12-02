//
// Created by Slayorious on 2017-11-30.
//

#include "Cursor.h"

Cursor::Cursor(VMDataSource &ds) : ds{ds}, currentLine{ds.begin()} {}

size_t Cursor::getXPos() { return xPos; }

size_t Cursor::getYPos() { return yPos; }

VMDataSource::iterator Cursor::getIT() { return currentLine; }

size_t Cursor::getInsertPos() { return insertPos; }

// TODO: Add alerts to all places marked alert

// Moves the cursor left one space
void Cursor::moveLeft() {
	// If we're at the start of the line, we don't move left
	if (insertPos == 0) {
		// Alert
	}
	else {
		--insertPos;
		--xPos;
	}
}

// Move the cursor left one space
void Cursor::moveRight() {
	// If we're at the end of line, we don't move right
	if (insertPos + 1 <= (rightOfEnd ? currentLine->length() : currentLine->length() - 1)) {
		// ALERT
	}
	else {
		++insertPos;
		++xPos;
	}

	std::cout << xPos << std::flush;
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
	}
}

// Allows the cursor to be positioned one space beyond the end of line
void Cursor::allowRightOfEnd() {
	rightOfEnd = true;
}

// Disables allowing the cursor to be positioned one space beyond the end of line
//   Note: it is the responsibility of the caller to ensure
void Cursor::disableRightOfEnd() {
	rightOfEnd = false;
}
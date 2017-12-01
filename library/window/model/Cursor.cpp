//
// Created by Slayorious on 2017-11-30.
//

#include "Cursor.h"

Cursor::Cursor(VMDataSource &ds) : ds{ds}, currentLine{ds.begin()} {}

size_t Cursor::getXPos() { return xPos; }

size_t Cursor::getYPos() { return yPos; }

VMDataSource::iterator Cursor::getIT() { return currentLine; }

size_t Cursor::getLinePos() { return linePos; }

// TODO: Add alerts to all places marked alert
void Cursor::moveLeft() {
	// If we're at the start of the line, we don't move left
	if (linePos == 0) {
		// Alert
	}
	else {
		--linePos;
		--xPos;
	}
}

void Cursor::moveRight() {
	// If we're at the end of line, we don't move right
	if (linePos == (*currentLine)->length() - 1) {
		// ALERT
	}
	else {
		++linePos;
		++xPos;
	}
}

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

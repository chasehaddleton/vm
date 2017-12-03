//
// Created by Slayorious on 2017-11-30.
//

#ifndef VM_CURSOR_H
#define VM_CURSOR_H

#include <cstddef>
#include "VMDataSource.h"

class Cursor {
	VMDataSource &ds;
	VMDataSource::iterator currentLine;
	VMLine::iterator currentLetter;

	size_t xPos;
	size_t yPos;
	size_t globalXPos;
	size_t insertPos;
	bool rightOfEnd;

	// Updates the horizontal position of the cursor
	void updateHorizontalPos();

public:
	explicit Cursor(VMDataSource &ds);

	// Returns the x position
	size_t getXPos();

	// Returns the y position
	size_t getYPos();

	VMDataSource::iterator getIT();

	VMLine::iterator getLineIter();

	// Returns the line number
	size_t getLineNumber();

	// Returns the lesser of the insertion position or the end of the line
	size_t getInsertPos();

	// Moves the cursor left one character
	void moveLeft();

	// Moves the cursor right one character
	void moveRight();

	// Moves the cursor up one line
	void moveUp();

	// Moves the cursor down one line
	void moveDown();

	// Allows the cursor to be positioned one space beyond the end of line
	void allowRightOfEnd();

	// Disables allowing the cursor to be positioned one space beyond the end of line
	void disableRightOfEnd();
};

#endif //VM_CURSOR_H

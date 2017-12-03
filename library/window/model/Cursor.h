//
// Created by Slayorious on 2017-11-30.
//

#ifndef VM_CURSOR_H
#define VM_CURSOR_H

#include <cstddef>
#include "VMDataSource.h"
#include "../../status/VMState.h"

class Cursor {
	VMDataSource &ds;
	const VMState &state;
	VMDataSource::iterator currentLine;
	VMLine::iterator currentLetter;

	size_t xPos{0};
	size_t yPos{0};
	size_t globalXPos{0};
	size_t insertPos{0};
	size_t firstLineNumber{0};

	// Updates the horizontal position of the cursor
	void updateHorizontalPos();

public:
	explicit Cursor(VMDataSource &ds, const VMState &vmState);

	Cursor(const Cursor &other) = delete;

	Cursor &operator=(const Cursor &other) = delete;

	// Returns the x position
	size_t getXPos() const ;

	// Returns the y position
	size_t getYPos() const;

	VMDataSource::iterator getDSIter();

	VMLine::iterator getLineIter();

	// Returns the line number
	size_t getLineNumber() const;

	// Returns the lesser of the insertion position or the end of the line
	size_t getInsertPos() const;

	// Returns the first line to be displayed
	size_t &getFirstLineNumber();

	// Moves the cursor left one character
	void moveLeft();

	// Moves the cursor right one character
	void moveRight();

	// Moves the cursor up one line
	void moveUp();

	// Moves the cursor down one line
	void moveDown();

	// Moves the cursor to the start of the line
	void moveSOL();

	// Moves the cursor to the end of the line
	void moveEOL();

};

#endif //VM_CURSOR_H

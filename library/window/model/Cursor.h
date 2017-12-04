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

	VMDataSource::iterator& getDSIter();

	VMLine::iterator& getLineIter();

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

	// Moves the cursor to the start of the data
	void moveSOD();

	// Moves the cursor to the given line
	void moveToLine(size_t lineNum);

	// Moves the cursor to the end of the data
	void moveEOD();

	// Returns true if cursor is at the start of a line
	bool startOfLine();

	// Returns true if cursor is at the end of a line
	bool endOfLine();

	// Returns true if cursor is at the start of the data
	bool startOfData();

	// Returns true if cursor is at the end of the data
	bool endOfData();

	void moveFrameDown();

	void moveFrameUp();

	std::string toString() const;
};

#endif //VM_CURSOR_H

//
// Created by Slayorious on 2017-11-30.
//

#ifndef VM_CURSOR_H
#define VM_CURSOR_H

#include <cstddef>
#include "VMDataSource.h"

class Cursor {
	const VMDataSource &ds;
	VMDataSource::iterator currentLine;
	VMLine::iterator currentLetter;

	size_t xPos;
	size_t yPos;
	size_t globalXPos;
	size_t insertPos;
	bool rightOfEnd;

	void updateHorizontalPos();

public:
	explicit Cursor(VMDataSource &ds);

	size_t getXPos();

	size_t getYPos();

	VMDataSource::iterator getIT();

	size_t getInsertPos();

	void moveLeft();

	void moveRight();

	void moveUp();

	void moveDown();

	void allowRightOfEnd();

	void disableRightOfEnd();
};

#endif //VM_CURSOR_H

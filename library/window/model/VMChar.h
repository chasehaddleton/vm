//
// Created by Slayorious on 2017-12-01.
//

#ifndef VM_VMCHAR_H
#define VM_VMCHAR_H

#include <cstddef>

class VMChar {
	char c;
	int colour;
	unsigned char width;
	//size_t startPos;

public:
	VMChar() = default;

	VMChar(char c, int colour, unsigned char width);
	//VMChar(char c, int colour, unsigned char width, size_t startPos);

	char getChar();

	void setChar(char newC);

	int getColour();

	void setColour(int newColour);

	unsigned char getWidth();

	void setWidth(unsigned char newWidth);
	//size_t getStartPos();
	//void setStartPos();
};

#endif //VM_VMCHAR_H

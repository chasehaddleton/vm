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
	size_t startPos;

public:
	VMChar() = default;

	//VMChar(char c, int colour, unsigned char width);
	VMChar(char c, int colour, size_t startPos, unsigned char width);

	char getChar() const;

	void setChar(char newC);

	int getColour() const ;

	void setColour(int newColour);

	size_t getStartPos() const;

	void setStartPos(size_t startPos);

	unsigned char getWidth() const;

	void setWidth(unsigned char newWidth);
};

#endif //VM_VMCHAR_H

//
// Created by Slayorious on 2017-12-01.
//

#include "VMChar.h"

//VMChar::VMChar(char c, int colour, unsigned char width) : c{c}, colour{colour}, width{width} {}

VMChar::VMChar(char c, int colour, size_t startPos, unsigned char width) :
		c{c}, colour{colour}, startPos{startPos}, width{width} {}

char VMChar::getChar() const { return c; }

void VMChar::setChar(char newC) { c = newC; }

int VMChar::getColour() const { return colour; }

void VMChar::setColour(int newColour) { colour = newColour; }

size_t VMChar::getStartPos() const { return startPos; }

void VMChar::setStartPos(size_t newStart) { startPos = newStart; }

unsigned char VMChar::getWidth() const { return width; }

void VMChar::setWidth(unsigned char newWidth) { width = newWidth; }
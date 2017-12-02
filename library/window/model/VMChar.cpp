//
// Created by Slayorious on 2017-12-01.
//

#include "VMChar.h"

//VMChar::VMChar(char c, int colour, unsigned char width) : c{c}, colour{colour}, width{width} {}

VMChar::VMChar(char c, int colour, unsigned char width, size_t startPos) :
		c{c}, colour{colour}, width{width}, startPos{startPos} {}

char VMChar::getChar() { return c; }

void VMChar::setChar(char newC) { c = newC; }

int VMChar::getColour() { return colour; }

void VMChar::setColour(int newColour) { colour = newColour; }

size_t VMChar::getStartPos() { return startPos; }

void VMChar::setStartPos(size_t newStart) { startPos = newStart; }

unsigned char VMChar::getWidth() { return width; }

void VMChar::setWidth(unsigned char newWidth) { width = newWidth; }
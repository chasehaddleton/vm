//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_LINE_H
#define VM_LINE_H

#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include "VMChar.h"

class VMLine {
	std::list<VMChar> line;
	int DEFAUT_COLOUR = 0;
	//std::string line;

public:
    VMLine();

    explicit VMLine(std::string str);

	using iterator = std::list<VMChar>::iterator;               // our iterator is just lists's iterator
	using const_iterator = std::list<VMChar>::const_iterator;   // our const iterator is just list's const iterator

	void addChar(VMLine::iterator &it, char c);         // inserts the given character at the iterator position
	void removeChar(VMLine::const_iterator &it);        // removes the character at the given position
	void replaceChar(VMLine::iterator &it, char c);     // replaces the character at the given position
	size_t lineWidth();             // returns the sum of the widths of the elements in the line
	size_t length();                // returns the number of elements in the line
	size_t size();                  // returns the number of elements in the line
	std::string toString();         // returns line as a string
	std::string operator*();        // apparently, also returns line as a string (WHY CHASE? WHY?!)

	void updateStartPos(VMLine::iterator it);          // updates the start positions relative to the beginning
	size_t tabCount();              // returns number of tabs on line
	size_t tabCount(size_t pos);    // returns number of tabs prior to pos on line

	iterator begin();

	iterator end();

	const_iterator cbegin() const;

	const_iterator cend() const;

};

std::ostream &operator<<(std::ostream &out, VMLine line);

#endif //VM_LINE_H
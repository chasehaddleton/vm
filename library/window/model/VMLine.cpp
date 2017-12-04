//
// Created by Slayorious on 2017-11-26.
//

#include <string>
#include "VMLine.h"

VMLine::VMLine() = default;

VMLine::VMLine(std::string s) {
	size_t previousStartPos = 0;
	unsigned char previousWidth = 0;
	size_t startPos = 0;
	unsigned char width = 0;
	for (auto &c:s) {
		startPos = previousStartPos + previousWidth;
		if (c == '\t') {
			width = 8 - startPos % 8;
		} else {
			width = 1;
		}
		line.emplace_back(c, 0, startPos, width);
		previousStartPos = startPos;
		previousWidth = width;
	}
}

// adds the character at the given position
void VMLine::addChar(VMLine::iterator &it, char c) {
	unsigned char width = 1;
	size_t startPos;
	if (it == line.begin()) {
		startPos = 0;
	} else {
		std::advance(it, -1);
		startPos = it->getStartPos() + 1;
		std::advance(it, 1);
	}
	if (c == '\t') {
		width = 8 - startPos % 8;
	}
	line.insert(it, VMChar(c, DEFAUT_COLOUR, startPos, width));
	--it;
}

// removes the character at the given position
void VMLine::removeChar(VMLine::iterator &it) {
	VMChar tmp = *it;
	it = line.erase(it);
	VMLine::iterator updateIt = it;
	updateStartPos(updateIt);
}

// replaces the character at the given position
void VMLine::replaceChar(VMLine::iterator &it, char c) {
	VMChar tmp = *it;
	it->setChar(c);
	if (tmp.getChar() == '\t') { updateStartPos(it); }
}

// updates the start positions relative to the beginning
void VMLine::updateStartPos(VMLine::iterator &it) {
	size_t previousStartPos;
	unsigned char previousWidth;
	size_t newStartPos;
	unsigned char newWidth;
	std::ptrdiff_t count;
	// Get the information about the startPos of the previous character
	if (it != this->begin()) {
		std::advance(it, -1);
		previousStartPos = it->getStartPos();
		previousWidth = it->getWidth();
		std::advance(it, 1);
	} else {
		previousStartPos = 0;
		previousWidth = 0;
	}
	while (it != this->end()) {
		newStartPos = previousStartPos + previousWidth;
		if (newStartPos == it->getStartPos()) {
			break;
		} else {
			it->setStartPos(newStartPos);
			// If it's a tab, then it's width may have changed
			if (it->getChar() == '\t') {
				newWidth = 8 - newStartPos % 8;
			} else {
				newWidth = 1;
			}
			it->setWidth(newWidth);
			previousStartPos = newStartPos;
			previousWidth = newWidth;
			++it;
		}
	}
	//std::advance(it, -count);
}

// returns the number of tabs in the line
size_t VMLine::tabCount() const {
	size_t count = 0;
	for (auto c:line) {
		if (c.getChar() == '\t') ++count;
	}
	return count;
}

// returns the number of tabs prior to this position
size_t VMLine::tabCount(size_t pos) const {
	size_t count = 0;
	for (auto c:line) {
		if (c.getChar() == '\t') ++count;
	}
	return count;
}

// returns the sum of the widths of the line
size_t VMLine::lineWidth() const {
	size_t count = 0;
	if (!line.empty()) {
		for (auto &c: line) {
			count += c.getWidth();
		}
	}
	return count;
}

// returns teh nubmer of elements in the line
size_t VMLine::length() const {
	return line.size();
}

// returns the number of elements in the line
size_t VMLine::size() const {
	return line.size();
}

// returns the VMLine as a string
std::string VMLine::toString() const {
	if (line.empty()) return "";

	std::string tmp{};


	for (auto &c:line) {
		tmp.push_back(c.getChar());
	}

	return tmp;
}

// returns the VMLine as a string
std::string VMLine::operator*() const {
    return toString();
}

VMLine::iterator VMLine::begin() { return line.begin(); }

VMLine::iterator VMLine::end() { return line.end(); }

VMLine::const_iterator VMLine::cbegin() const { return line.cbegin(); }

VMLine::const_iterator VMLine::cend() const { return line.cend(); }

// Returns true if the line is empty
bool VMLine::empty() const {
    return !size();
}

std::ostream &operator<<(std::ostream &out, VMLine l) {
    out << l.toString() << std::endl;
	return out;
}

//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_VMDATASOURCE_H
#define VM_VMDATASOURCE_H

//#include "../../abstractions/DataSource.h"
#include "VMLine.h"
#include <list>
#include <memory>

class VMDataSource {
	std::list<VMLine> lines;
	std::string fileName;

	void doSaveFile() const;

public:
	VMDataSource();

	explicit VMDataSource(const std::string &file);

	using iterator = std::list<VMLine>::iterator;
	using const_iterator = std::list<VMLine>::const_iterator;

	// Returns the number of lines in VMDataSource
	size_t size();

	// Adds a character to the line at the given lineIter position
	void addChar(VMDataSource::iterator &dsIter, VMLine::iterator &lineIter, char c);

	// Remove a character from the line at the given lineIter position
	void removeChar(VMDataSource::iterator &dsIter, VMLine::iterator &lineIter);

	// Replace the character at the given lineIter position
	void replaceChar(VMDataSource::iterator dsIter, VMLine::iterator lineIter, char c);

	// Joins all lines between two iterators, startIter must be before endIter or undefined behaviour
	void joinLines(VMDataSource::iterator startIter, VMDataSource::iterator endIter);

	// Empties the line pointed to by dsIter of all characters
	void emptyLine(VMDataSource::iterator dsIter);

	void addLine(VMDataSource::iterator &dsIter, const std::string &str);

	void addLine(VMDataSource::iterator &dsIter, VMLine line);

	VMDataSource::iterator removeLine(iterator it);

	void saveFile() const;

	void saveFile(std::string fileName);

	size_t size() const;

	iterator begin();

	iterator end();

	const_iterator cbegin() const;

	const_iterator cend() const;
};

std::ostream &operator<<(std::ostream &out, VMDataSource &ds);

#endif //VM_VMDATASOURCE_H
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

	//returns the number of lines in VMDataSource
	size_t size();

	void addChar(VMDataSource::iterator &dsIter, VMLine::iterator &lineIter, char c);

	void removeChar(VMDataSource::iterator &dsIter, VMLine::iterator &lineIter);

	void replaceChar(VMDataSource::iterator dsIter, VMLine::iterator lineIter, char c);

	void addLine(VMDataSource::iterator dsIter, const std::string &str);

	void addLine(VMDataSource::iterator dsIter, VMLine line);

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
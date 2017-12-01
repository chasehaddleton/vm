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
public:
	using iterator = std::list<VMLine>::iterator;
	using const_iterator = std::list<VMLine>::const_iterator;

    VMDataSource();
    explicit VMDataSource(const std::string &file);

    void addChar(iterator it, size_t linePos, char c);
    void removeChar(iterator it, size_t linePos);
    void addLine(iterator it, const std::string &str);

	void addLine(iterator it, VMLine line);

	VMLine removeLine(iterator it);

    void saveFile();
    void saveFile(std::string fileName);

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
};

std::ostream &operator<<(std::ostream &out, VMDataSource &ds);

#endif //VM_VMDATASOURCE_H
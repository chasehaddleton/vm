//
// Created by Slayorious on 2017-11-26.
//

#include <fstream>
#include "VMDataSource.h"

VMDataSource::VMDataSource() {
	lines.emplace_front(new VMLine(""));
}

VMDataSource::VMDataSource(const std::string &name) : fileName{name} {
	std::ifstream f{name};
	std::string line;
	// Check if failbit was set on ifstream
	if (f.failbit) {
		throw std::invalid_argument("No filename matching input!");
	}
		// Otherwise read file
	else {
		while (std::getline(f, line)) {
			lines.emplace_back(new VMLine(line));
		}
	}
	f.close();
}

// Add a character to the line pointed to by iterator at the given position
void VMDataSource::addChar(VMDataSource::iterator it, size_t linePos, char c) {
	(*it)->addChar(linePos, c);
}

// Remove the character at linePos in line pointed to by iterator
void VMDataSource::removeChar(VMDataSource::iterator it, size_t linePos) {
	(*it)->removeChar(linePos);
}

// Add a line at the given iterator position
void VMDataSource::addLine(VMDataSource::iterator it, const std::string &s) {
	lines.insert(it, std::unique_ptr<VMLine>{new VMLine(s)});
}

// Remove a line at the given iterator position and return it
std::unique_ptr<VMLine> VMDataSource::removeLine(VMDataSource::iterator it) {
	std::unique_ptr<VMLine> tmp{(*it).release()};
	lines.erase(it);
	return tmp;
}

void VMDataSource::saveFile() {
	saveFile(fileName);
}

void VMDataSource::saveFile(std::string file) {
	std::ofstream f(file);
	if (!f.failbit) {
		throw std::invalid_argument("ERROR WHILE TRYING TO SAVE FILE!");
	} else {
		fileName = file;
		for (auto &line:lines) {
			f << *line << std::endl;
		}
	}
	f.close();
}

// Return an iterator at the beginning of DataSource
VMDataSource::iterator VMDataSource::begin() { return lines.begin(); }

// Return an iterator at the end of DataSource
VMDataSource::iterator VMDataSource::end() { return lines.end(); }

// Return a const iterator at the beginning of the DataSource
VMDataSource::const_iterator VMDataSource::cbegin() const { return lines.cbegin(); }

// Return a const iterator at the end of the DataSource
VMDataSource::const_iterator VMDataSource::cend() const { return lines.cend(); }

// Prints our DataSource to the provided output stream
std::ostream &operator<<(std::ostream &out, VMDataSource &ds) {
	for (auto &line:ds) {
		out << *line;
	}
	return out;
}



// SOME LEGACY CODE, DELETE BEFORE SUBMISSION!
/*
VMDataSource::iterator::iterator(std::list::iterator inputIt) { it = inputIt; }

bool VMDataSource::iterator::operator!=(const iterator &other) const { return *it != *other; }

VMLine &VMDataSource::iterator::operator*() const { return *it; }

VMLine *VMDataSource::iterator::operator->() const { return &*it; }

iterator VMDataSource::iterator::operator++() {
    ++it;
    return *this;
}

iterator VMDataSource::iterator::operator--() {
    --it;
    return *this;
}


iterator VMDataSource::createEnd() {
    VMDataSource::iterator(lines.begin());
}

iterator VMDataSource::createBegin() {
    VMDataSource::iterator(lines.end());
}*/
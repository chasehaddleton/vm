//
// Created by Slayorious on 2017-11-26.
//

#include <fstream>
#include "VMDataSource.h"

VMDataSource::VMDataSource() {
	lines.emplace_front("");
}

VMDataSource::VMDataSource(const std::string &name) : fileName{name} {
	std::ifstream f{name};
	std::string line;
	// Check if failbit was set on ifstream
	if (f.fail()) {
		throw std::invalid_argument("No filename matching input!");
	}
		// Otherwise read file
	else {
		while (std::getline(f, line)) {
			lines.emplace_back(line);
		}
	}
	f.close();
}

size_t VMDataSource::size() {
	return lines.size();
};

// Add a character to the line pointed to by iterator at the given position
void VMDataSource::addChar(VMDataSource::iterator dsIter, VMLine::iterator lineIter, char c) {
	dsIter->addChar(lineIter, c);
}

// Remove the character at insertPos in line pointed to by iterator
void VMDataSource::removeChar(VMDataSource::iterator dsIter, VMLine::iterator lineIter) {
	dsIter->removeChar(lineIter);
}

// Add a line at the given iterator position
void VMDataSource::addLine(VMDataSource::iterator dsIter, const std::string &s) {
	lines.insert(dsIter, VMLine(s));
}

// Add a line at the given iterator position
void VMDataSource::addLine(VMDataSource::iterator dsIter, VMLine line) {
	lines.insert(dsIter, line);
}

// Remove a line at the given iterator position and return it
VMDataSource::iterator VMDataSource::removeLine(VMDataSource::iterator it) {
	return lines.erase(it);
}

void VMDataSource::doSaveFile() const {
	std::ofstream f(fileName);
	if (f.fail()) {
		throw std::invalid_argument("ERROR WHILE TRYING TO SAVE FILE!");
	} else {
		for (auto &line:lines) {
			f << line.toString() << std::endl;
		}
	}
	f.close();
}

void VMDataSource::saveFile() const {
	doSaveFile();
}

void VMDataSource::saveFile(std::string file) {
	std::swap(fileName, file);
	doSaveFile();
	std::swap(fileName, file);
}

// Return an iterator at the beginning of DataSource
VMDataSource::iterator VMDataSource::begin() { return lines.begin(); }

// Return an iterator at the end of DataSource
VMDataSource::iterator VMDataSource::end() { return lines.end(); }

// Return a const iterator at the beginning of the DataSource
VMDataSource::const_iterator VMDataSource::cbegin() const { return lines.cbegin(); }

// Return a const iterator at the end of the DataSource
VMDataSource::const_iterator VMDataSource::cend() const { return lines.cend(); }

size_t VMDataSource::size() const {
	return lines.size();
}

// Prints our DataSource to the provided output stream
std::ostream &operator<<(std::ostream &out, VMDataSource &ds) {
	for (auto &line:ds) {
		out << *line;
	}
	return out;
}
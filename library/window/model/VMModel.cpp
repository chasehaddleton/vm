//
// Created by Slayorious on 2017-11-23.
//

#include "VMModel.h"

VMModel::VMModel() = default;

VMModel::VMModel(const std::string &fileName) : ds{fileName} {
}

void VMModel::addChar(size_t linePos, char c) {
	ds.addChar(cursor.getIT(), cursor.getLinePos(), c);
	cursor.moveDown();
}

void VMModel::removeChar(size_t linePos) {
	ds.removeChar(cursor.getIT(), cursor.getLinePos());
	cursor.moveUp();
}

void VMModel::removeLine() {
	ds.removeLine(cursor.getIT());
}

void VMModel::addLine(std::string s) {
	ds.addLine(cursor.getIT(), s);
}

void VMModel::redo() {}

void VMModel::undo() {}

void VMModel::saveFile() {
	try {
		ds.saveFile();
	}
	catch (std::invalid_argument &ia) {
		throw;
	}
}

VMDataSource::iterator VMModel::begin() {
	return ds.begin();
}

VMDataSource::iterator VMModel::end() {
	return ds.end();
}

Cursor &VMModel::getCursor() {
	return cursor;
}

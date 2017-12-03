//
// Created by Slayorious on 2017-11-23.
//

#include "VMModel.h"

VMModel::VMModel(const VMState &vmState) : vmStatus{vmState}, ds{vmState.getOpenFileName()}, cursor{ds, vmState} {}

// Adds a character at the current Cursor character position
void VMModel::addChar(char c) {
	// Adds a character at the current Cursor character position
	ds.addChar(cursor.getDSIter(), cursor.getLineIter(), c);
	cursor.moveRight();
}

// Removes the character at the current Cursor character position
void VMModel::removeChar() {
	ds.removeChar(cursor.getDSIter(), cursor.getLineIter());
	cursor.moveLeft();
}

// Adds a line at the current Cursor line position using a string as input
void VMModel::addLine(std::string s) {
	ds.addLine(cursor.getDSIter(), s);
}

void VMModel::addLine(VMLine line) {
	ds.addLine(cursor.getDSIter(), line);
}

// Remove the line at the current Cursor line position
void VMModel::removeLine() {
	ds.removeLine(cursor.getDSIter());
}

// Move the cursor left one character
void VMModel::moveCursorLeft() { cursor.moveLeft(); }

// Move the cursor right one character
void VMModel::moveCursorRight() { cursor.moveRight(); }

// Move the cursor up one line
void VMModel::moveCursorUp() { cursor.moveUp(); }

// Move the cursor down one line
void VMModel::moveCursorDown() { cursor.moveDown(); }

// Undo the last top-level command
void VMModel::undo() {}

// Redo the last undone command
void VMModel::redo() {}

// Output the DataSource's text to a file
void VMModel::saveFile() {
	try {
		ds.saveFile();
	}
	catch (std::invalid_argument &ia) {
		throw;
	}
}

VMDataSource::iterator VMModel::getDataSourceBegin() {
	return ds.begin();
}

VMDataSource::iterator VMModel::getDataSourceEnd() {
	return ds.end();
}


// Returns a reference to VMModel's Cursor
Cursor &VMModel::getCursor() {
	return cursor;
}

// Returns a reference to VMModel's DataSource
VMDataSource &VMModel::getDataSource() {
	return ds;
}

//
// Created by Slayorious on 2017-11-23.
//

#include "VMModel.h"

VMModel::VMModel(VMState &vmState) : state{vmState}, ds{vmState.getOpenFileName()}, cursor{ds, vmState} {}

// Adds a character at the current Cursor character position
void VMModel::addChar(int c) {
	// Adds a character at the current Cursor character position
	ds.addChar(cursor.getDSIter(), cursor.getLineIter(), c);
	cursor.moveRight();
	state.setFileModified(true);
}

// Removes the character at the current Cursor character position
void VMModel::removeChar() {
	if (!cursor.startOfData()) {
		if (!cursor.startOfLine()) {
			cursor.moveLeft();
			ds.removeChar(cursor.getDSIter(), cursor.getLineIter());
		}
			// If the cursor is at the start of the line, the line must be joined with the previous line
		else {
			VMDataSource::iterator firstLine = cursor.getDSIter();
			--firstLine;
			VMDataSource::iterator secondLine = cursor.getDSIter();
			cursor.moveUp();
			cursor.moveEOL();
			cursor.moveLeft();
			ds.joinLines(firstLine, secondLine);
			cursor.moveRight();
		}
	}
	// TODO: logic for not removing when at SOF
	state.setFileModified(true);
}

// Adds a line at the current Cursor line position using a string as input
void VMModel::addLine(std::string s) {
	ds.addLine(cursor.getDSIter(), s);
	state.setFileModified(true);
}

void VMModel::addLine(VMLine line) {
	ds.addLine(cursor.getDSIter(), line);
	state.setFileModified(true);
}

// Remove the line at the current Cursor line position
void VMModel::removeLine() {
	cursor.getDSIter() = ds.removeLine(cursor.getDSIter());
	cursor.getLineIter() = (*cursor.getDSIter()).begin();
	state.setFileModified(true);
}

// Move the cursor left one character
void VMModel::moveCursorLeft() { cursor.moveLeft(); }

// Move the cursor right one character
void VMModel::moveCursorRight() { cursor.moveRight(); }

// Move the cursor up one line
void VMModel::moveCursorUp() { cursor.moveUp(); }

// Move the cursor down one line
void VMModel::moveCursorDown() { cursor.moveDown(); }

// Move the cursor to the start of the line
void VMModel::moveCursorSOL() { cursor.moveSOL(); }

// Move the cursor to the end of the line
void VMModel::moveCursorEOL() { cursor.moveEOL(); }

// Undo the last top-level command
void VMModel::undo() {}

// Redo the last undone command
void VMModel::redo() {}

// Saves the current history
void VMModel::saveHistory() {}

// Output the DataSource's text to a file
void VMModel::saveFile() const {
	try {
		ds.saveFile();
		state.setFileModified(false);
	}
	catch (std::invalid_argument &ia) {
		throw;
	}
}

void VMModel::saveFile(std::string fileName) {
	try {
		ds.saveFile(fileName);
		state.setFileModified(false);
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

size_t VMModel::size() const {
	return ds.size();
}

void VMModel::replaceChar(int c) {
	ds.replaceChar(cursor.getDSIter(), cursor.getLineIter(), c);
}

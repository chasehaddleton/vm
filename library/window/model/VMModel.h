//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_VMMODEL_H
#define VM_VMMODEL_H

//#include "Model.h"
#include <memory>
#include "VMDataSource.h"
#include "../history/HistoryStack.h"
#include "../history/HistoryFrame.h"
#include "Cursor.h"
#include "../../status/VMState.h"

class VMModel {
	const VMState &vmStatus;
	VMDataSource ds;
	Cursor cursor;
	// TODO: Implement History
	//HistoryFrame undoFrame;
	//HistoryStack undoStack;
	// HistoryStack redoStack;
	// TODO: Implement StatusBar
	// InfoBar statusBar;

public:
	using dataSource = VMDataSource;

	explicit VMModel(const VMState &vmState);

	VMModel(const VMModel &other) = delete;

	VMModel &operator=(const VMModel &other) = delete;

	// Adds a character at the current Cursor character position
	void addChar(char c);

	// Removes the character at the current Cursor character position
	void removeChar();

	// Adds the next word in the line (CURRENTLY NOT NEEDED)
	void addWord(std::string);

	// Removes the next word in the line (CURRENTLY NOT NEEDED)
	void removeWord();

	// Adds a line at the current Cursor line position using a string as input
	void addLine(std::string s);

	// Adds a line at the current Cursor line position using a VMLine as input
	void addLine(VMLine line);

	// Remove the line at the current Cursor line position
	void removeLine();

	// Move the cursor left one character
	void moveCursorLeft();

	// Move the cursor right one character
	void moveCursorRight();

	// Move the cursor up one line
	void moveCursorUp();

	// Move the cursor down one line
	void moveCursorDown();

	// Undo the last top-level command
	void undo();

	// Redo the last undone command
	void redo();

	// Save the current HistoryFrame
	void saveHistFrame();

	// Output the DataSource's text to a file
	void saveFile() const;

	// Output the DataSource's text to a file with the given filename
	void saveFile(std::string fileName);

	// Returns an iterator at the beginning of the DataSource
	VMDataSource::iterator getDataSourceBegin();

	// Returns an iterator at the end of the DataSource
	VMDataSource::iterator getDataSourceEnd();

	// Returns a reference to VMModel's Cursor
	Cursor &getCursor();

	// Returns a reference to VMModel's DataSource
	VMDataSource &getDataSource();
};

#endif //VM_VMMODEL_H

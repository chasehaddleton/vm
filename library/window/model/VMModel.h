//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_VMMODEL_H
#define VM_VMMODEL_H

//#include "Model.h"
#include <memory>
#include "VMDataSource.h"
#include "../history/HistoryStack.h"
#include "Cursor.h"
#include "../../status/VMState.h"

class VMModel {
	const VMState &vmStatus;
	VMDataSource ds;
	Cursor cursor;
	// TODO: Implement History
	// HistoryStack undoStack;
	// HistoryStack redoStack;
	// TODO: Implement StatusBar
	// InfoBar statusBar;

public:
	using dataSource = VMDataSource;

	explicit VMModel(const VMState &vmStatus);

	VMModel(const VMModel &other) = delete;

	VMModel &operator=(const VMModel &other) = delete;

	void addChar(size_t linePos, char c);

	void removeChar(size_t linePos);

	void removeWord();

	void addWord(std::string);

	void addLine(std::string);

	void addLine(VMLine line);

	void removeLine();

	void undo();

	void redo();

	void saveHistFrame();

	void saveFile();

	void saveFile(std::string);

	void moveLeft();

	void moveRight();

	void moveUp();

	void moveDown();

	dataSource::iterator begin();

	dataSource::iterator end();

	Cursor *getCursor();

	VMDataSource *getDataSource();

};

#endif //VM_VMMODEL_H

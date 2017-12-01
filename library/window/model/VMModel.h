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

class VMModel {
	VMDataSource ds;
	Cursor cursor;
	// TODO: Implement History
	// HistoryStack undoStack;
	// HistoryStack redoStack;
	// TODO: Implement StatusBar
	// InfoBar statusBar;

public:
	using dataSource = VMDataSource;

	VMModel();

	explicit VMModel(const std::string &fileName);

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

	dataSource::iterator begin();

	dataSource::iterator end();

	Cursor &getCursor();

	VMDataSource &getDataSource();

};

#endif //VM_VMMODEL_H

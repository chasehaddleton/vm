//
// Created by Chase Haddleton on 2017-11-28.
//

#ifndef VM_VMWINDOW_H
#define VM_VMWINDOW_H

#include "model/VMModel.h"
#include "display/VMDisplay.h"
#include "../input/VMKeyboard.h"
#include <memory>
#include "model/Cursor.h"

class DataSource;

class VMWindow {
	VMKeyboard keyboard;
	VMKeyboard::Iterator keyIt;
	VMModel model;
	Cursor &cursor;
	VMDisplay display;

	int printStart = 0;

public:
	VMWindow();

	explicit VMWindow(std::string fileName);

	void run();

	bool handleInput(int ch);
};


#endif //VM_VMWINDOW_H

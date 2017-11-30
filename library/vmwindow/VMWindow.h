//
// Created by Chase Haddleton on 2017-11-28.
//

#ifndef VM_VMWINDOW_H
#define VM_VMWINDOW_H

#include "VMModel.h"
#include "VMDisplay.h"
#include "../input/VMKeyboard.h"
#include "../Point.h"
#include <memory>

class DataSource;

class VMWindow {
	std::shared_ptr<Point> cursorPosition;
	VMDisplay display;
	VMKeyboard keyboard;
	VMModel model;
	std::shared_ptr<DataSource> dataSource;
	std::shared_ptr<DataSource::Iterator> dsIt;
	int printStart = 0;

public:
	void run();

	bool handleInput(int ch);
};


#endif //VM_VMWINDOW_H

//
// Created by Chase Haddleton on 2017-11-16.
//

#ifndef VM_VMDISPLAY_H
#define VM_VMDISPLAY_H

#include <list>
#include <string>
#include "../../Point.h"
#include <memory>
#include "../../abstractions/Display.h"
#include "../model/VMModel.h"
#include "../model/Cursor.h"

class VMDisplay : public Display {
	using dataType = VMModel;
	using dataTypeIt = VMModel::dataSource::iterator;

	dataType &ds;
	Cursor &cursor;
	std::shared_ptr<int> printStart;

	int xSize = 0;
	int ySize = 0;

	void init();

	void end();

	void doUpdate() override;

public:

	VMDisplay(dataType &ds, Cursor &c);

	~VMDisplay();

	void resize();

	void print(std::string s, int y);

	bool handleInput(int ch);

	int getXSize() const;

	int getYSize() const;
};


#endif //VM_VMDISPLAY_H

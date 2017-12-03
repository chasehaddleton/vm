//
// Created by Chase Haddleton on 2017-11-16.
//

#ifndef VM_VMDISPLAY_H
#define VM_VMDISPLAY_H

#include <list>
#include <string>
#include <memory>
#include "../../abstractions/Display.h"
#include "../model/VMModel.h"
#include "../model/Cursor.h"
#include "../../status/VMState.h"

class VMDisplay : public Display {
	VMState &vmState;
	VMModel* m;

	bool enablePreProcessing = false;

	void init();

	void end();

	void doUpdate() override;

public:
	explicit VMDisplay(VMState &vmState);

	~VMDisplay();

	void bind(VMModel &vmModel);

	void resize();

	void print(std::string s, int y);
};


#endif //VM_VMDISPLAY_H

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
	VMState &state;
	VMModel* m;

	int xSize;
	int ySize;

	//bool enablePreProcessing = false;

	void init();

	void end();

	void doUpdate() const override;

	void print(std::string s, int y) const;

public:
	explicit VMDisplay(VMState &vmState);

	~VMDisplay();

	void bind(VMModel &vmModel);

	void resize();
};


#endif //VM_VMDISPLAY_H

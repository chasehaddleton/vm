//
// Created by Chase Haddleton on 2017-12-02.
//

#ifndef VM_VM_H
#define VM_VM_H

#include "status/VMState.h"
#include "abstractions/command/Command.h"
#include "window/display/VMDisplay.h"
#include "input/VMKeyboard.h"
#include <string>

class VM {
	std::vector<std::unique_ptr<Command>> commands;

	VMState state;
	VMDisplay display;
	VMKeyboard keyboard;

public:
	VM();

	void run(const std::string &fileName = "");
};


#endif //VM_VM_H

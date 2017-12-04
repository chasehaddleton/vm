//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_WRITEQUIT_H
#define VM_WRITEQUIT_H


#include "../abstractions/command/Command.h"

class Write;
class Quit;

class WriteQuit : public Command {
	std::unique_ptr<Write> save;
	std::unique_ptr<Quit> quit;

	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	WriteQuit(VMState &state, const std::string &name);
};


#endif //VM_WRITEQUIT_H

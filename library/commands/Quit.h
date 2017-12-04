//
// Created by Chase Haddleton on 2017-12-02.
//

#ifndef VM_EXIT_H
#define VM_EXIT_H


#include "../abstractions/command/Command.h"

class Quit : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	Quit(VMState &vmState, const std::string &name);
};


#endif //VM_EXIT_H

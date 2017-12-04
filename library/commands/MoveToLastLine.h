//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_JUMPTOLASTLINE_H
#define VM_JUMPTOLASTLINE_H


#include "../abstractions/command/Command.h"

class MoveToLastLine : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	MoveToLastLine(VMState &state, const std::string &name);
};


#endif //VM_JUMPTOLASTLINE_H

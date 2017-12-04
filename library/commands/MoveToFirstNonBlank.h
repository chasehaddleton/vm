//
// Created by Chase Haddleton on 2017-12-04.
//

#ifndef VM_MOVETOFIRSTNONBLANK_H
#define VM_MOVETOFIRSTNONBLANK_H


#include "../abstractions/command/Command.h"

class MoveToFirstNonBlank : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	MoveToFirstNonBlank(VMState &state, const std::string &name);

};


#endif //VM_MOVETOFIRSTNONBLANK_H

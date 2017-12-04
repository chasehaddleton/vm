//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_SCROLLDOWNLINE_H
#define VM_SCROLLDOWNLINE_H


#include "../abstractions/command/Command.h"

class ScrollDownLine : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	ScrollDownLine(VMState &state, const std::string &name);
};


#endif //VM_SCROLLDOWNLINE_H

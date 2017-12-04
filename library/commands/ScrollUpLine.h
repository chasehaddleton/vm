//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_SCROLLUPLINE_H
#define VM_SCROLLUPLINE_H


#include "../abstractions/command/Command.h"

class ScrollUpLine : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	ScrollUpLine(VMState &state, const std::string &name);
};


#endif //VM_SCROLLUPLINE_H

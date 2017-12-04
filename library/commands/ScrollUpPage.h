//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_SCROLLUPPAGE_H
#define VM_SCROLLUPPAGE_H


#include "../abstractions/command/Command.h"

class ScrollUpPage : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	ScrollUpPage(VMState &state, const std::string &name);
};


#endif //VM_SCROLLUPPAGE_H

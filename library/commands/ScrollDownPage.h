//
// Created by Chase Haddleton on 2017-12-04.
//

#ifndef VM_SCROLLDOWNPAGE_H
#define VM_SCROLLDOWNPAGE_H


#include "../abstractions/command/Command.h"

class ScrollDownPage: public Command{
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	ScrollDownPage(VMState &state, const std::string &name);
};


#endif //VM_SCROLLDOWNPAGE_H

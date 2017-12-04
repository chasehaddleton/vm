//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_TOP_H
#define VM_TOP_H

#include "../abstractions/command/Command.h"
#include <regex>

class MoveToLineNum  : public Command {
	std::regex partialMatch{"(:[-]{0,1}[0-9]*)"};

	MatchType doMatch(const std::string &s) const override;

	void doExecute(const std::string &command, VMModel &model, int count) const override;

public:
	MoveToLineNum(VMState &state, const std::string &name);
};


#endif //VM_TOP_H

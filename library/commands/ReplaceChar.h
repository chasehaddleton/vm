//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_REPLACECHAR_H
#define VM_REPLACECHAR_H


#include "../abstractions/command/Command.h"

class ReplaceChar : public Command {
	MatchType doMatch(const std::string &s) const override;

	void doExecute(const std::string &command, VMModel &model, int count) const override;

public:
	ReplaceChar(VMState &state, const std::string &name);
};


#endif //VM_REPLACECHAR_H

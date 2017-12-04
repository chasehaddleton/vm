//
// Created by Slayorious on 2017-12-03.
//

#ifndef VM_STARTOFLINE_H
#define VM_STARTOFLINE_H

#include "../abstractions/command/Command.h"

class StartOfLine : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	StartOfLine(VMState &vmState, const std::string &name);
};

#endif //VM_STARTOFLINE_H

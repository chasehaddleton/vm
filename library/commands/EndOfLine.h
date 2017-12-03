//
// Created by Slayorious on 2017-12-03.
//

#ifndef VM_ENDOFLINE_H
#define VM_ENDOFLINE_H

#include "../abstractions/command/Command.h"

class EndOfLine : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	EndOfLine(VMState &vmState, const std::string &name);
};

#endif //VM_ENDOFLINE_H

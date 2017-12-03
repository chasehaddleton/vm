//
// Created by Slayorious on 2017-12-03.
//

#ifndef VM_MOTIONWORD_H
#define VM_MOTIONWORD_H

#include "../abstractions/command/Command.h"

class MotionWord : Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	MotionWord(VMState &vmState, const std::string &name);
};

#endif //VM_MOTIONWORD_H

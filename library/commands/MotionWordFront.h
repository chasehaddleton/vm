//
// Created by Slayorious on 2017-12-03.
//

#ifndef VM_MOTIONWORDFRONT_H
#define VM_MOTIONWORDFRONT_H

#include "../abstractions/command/Command.h"

class MotionWordFront : Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	MotionWordFront(VMState &vmState, const std::string &name);
};

#endif //VM_MOTIONWORDFRONT_H

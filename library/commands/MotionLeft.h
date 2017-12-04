//
// Created by Slayorious on 2017-12-03.
//

#ifndef VM_MOTIONLEFT_H
#define VM_MOTIONLEFT_H

#include "../abstractions/command/Command.h"

class MotionLeft : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	virtual MatchType doMatch(const std::string &s) const override;

public:
	MotionLeft(VMState &vmState, const std::string &name);
};

#endif //VM_MOTIONLEFT_H

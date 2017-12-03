//
// Created by Slayorious on 2017-12-03.
//

#ifndef VM_MOTIONDOWN_H
#define VM_MOTIONDOWN_H

#include "../abstractions/command/Command.h"

class MotionDown : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	virtual MatchType doMatch(const std::string &s) const override;

public:
	MotionDown(VMState &vmState, const std::string &name);
};

#endif //VM_MOTIONDOWN_H

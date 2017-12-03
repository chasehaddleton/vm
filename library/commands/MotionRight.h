//
// Created by Slayorious on 2017-12-03.
//

#ifndef VM_MOTIONRIGHT_H
#define VM_MOTIONRIGHT_H

#include "../abstractions/command/Command.h"

class MotionRight : public Command {

	void doExecute(const std::string &command, VMModel &model) const override;

	virtual MatchType doMatch(const std::string &s) const override;

public:
	MotionRight(VMState &vmState, const std::string &name);
};

#endif //VM_MOTIONRIGHT_H

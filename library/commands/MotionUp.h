//
// Created by Slayorious on 2017-12-03.
//

#ifndef VM_MOTIONUP_H
#define VM_MOTIONUP_H

#include "../abstractions/command/Command.h"

class MotionUp : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	MotionUp(VMState &vmState, const std::string &name);
};

#endif //VM_MOTIONUP_H

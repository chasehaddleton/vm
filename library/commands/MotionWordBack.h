//
// Created by Slayorious on 2017-12-03.
//

#ifndef VM_MOTIONWORDBACK_H
#define VM_MOTIONWORDBACK_H

#include "../abstractions/command/Command.h"

class MotionWordBack : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	// Moves to the start of the previous "word"
	void moveToPreviousWord(VMModel &model) const;

	MatchType doMatch(const std::string &s) const override;

public:
	MotionWordBack(VMState &vmState, const std::string &name);
};

#endif //VM_MOTIONWORDBACK_H

//
// Created by Slayorious on 2017-12-03.
//

#include "MotionUp.h"

void MotionUp::doExecute(const std::string &command, VMModel &model) const {
	model.moveCursorUp();
}

MatchType MotionUp::doMatch(const std::string &s) const {
	if (s == "k") {
		return MatchType::FULL;
	}
	return MatchType::NONE;
}


MotionUp::MotionUp(VMState &vmState, const std::string &name) : Command(vmState, name) {}
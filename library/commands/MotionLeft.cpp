//
// Created by Slayorious on 2017-12-03.
//

#include "MotionLeft.h"

void MotionLeft::doExecute(const std::string &command, VMModel &model) const {
	model.moveCursorLeft();
}

MatchType MotionLeft::doMatch(const std::string &s) const {
	if (s == "h") {
		return MatchType::FULL;
	}
	return MatchType::NONE;
}


MotionLeft::MotionLeft(VMState &vmState, const std::string &name) : Command(vmState, name) {}
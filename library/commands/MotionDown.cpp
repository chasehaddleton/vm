//
// Created by Slayorious on 2017-12-03.
//

#include "MotionDown.h"

void MotionDown::doExecute(const std::string &command, VMModel &model) const {
	model.moveCursorDown();
}

MatchType MotionDown::doMatch(const std::string &s) const {
	if (s == "j") {
		return MatchType::FULL;
	}
	return MatchType::NONE;
}


MotionDown::MotionDown(VMState &vmState, const std::string &name) : Command(vmState, name) {}
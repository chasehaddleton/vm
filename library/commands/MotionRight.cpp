//
// Created by Slayorious on 2017-12-03.
//

#include "MotionRight.h"

void MotionRight::doExecute(const std::string &command, VMModel &model) const {
	model.moveCursorRight();
}

MatchType MotionRight::doMatch(const std::string &s) const {
	if (s == "l") {
		return MatchType::FULL;
	}
	return MatchType::NONE;
}


MotionRight::MotionRight(VMState &vmState, const std::string &name) : Command(vmState, name) {}
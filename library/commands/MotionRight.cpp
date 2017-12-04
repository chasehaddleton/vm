//
// Created by Slayorious on 2017-12-03.
//

#include "MotionRight.h"
#include "../input/VMKeyMap.h"

void MotionRight::doExecute(const std::string &command, VMModel &model, int count) const {
	for (int i = 0; i < count; ++i) model.moveCursorRight();
}

MatchType MotionRight::doMatch(const std::string &s) const {
	if (s == "l" || VMKeyMap::RIGHT) { return MatchType::FULL; }
	return MatchType::NONE;
}


MotionRight::MotionRight(VMState &vmState, const std::string &name) : Command(vmState, name) {}
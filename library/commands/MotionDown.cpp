//
// Created by Slayorious on 2017-12-03.
//

#include "MotionDown.h"
#include "../input/VMKeyMap.h"

void MotionDown::doExecute(const std::string &command, VMModel &model, int count) const {
	for (int i = 0; i < count; ++i) model.moveCursorDown();
}

MatchType MotionDown::doMatch(const std::string &s) const {
	if (s == "j" || VMKeyMap::DOWN) { return MatchType::FULL; }
	return MatchType::NONE;
}


MotionDown::MotionDown(VMState &vmState, const std::string &name) : Command(vmState, name) {}
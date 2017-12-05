//
// Created by Slayorious on 2017-12-03.
//

#include "MotionLeft.h"
#include "../input/VMKeyMap.h"

void MotionLeft::doExecute(const std::string &command, VMModel &model, int count) const {
	for (int i = 0; i < count; ++i) model.moveCursorLeft();
}

MatchType MotionLeft::doMatch(const std::string &s) const {
	if (s == "h" || (!s.empty() && s.at(0) == VMKeyMap::LEFT)) { return MatchType::FULL; }
	return MatchType::NONE;
}


MotionLeft::MotionLeft(VMState &vmState, const std::string &name) : Command(vmState, name) {}
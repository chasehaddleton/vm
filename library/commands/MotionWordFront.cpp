//
// Created by Slayorious on 2017-12-03.
//

#include "MotionWordFront.h"

void MotionWordFront::doExecute(const std::string &command, VMModel &model, int count) const {

}

MatchType MotionWordFront::doMatch(const std::string &s) const {
	if (s == "w") { return MatchType::FULL; }
	return MatchType::NONE;
}

MotionWordFront::MotionWordFront(VMState &vmState, const std::string &name) : Command(vmState, name) {}
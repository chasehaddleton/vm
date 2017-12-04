//
// Created by Slayorious on 2017-12-03.
//

#include "MotionWord.h"

void MotionWord::doExecute(const std::string &command, VMModel &model, int count) const {
	// TODO: determine is this is a better way
	// My instinct says no because even though there's better code re-use, there's less modularity. What if
	//   someone wants to disable moving in one direction?
}

MatchType MotionWord::doMatch(const std::string &s) const {
	if (s == "b" || "w") { return MatchType::FULL; }
	return MatchType::NONE;
}

MotionWord::MotionWord(VMState &vmState, const std::string &name) : Command(vmState, name) {}
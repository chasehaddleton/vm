//
// Created by Slayorious on 2017-12-03.
//

#include "Insert.h"

void Insert::doExecute(const std::string &command, VMModel &model, int count) const {
	state.setMode(ModeType::INSERT);
	state.setEnableHistorySave(false);
	state.resetCommandState();
	state.addChar(count);
}

MatchType Insert::doMatch(const std::string &s) const {
	if (s == "i") { return MatchType::FULL; }
	return MatchType::NONE;
}


Insert::Insert(VMState &vmState, const std::string &name) : Command(vmState, name) {}
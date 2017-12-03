//
// Created by Chase Haddleton on 2017-12-02.
//

#include "Exit.h"

void Exit::doExecute(const std::string &command, VMModel &model) const {
	state.setRunning(false);
}

MatchType Exit::doMatch(const std::string &s) const {
	if (s == ":") {
		return MatchType::PARTIAL;
	} else if (s == ":q") {
		return MatchType::FULL;
	} else {
		return MatchType::NONE;
	}
}

Exit::Exit(VMState &vmState, const std::string &name) : Command(vmState, name) {}

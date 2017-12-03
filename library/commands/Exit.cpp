//
// Created by Chase Haddleton on 2017-12-02.
//

#include "Exit.h"
#include "../input/VMKeyMap.h"

void Exit::doExecute(const std::string &command, VMModel &model) const {
	if (state.isFileModified()) {
		// TODO: implement some alert on the status bar
	} else {
		state.setRunning(false);
	}
}

MatchType Exit::doMatch(const std::string &s) const {
	if (s == ":" || s == partialMatch) {
		return MatchType::PARTIAL;
	} else if (s.size() == 3 && s.substr(0, partialMatch.size()) == partialMatch) {
		if (s.at(2) == VMKeyMap::ENTER || s.at(2) == VMKeyMap::ENTER_ASCII) return MatchType::FULL;
	}
	return MatchType::NONE;
}

Exit::Exit(VMState &vmState, const std::string &name) : Command(vmState, name) {
	partialMatch = ":q";
}

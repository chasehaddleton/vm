//
// Created by Chase Haddleton on 2017-12-02.
//

#include "Exit.h"
#include "../input/VMKeyMap.h"

void Exit::doExecute(const std::string &command, VMModel &model, int count) const {
	if (state.isFileModified() && command != (":q!" + VMKeyMap::ENTER)) {
		state.getStatusBar().setMessage("ERR: file modified, save or use ! to override");
		return;
	}

	state.setRunning(false);
}

MatchType Exit::doMatch(const std::string &s) const {
	if (s == ":" || s == ":q") {
		return MatchType::PARTIAL;
	}

	if (s == ":q!") {
		return MatchType::PARTIAL;
	} else if (s == (":q!" + VMKeyMap::ENTER) || s == (":q" + VMKeyMap::ENTER)) {
		return MatchType::FULL;
	}

	return MatchType::NONE;
}

Exit::Exit(VMState &vmState, const std::string &name) : Command(vmState, name) {}

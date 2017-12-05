//
// Created by Chase Haddleton on 2017-12-02.
//

#include "Quit.h"
#include "../input/VMKeyMap.h"

void Quit::doExecute(const std::string &command, VMModel &model, int count) const {
	if (state.isFileModified() && command != (":q!" + VMKeyMap::ENTER)) {
		state.getStatusBar().setMessage("ERR: file modified, save or use ! to override");
		return;
	}

	state.setRunning(false);
}

MatchType Quit::doMatch(const std::string &s) const {
	if (s == (":q!" + VMKeyMap::ENTER) || s == (":q" + VMKeyMap::ENTER)) {
		return MatchType::FULL;
	} else if (s == ":" || s == ":q" || s == ":q!") {
		return MatchType::PARTIAL;
	}

	return MatchType::NONE;
}

Quit::Quit(VMState &vmState, const std::string &name) : Command(vmState, name) {}

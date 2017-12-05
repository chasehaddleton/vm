//
// Created by Chase Haddleton on 2017-12-03.
//

#include "WriteQuit.h"
#include "Write.h"
#include "Quit.h"
#include "../input/VMKeyMap.h"

void WriteQuit::doExecute(const std::string &command, VMModel &model, int count) const {
	if (state.getOpenFileName().empty()) {
		state.getStatusBar().setMessage("Error, write with :w to give file name");
	} else {
		save->execute(":w", model, count);
		quit->execute(":q", model, count);
	}
}

MatchType WriteQuit::doMatch(const std::string &s) const {
	if (s == ":" || s == ":w" || s == ":wq") {
		return MatchType::PARTIAL;
	} else if (s == (":wq" + VMKeyMap::ENTER)) {
		return MatchType::FULL;
	} else {
		return MatchType::NONE;
	}
}

WriteQuit::WriteQuit(VMState &state, const std::string &name) : Command(state, name), save{new Write{state, "Write"}},
                                                                quit{new Quit{state, "Quit"}} {}

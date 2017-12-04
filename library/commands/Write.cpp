//
// Created by Chase Haddleton on 2017-12-03.
//

#include "Write.h"

#include "../input/VMKeyMap.h"

void Write::doExecute(const std::string &command, VMModel &model, int count) const {
	if (command.size() > 3) {
		model.saveFile(command.substr(3, command.size() - 3 - 2));
	} else if (state.isFileModified()) {
		model.saveFile();
	}
}

MatchType Write::doMatch(const std::string &s) const {
	if (s == ":" || s == ":w" || s == ":w ") {
		return MatchType::PARTIAL;
	}
	if (s.size() > 3) {
		// use the rest as a new file name, as long as the last char is enter
		if (s.substr(0, 3) == ":w " && s.substr(s.length() - 2) == VMKeyMap::ENTER) {
			return MatchType::FULL;
		} else {
			return MatchType::PARTIAL;
		}
	} else if (s == (":w" + VMKeyMap::ENTER)) {
		// Extra key should be enter
		return MatchType::FULL;
	}

	return MatchType::NONE;
}

Write::Write(VMState &vmState, const std::string &name) : Command(vmState, name) {}

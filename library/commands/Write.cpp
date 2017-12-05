//
// Created by Chase Haddleton on 2017-12-03.
//

#include "Write.h"

#include "../input/VMKeyMap.h"

void Write::doExecute(const std::string &command, VMModel &model, int count) const {
	std::smatch match;

	if (std::regex_match(command, match, std::regex{":w[ ]+?([\\w.]+?)\\" + VMKeyMap::ENTER})) {
		// file name given
		model.saveFile(match[1]);
	} else {
		if (state.getOpenFileName().empty()) {
			state.getStatusBar().setMessage("Error, file name required");
		} else {
			model.saveFile();
		}
	}
}

MatchType Write::doMatch(const std::string &s) const {
	if (std::regex_match(s, fullMatch)) {
		return MatchType::FULL;
	} else if (std::regex_match(s, partialMatch)) {
		return MatchType::PARTIAL;
	}
	return MatchType::NONE;
}

Write::Write(VMState &vmState, const std::string &name) : Command(vmState, name) {}

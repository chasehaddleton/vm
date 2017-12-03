//
// Created by Chase Haddleton on 2017-12-03.
//

#include "Save.h"

#include "../input/VMKeyMap.h"

void Save::doExecute(const std::string &command, VMModel &model) const {
	if (command.size() > 3) {
		model.saveFile(command.substr(3));
	} else {
		model.saveFile();
	}
}

MatchType Save::doMatch(const std::string &s) const {
	if (s == ":" || s == partialMatch) {
		return MatchType::PARTIAL;
	} else if (s.size() > partialMatch.size() && s.substr(0, partialMatch.size()) == partialMatch) {
		if (s.size() > 3) {
			// use the rest as a new file name, as long as the last char is enter
			if (s.back() == VMKeyMap::ENTER || s.back() == VMKeyMap::ENTER_ASCII) {
				return MatchType::FULL;
			} else {
				return MatchType::PARTIAL;
			}
		} else {
			// Extra key should be enter
			if (s.at(2) == VMKeyMap::ENTER || s.at(2) == VMKeyMap::ENTER_ASCII) {
				return MatchType::FULL;
			}
		}
	}
	return MatchType::NONE;
}

Save::Save(VMState &vmState, const std::string &name) : Command(vmState, name) {
	partialMatch = ":w";
}

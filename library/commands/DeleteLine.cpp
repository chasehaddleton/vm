//
// Created by Chase Haddleton on 2017-12-03.
//

#include "DeleteLine.h"

DeleteLine::DeleteLine(VMState &state, const std::string &name) : Command(state, name) {}

void DeleteLine::doExecute(const std::string &command, VMModel &model, int count) const {
	for (int i = 0; i < count; ++i) {
		model.removeLine();
	}
}

MatchType DeleteLine::doMatch(const std::string &s) const {
	if (s == "d") return MatchType::PARTIAL;
	else if (s == "dd") return MatchType::FULL;
	else return MatchType::NONE;
}

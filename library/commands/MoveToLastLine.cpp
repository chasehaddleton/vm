//
// Created by Chase Haddleton on 2017-12-03.
//

#include "MoveToLastLine.h"
#include "../input/VMKeyMap.h"


MoveToLastLine::MoveToLastLine(VMState &state, const std::string &name) : Command(state, name) {}

void MoveToLastLine::doExecute(const std::string &command, VMModel &model, int count) const {
	model.getCursor().moveToLastLine();
}

MatchType MoveToLastLine::doMatch(const std::string &s) const {
	if (s == ":" || s == ":$") return MatchType::PARTIAL;
	else if (s == (":$" + VMKeyMap::ENTER)) return MatchType::FULL;
	else return MatchType::NONE;
}

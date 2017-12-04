//
// Created by Chase Haddleton on 2017-12-03.
//

#include "JumpToLastLine.h"


JumpToLastLine::JumpToLastLine(VMState &state, const std::string &name) : Command(state, name) {}

void JumpToLastLine::doExecute(const std::string &command, VMModel &model, int count) const {
	model.getCursor().moveToLastLine();
}

MatchType JumpToLastLine::doMatch(const std::string &s) const {
	if (s == ":") return MatchType::PARTIAL;
	else if (s == ":$") return MatchType::FULL;
	else return MatchType::NONE;
}

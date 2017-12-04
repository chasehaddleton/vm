//
// Created by Chase Haddleton on 2017-12-03.
//

#include "ReplaceChar.h"

ReplaceChar::ReplaceChar(VMState &state, const std::string &name) : Command(state, name) {}

void ReplaceChar::doExecute(const std::string &command, VMModel &model, int count) const {
	if (count > 1 && count + model.getCursor().getXPos() < model.getCursor().getDSIter()->size())  {
		for (int i = 0; i < count; ++i) {
			model.replaceChar(command.back());
			model.getCursor().moveRight();
		}
		model.getCursor().moveLeft();
	} else if (count == 1) {
		model.replaceChar(command.back());
	}
}

MatchType ReplaceChar::doMatch(const std::string &s) const {
	if (s == "r") return MatchType::PARTIAL;
	if (s.size() == 2 && s.at(0) == 'r') return MatchType::FULL;
	return MatchType::NONE;
}

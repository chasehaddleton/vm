//
// Created by Chase Haddleton on 2017-12-04.
//

#include "MoveToFirstNonBlank.h"

void MoveToFirstNonBlank::doExecute(const std::string &command, VMModel &model, int count) const {
	model.moveCursorSOL();

	auto it = model.getCursor().getLineIter();

	while (it != model.getCursor().getDSIter()->end()) {
		if (it->getChar() == ' ' || it->getChar() == '\t') {
			++it;
		} else {
			return;
		}
	}

	if (it == model.getCursor().getDSIter()->end()) model.moveCursorSOL();
}

MatchType MoveToFirstNonBlank::doMatch(const std::string &s) const {
	if (s == "^") return MatchType::FULL;
	return MatchType::NONE;
}

MoveToFirstNonBlank::MoveToFirstNonBlank(VMState &state, const std::string &name) : Command(state, name) {}

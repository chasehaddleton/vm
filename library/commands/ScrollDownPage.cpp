//
// Created by Chase Haddleton on 2017-12-04.
//

#include "ScrollDownPage.h"

ScrollDownPage::ScrollDownPage(VMState &state, const std::string &name) : Command(state, name) {}

void ScrollDownPage::doExecute(const std::string &command, VMModel &model, int count) const {
	for (int i = 0; i < count; ++i) {
		model.getCursor().movePageDown();
	}
}

MatchType ScrollDownPage::doMatch(const std::string &s) const {
	if (s == "^F") {
		return MatchType::FULL;
	} else {
		return MatchType::NONE;
	}
}

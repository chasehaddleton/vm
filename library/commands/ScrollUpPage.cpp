//
// Created by Chase Haddleton on 2017-12-04.
//

#include "ScrollUpPage.h"

ScrollUpPage::ScrollUpPage(VMState &state, const std::string &name) : Command(state, name) {}

void ScrollUpPage::doExecute(const std::string &command, VMModel &model, int count) const {
	for (int i = 0; i < count; ++i) {
		if (model.getCursor().getFirstLineNumber() > 0) model.getCursor().movePageUp();
	}
}

MatchType ScrollUpPage::doMatch(const std::string &s) const {
	if (s == "^B") {
		return MatchType::FULL;
	} else {
		return MatchType::NONE;
	}
}

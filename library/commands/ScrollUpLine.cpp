//
// Created by Chase Haddleton on 2017-12-03.
//

#include "ScrollUpLine.h"

ScrollUpLine::ScrollUpLine(VMState &state, const std::string &name) : Command(state, name) {}

void ScrollUpLine::doExecute(const std::string &command, VMModel &model, int count) const {
	if (count != 1) {
		state.setScrollAmount(count);
	}

	for (int i = 0; i < state.getScrollAmount(); ++i) {
		model.getCursor().moveFrameUp();
	}
}

MatchType ScrollUpLine::doMatch(const std::string &s) const {
	if (s == "^U") {
		return MatchType::FULL;
	} else {
		return MatchType::NONE;
	}
}

//
// Created by Chase Haddleton on 2017-12-03.
//

#include "ScrollDownLine.h"

ScrollDownLine::ScrollDownLine(VMState &state, const std::string &name) : Command(state, name) {}

void ScrollDownLine::doExecute(const std::string &command, VMModel &model, int count) const {
	if (count != 1) {
		state.setScrollAmount(count);
	}

	for (int i = 0; i < state.getScrollAmount(); ++i) {
		model.getCursor().moveFrameDown();
	}
}

MatchType ScrollDownLine::doMatch(const std::string &s) const {
	if (s == "^D") {
		return MatchType::FULL;
	} else {
		return MatchType::NONE;
	}
}

//
// Created by Chase Haddleton on 2017-12-03.
//

#include <sstream>
#include "MoveToLineNum.h"
#include "../input/VMKeyMap.h"

MoveToLineNum::MoveToLineNum(VMState &state, const std::string &name) : Command(state, name) {}

void MoveToLineNum::doExecute(const std::string &command, VMModel &model, int count) const {
	std::stringstream ss(command.substr(1));
	ptrdiff_t lineNum;
	ss >> lineNum;

	if (lineNum < 0) {
		lineNum = std::max(size_t{0}, model.getCursor().getYPos() + lineNum + 1);
	}

	model.getCursor().moveToLine(static_cast<size_t>(lineNum));
}

MatchType MoveToLineNum::doMatch(const std::string &s) const {
	if (regex_match(s, partialMatch)) {
		return MatchType::PARTIAL;
	} else if (regex_match(s.substr(0, s.size() - 2), partialMatch) && s.substr(s.size() - 2) == VMKeyMap::ENTER) {
		return MatchType::FULL;
	} else {
		return MatchType::NONE;
	}
}

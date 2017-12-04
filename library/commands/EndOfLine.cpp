//
// Created by Slayorious on 2017-12-03.
//

#include "EndOfLine.h"

void EndOfLine::doExecute(const std::string &command, VMModel &model, int count) const {
	for (int i = 0; i < count - 1; ++i) { model.moveCursorDown(); }
	model.moveCursorEOL();
}

MatchType EndOfLine::doMatch(const std::string &s) const {
	if (s == "$") { return MatchType::FULL; }
	return MatchType::NONE;
}

EndOfLine::EndOfLine(VMState &vmState, const std::string &name) : Command(vmState, name) {}
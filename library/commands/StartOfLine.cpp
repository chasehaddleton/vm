//
// Created by Slayorious on 2017-12-03.
//

#include "StartOfLine.h"

void StartOfLine::doExecute(const std::string &command, VMModel &model, int count) const {
	model.moveCursorSOL();
}

MatchType StartOfLine::doMatch(const std::string &s) const {
	if (s == "0") { return MatchType::FULL; }
	return MatchType::NONE;
}

StartOfLine::StartOfLine(VMState &vmState, const std::string &name) : Command(vmState, name) {}

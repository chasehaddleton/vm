//
// Created by Chase Haddleton on 2017-11-18.
//

#include "CompositeCommand.h"

MatchType CompositeCommand::match(const std::string &s) const {
	return PARTIAL;
}

CompositeCommand::CompositeCommand(VMState &state, const std::string &name) : Command(state, name) {}

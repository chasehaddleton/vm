//
// Created by Chase Haddleton on 2017-11-18.
//

#include "Command.h"

Command::Command(VMState &state, const std::string &name) : state{state}, name{name} {}

void Command::execute(const std::string &command, VMModel &model) const {
	doExecute(command, model);
	notifyObservers();
}

MatchType Command::match(const std::string &s) const {
	return doMatch(s);
}

bool Command::operator==(const Command &other) const {
	return name == other.name;
}

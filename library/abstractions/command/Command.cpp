//
// Created by Chase Haddleton on 2017-11-18.
//

#include "Command.h"

void Command::execute(const std::string &command) const {
	doExecute(command);
}

MatchType Command::match(const std::string &s) const {
	return doMatch(s);
}
bool Command::operator==(const Command &other) const {
	return name == other.name;
}


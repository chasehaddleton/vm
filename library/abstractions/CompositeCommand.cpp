//
// Created by Chase Haddleton on 2017-11-18.
//

#include "CompositeCommand.h"

void CompositeCommand::doExecute(const std::string &command) const {

}

MatchType CompositeCommand::match(const std::string &s) const {
	return PARTIAL;
}

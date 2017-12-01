//
// Created by Chase Haddleton on 2017-11-18.
//

#ifndef VM_DELETE_H
#define VM_DELETE_H

#include "../abstractions/command/Command.h"

class Delete : public Command {
public:
	void doExecute(const std::string &command) const override;

	MatchType doMatch(const std::string &s) const override;
};

#endif //VM_DELETE_H

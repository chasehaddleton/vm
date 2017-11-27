//
// Created by Chase Haddleton on 2017-11-18.
//

#ifndef VM_COMMAND_H
#define VM_COMMAND_H

#include "../MatchType.h"
#include <string>
#include "../Point.h"
#include "../vmwindow/VMDisplay.h"

class Command {
	virtual void doExecute(const std::string &command) const = 0;

	virtual MatchType doMatch(const std::string &s) const = 0;

public:


	virtual ~Command() = default;

	virtual MatchType match(const std::string &s) const;

	void execute(const std::string &command) const;
};

#endif //VM_COMMAND_H
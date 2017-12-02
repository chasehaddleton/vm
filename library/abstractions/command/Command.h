//
// Created by Chase Haddleton on 2017-11-18.
//

#ifndef VM_COMMAND_H
#define VM_COMMAND_H

#include "../../MatchType.h"
#include <string>

class Command {
	std::string name;

	virtual void doExecute(const std::string &command) const = 0;

	virtual MatchType doMatch(const std::string &s) const = 0;

public:

	virtual ~Command() = default;

	virtual MatchType match(const std::string &s) const;

	void execute(const std::string &command) const;

	bool operator==(const Command &other) const;
};

#endif //VM_COMMAND_H

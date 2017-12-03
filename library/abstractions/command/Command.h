//
// Created by Chase Haddleton on 2017-11-18.
//

#ifndef VM_COMMAND_H
#define VM_COMMAND_H

#include "../../status/MatchType.h"
#include "../../status/VMState.h"
#include "../../window/model/VMModel.h"
#include "../observer/Subject.h"
#include <string>

class Command : public Subject {
	virtual void doExecute(const std::string &command, VMModel &model) const = 0;

	virtual MatchType doMatch(const std::string &s) const = 0;

protected:
	VMState &state;
	std::string name;

public:

	explicit Command(VMState &state, const std::string &name);

	virtual ~Command() = default;

	virtual MatchType match(const std::string &s) const;

	void execute(const std::string &command, VMModel &model) const;

	bool operator==(const Command &other) const;
};

#endif //VM_COMMAND_H

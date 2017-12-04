//
// Created by Slayorious on 2017-12-03.
//

#ifndef VM_INSERT_H
#define VM_INSERT_H

#include "../abstractions/command/Command.h"

class Insert : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	virtual MatchType doMatch(const std::string &s) const override;

public:
	Insert(VMState &vmState, const std::string &name);
};

#endif //VM_INSERT_H

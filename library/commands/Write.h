//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_SAVE_H
#define VM_SAVE_H


#include "../abstractions/command/Command.h"

class Write : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	Write(VMState &vmState, const std::string &name);
};


#endif //VM_SAVE_H

//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_DELETELINE_H
#define VM_DELETELINE_H


#include "../abstractions/command/Command.h"

class DeleteLine : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	DeleteLine(VMState &state, const std::string &name);
};


#endif //VM_DELETELINE_H

//
// Created by Chase Haddleton on 2017-11-18.
//

#ifndef VM_MOTIONCOMMAND_H
#define VM_MOTIONCOMMAND_H

#include "Command.h"
#include <memory>
#include <vector>

class CompositeCommand : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override = 0;

	MatchType doMatch(const std::string &s) const override = 0;

protected:
	std::vector<std::unique_ptr<Command>> subCommands; // This will hold the different motion commands

public:
	explicit CompositeCommand(VMState &state, const std::string &name);

	~CompositeCommand() override = default;
};

#endif //VM_MOTIONCOMMAND_H

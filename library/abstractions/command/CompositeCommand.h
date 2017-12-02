//
// Created by Chase Haddleton on 2017-11-18.
//

#ifndef VM_MOTIONCOMMAND_H
#define VM_MOTIONCOMMAND_H

#include "Command.h"
#include <memory>
#include <vector>

class CompositeCommand : Command {
	std::vector<std::unique_ptr<Command>> subCommands; // This will hold the different motion commands
	void doExecute(const std::string &command) const override;

public:
	~CompositeCommand() override = default;

	MatchType match(const std::string &s) const override;
};

#endif //VM_MOTIONCOMMAND_H

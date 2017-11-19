//
// Created by Chase Haddleton on 2017-11-18.
//

#ifndef VM_DELETE_H
#define VM_DELETE_H

#include "../abstractions/Command.h"
#include <memory>
#include <vector>

class DeleteMotion : public Command {
	std::vector<std::unique_ptr<Command>> subCommands; // This will hold the different motion commands

public:
	~DeleteMotion() override = default;

	MatchType match(const std::string &s) const override;

	void execute(const std::string &command) const override;
};


#endif //VM_DELETE_H

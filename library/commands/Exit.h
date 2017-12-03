//
// Created by Chase Haddleton on 2017-12-02.
//

#ifndef VM_EXIT_H
#define VM_EXIT_H


#include "../abstractions/command/Command.h"

class Exit : public Command {
	void doExecute(const std::string &command, VMModel &model) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	Exit(VMState &vmState, const std::string &name);
};


#endif //VM_EXIT_H

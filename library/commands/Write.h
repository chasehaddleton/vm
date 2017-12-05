//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_SAVE_H
#define VM_SAVE_H


#include <regex>
#include "../abstractions/command/Command.h"
#include "../input/VMKeyMap.h"

class Write : public Command {
	std::regex fullMatch{":w[ ]*?([\\w.]*?)\\" + VMKeyMap::ENTER};
	std::regex partialMatch{":w[ ]+?([\\w.]*?)"};

	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	Write(VMState &vmState, const std::string &name);
};


#endif //VM_SAVE_H

//
// Created by Chase Haddleton on 2017-12-04.
//

#ifndef VM_SEARCHBACKWARD_H
#define VM_SEARCHBACKWARD_H

#include <regex>
#include "../abstractions/command/Command.h"
#include "../input/VMKeyMap.h"

class SearchBackward : public Command {
	std::regex partialMatch{"(\\?(.*?))"};
	std::regex fullMatch{"\\?(.*?)\\" + VMKeyMap::ENTER};

	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	SearchBackward(VMState &state, const std::string &name);
};


#endif //VM_SEARCHBACKWARD_H

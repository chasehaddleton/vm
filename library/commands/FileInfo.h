//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_FILEINFO_H
#define VM_FILEINFO_H


#include "../abstractions/command/Command.h"

class FileInfo : public Command {
	void doExecute(const std::string &command, VMModel &model, int count) const override;

	MatchType doMatch(const std::string &s) const override;

public:
	explicit FileInfo(VMState &state, const std::string &name);

};

#endif //VM_FILEINFO_H

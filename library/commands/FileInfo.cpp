//
// Created by Chase Haddleton on 2017-12-03.
//

#include "FileInfo.h"
#include "../input/VMKeyMap.h"

void FileInfo::doExecute(const std::string &command, VMModel &model, int count) const {
	auto &sB = state.getStatusBar();
	auto &cur = model.getCursor();

	std::string msg = "\"" + state.getOpenFileName() + "\" ";
	msg += "line " + std::to_string(cur.getYPos() + 1) + " of " + std::to_string(model.size());
	msg += (state.isFileModified()) ? " EDITED" : " NOT EDITED";

	sB.setMessage(msg);
}

MatchType FileInfo::doMatch(const std::string &s) const {
	if (s == "^G") {
		return MatchType::FULL;
	} else {
		return MatchType::NONE;
	}
}

FileInfo::FileInfo(VMState &state, const std::string &name) : Command(state, name) {}

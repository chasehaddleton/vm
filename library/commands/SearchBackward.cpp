//
// Created by Chase Haddleton on 2017-12-04.
//

#include "SearchBackward.h"

void SearchBackward::doExecute(const std::string &command, VMModel &model, int count) const {
	std::smatch match;

	if (std::regex_match(command, match, fullMatch)) {
		std::regex userSearch{match.str(1)};
		auto tmpIt = model.getCursor().getDSIter();

		int matches = 0;
		bool freePass = true;
		size_t lineCounter = model.getCursor().getYPos() + 1;
		ptrdiff_t matchPos = 0;

		while (matches < count) {
			while (true) {
				std::smatch m;
				auto s = tmpIt->toString();

				if (std::regex_search(s, m, userSearch)) {
					++matches;
					if (count == matches) {
						matchPos = m.position(0);
						break;
					}
				}

				if (tmpIt != model.getDataSourceBegin()) {
					--tmpIt;
					--lineCounter;
				} else {
					break;
				}
			}

			if (matches != count && (freePass || matches > 0)) {
				freePass = false;
				tmpIt = --model.getDataSourceEnd();
				lineCounter = model.size();
				state.getStatusBar().setMessage("Search hit top, resuming from from");
			} else {
				break;
			}
		}

		if (matches > 0) {
			model.getCursor().moveToLine(lineCounter);

			while (matchPos > 0) {
				model.getCursor().moveRight();
				--matchPos;
			}
		} else {
			state.getStatusBar().setMessage("Error: pattern " + std::string{match.str(1)} + " not found");
		}
	}
}

MatchType SearchBackward::doMatch(const std::string &s) const {
	if (std::regex_match(s, fullMatch)) {
		return MatchType::FULL;
	} else if (std::regex_match(s, partialMatch)) {
		return MatchType::PARTIAL;
	} else {
		return MatchType::NONE;
	}
}

SearchBackward::SearchBackward(VMState &state, const std::string &name) : Command(state, name) {}

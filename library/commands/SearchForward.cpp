//
// Created by Chase Haddleton on 2017-12-04.
//

#include "SearchForward.h"

void SearchForward::doExecute(const std::string &command, VMModel &model, int count) const {
	std::smatch match;

	if (std::regex_match(command, match, fullMatch)) {
		std::regex userSearch{match.str(1)};
		auto tmpIt = model.getCursor().getDSIter();

		int matches = 0;
		bool freePass = true;
		size_t lineCounter = model.getCursor().getYPos();
		ptrdiff_t matchPos = 0;

		while (matches < count && tmpIt != model.getDataSourceEnd()) {
			while (tmpIt != model.getDataSourceEnd()) {
				std::smatch m;
				auto s = tmpIt->toString();

				if (std::regex_search(s, m, userSearch)) {
					++matches;
					if (count == matches) {
						matchPos = m.position(0);
						break;
					}
				}

				++tmpIt;
				++lineCounter;
			}

			if (matches != count && (freePass || matches > 0)) {
				freePass = false;
				tmpIt = model.getDataSourceBegin();
			}
		}

		if (matches > 0) {
			model.getCursor().moveToLine(lineCounter % model.size() + 1);

			while (matchPos > 0) {
				model.getCursor().moveRight();
				--matchPos;
			}
		} else {
			state.getStatusBar().setMessage("Error: pattern " + std::string{match.str(1)} + " not found");
		}
	}
}

MatchType SearchForward::doMatch(const std::string &s) const {
	if (std::regex_match(s, fullMatch)) {
		return MatchType::FULL;
	} else if (std::regex_match(s, partialMatch)) {
		return MatchType::PARTIAL;
	} else {
		return MatchType::NONE;
	}
}

SearchForward::SearchForward(VMState &state, const std::string &name) : Command(state, name) {}

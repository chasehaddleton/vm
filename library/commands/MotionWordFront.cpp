//
// Created by Slayorious on 2017-12-03.
//

#include <regex>
#include "MotionWordFront.h"
#include "CharType.h"

void MotionWordFront::doExecute(const std::string &command, VMModel &model, int count) const {
	bool movedDown = false;
	CharType wordType = CharType::BLANK;
	model.moveCursorRight();
	std::string currentChar;
	std::regex word("\w");
	std::regex blank("\s");

	// If we're not at the start of the file, there's more to do
	while (!model.getCursor().endOfData()) {
		currentChar = model.getCursor().getLineIter()->getChar();
		// Update the word type if we haven't already
		if (wordType == CharType::BLANK) {
			// If our new character is not blank, we update the character type
			if (regex_match(currentChar, word)) {
				wordType = CharType::WORD;
			}
			else if (!regex_match(currentChar, blank)) {
				wordType = CharType::NONWORD;
			}
		}
		// Update the position
		if (wordType == CharType::BLANK) {
			if (model.getCursor().endOfLine()) {
				// If we've moved down before we're done moving
				if (movedDown) {
					break;
				}
					// Otherwise move down a line
				else {
					model.getCursor().moveDown();
					model.getCursor().moveSOL();
					movedDown = true;
				}
			}
			else {
				model.getCursor().moveRight();
			}
		}
			// TODO: refactor this to something less stupid, dunno why I can't see it right now
		else if (wordType == CharType::WORD) {
			// If the current character is a word keep going right
			if (regex_match(currentChar, word)) {
				// If we're at the start of the line, we're done
				if (model.getCursor().endOfLine()) { break; }
					// Otherwise move the cursor right
				else { model.getCursor().moveRight(); }
			}
				// If the current character is not a word, we're done
			else {
				model.getCursor().moveLeft();
				break;
			}
		}
		else {
			// If the current character is a word or whitespace, we're done
			if (regex_match(currentChar, word) || regex_match(currentChar, blank)) {
				model.getCursor().moveLeft();
				break;
			}
			else {
				// If we're at the start of the line, we're done
				if (model.getCursor().endOfLine()) { break; }
					// Otherwise move the cursor right
				else { model.getCursor().moveRight(); }
			}
		}
	}
}

MatchType MotionWordFront::doMatch(const std::string &s) const {
	if (s == "w") { return MatchType::FULL; }
	return MatchType::NONE;
}

MotionWordFront::MotionWordFront(VMState &vmState, const std::string &name) : Command(vmState, name) {}
//
// Created by Slayorious on 2017-12-03.
//

#include <regex>
#include "MotionWordBack.h"
#include "CharType.h"

void MotionWordBack::doExecute(const std::string &command, VMModel &model, int count) const {
	for (int i = 0; i < count; ++i) {
		moveToPreviousWord(model);
	}
}

void MotionWordBack::moveToPreviousWord(VMModel &model) const {
	// Check until we hit start of line
	// If it's start of file, we don't move
	// If it's start of line, we move to the next line and back to the previous word
	// If it's white space, ignore it

	// Ignore whitespace until character
	// Check until we hit start of file or until the character type changes

	bool movedUp = false;
	CharType wordType = CharType::BLANK;
	model.moveCursorLeft();
	std::string currentChar;
	std::regex word("\w");
	std::regex blank("\s");

	// If we're not at the start of the file, there's more to do
	while (!model.getCursor().startOfData()) {
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
			if (model.getCursor().startOfLine()) {
				// If we've moved up before we're done moving
				if (movedUp) {
					break;
				}
					// Otherwise move up a line
				else {
					model.getCursor().moveUp();
					model.getCursor().moveEOL();
					movedUp = true;
				}
			}
			else {
				model.getCursor().moveLeft();
			}
		}
			// TODO: refactor this to something less stupid, dunno why I can't see it right now
		else if (wordType == CharType::WORD) {
			// If the current character is a word keep going left
			if (regex_match(currentChar, word)) {
				// If we're at the start of the line, we're done
				if (model.getCursor().startOfLine()) { break; }
					// Otherwise move the cursor left
				else { model.getCursor().moveLeft(); }
			}
				// If the current character is not a word, we're done
			else {
				model.getCursor().moveRight();
				break;
			}
		}
		else {
			// If the current character is a word or whitespace, we're done
			if (regex_match(currentChar, word) || regex_match(currentChar, blank)) {
				model.getCursor().moveRight();
				break;
			}
			else {
				// If we're at the start of the line, we're done
				if (model.getCursor().startOfLine()) { break; }
					// Otherwise move the cursor left
				else { model.getCursor().moveLeft(); }
			}
		}
	}
}

MatchType MotionWordBack::doMatch(const std::string &s) const {
	if (s == "b") { return MatchType::FULL; }
	return MatchType::NONE;
}

MotionWordBack::MotionWordBack(VMState &vmState, const std::string &name) : Command(vmState, name) {}
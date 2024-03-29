//
// Created by Chase Haddleton on 2017-12-02.
//

#include "VM.h"
#include "commands/Quit.h"
#include "commands/Write.h"
#include "commands/FileInfo.h"
#include "commands/DeleteLine.h"
#include "commands/WriteQuit.h"
#include "commands/ReplaceChar.h"
#include "commands/MoveToLineNum.h"
#include "commands/ScrollDownLine.h"
#include "commands/ScrollUpLine.h"
#include "commands/Insert.h"
#include "commands/MoveToLastLine.h"
#include "commands/ScrollDownPage.h"
#include "commands/ScrollUpPage.h"
#include "commands/MoveToFirstNonBlank.h"
#include "commands/SearchForward.h"
#include "commands/SearchBackward.h"
#include "commands/StartOfLine.h"
#include "commands/MotionWordFront.h"
#include "commands/MotionWordBack.h"
#include "commands/MotionUp.h"
#include "commands/MotionDown.h"
#include "commands/MotionLeft.h"
#include "commands/MotionRight.h"
#include "commands/EndOfLine.h"

bool VM::handleMoveCommand(const int &ch, VMModel &m) {
	if (ch == VMKeyboard::key.LEFT) {
		m.moveCursorLeft();
	} else if (ch == VMKeyboard::key.RIGHT) {
		m.moveCursorRight();
	} else if (ch == VMKeyboard::key.UP) {
		m.moveCursorUp();
	} else if (ch == VMKeyboard::key.DOWN) {
		m.moveCursorDown();
	} else {
		return false;
	}
	state.getStatusBar().clearMessage();
	return true;
}

void VM::run(const std::string &fileName) {
	state.setOpenFileName(fileName);
	VMModel model{state};
	state.bind(model);
	display.bind(model);

	auto vmkIt = keyboard.begin();
	int numExecutions = 0;
	int c;

	while (state.isRunning()) {
		display.update();
		c = *vmkIt;

		if (c == VMKeyboard::key.RESIZE) {
			display.resize();
			continue;
		}

		switch (state.getMode()) {
			case ModeType::COMMAND: {
				if (c == VMKeyboard::key.ESCAPE_ASCII) {
					// Special key which erases the current command, nothing else if then required to be done until
					// the next keypress

					state.resetCommandState();
					continue;
				} else if (c == VMKeyboard::key.DELETE_ASCII || c == VMKeyboard::key.DELETE) {
					if (!state.keyBuff.empty()) {
						state.keyBuff.removeLast();
					}
				} else {
					if (state.keyBuff.empty()) {
						// Check for special key-character/commands
						if (c == ':' || c == '/' || c == '?') {
							state.addChar(c);
							state.displayCommand();
							continue;
						} else if (handleMoveCommand(c, model)) {
							continue;
						} else if ('0' <= c && c <= '9' && (numExecutions == 0 && c != '0') ){
							numExecutions = numExecutions * 10 + (c - '0');
							continue;
						}
					}

					state.addChar(c);

					int commandMatch = 0;

					for (auto &x:commands) {
						int score = x->match(*state.keyBuff);

						if (score == MatchType::FULL) {
							state.hideCommand();
							x->execute(*state.keyBuff, model, numExecutions);

							// Command ran, reset state
							commandMatch = 0;
							break;
						} else {
							commandMatch += score;
						}
					}

					if (commandMatch == 0) {
						numExecutions = 0;
						state.resetCommandState();
					}
				}
				break;
			}
			case ModeType::INSERT: {
				//std::cout << VMKeyboard::key.ENTER_ASCII << std::flush;
				if (c == VMKeyboard::key.ESCAPE_ASCII) {
					state.setEnableHistorySave(true);
					model.saveHistory();
					state.setMode(ModeType::COMMAND);
					state.resetCommandState();
				} else if (handleMoveCommand(c, model)) {
					model.saveHistory();
				} else if ((' ' <= c) && (c <= '~')) {
					model.addChar(c);
					state.addChar(c);
				}
				else if (c == VMKeyboard::key.ENTER_ASCII) {
					model.addChar(c);
					state.addChar(c);
				}
				else if (c == VMKeyboard::key.DELETE_ASCII) {
					model.removeChar();
					state.addChar(c);
				} else {
					continue;
				}
			}
			case ModeType::MACRO_RECORD: {
				break;
			}
			case ModeType::MACRO_PLAYBACK: {
				break;
			}
		}

		++vmkIt;
	}
}

VM::VM() : state{}, display{state}, keyboard{} {
	commands.push_back(std::make_unique<Quit>(state, "Quit"));
	commands.push_back(std::make_unique<Write>(state, "Write"));
	commands.push_back(std::make_unique<Insert>(state, "Insert"));
	commands.push_back(std::make_unique<FileInfo>(state, "File Info"));
	commands.push_back(std::make_unique<DeleteLine>(state, "Delete Line"));
	commands.push_back(std::make_unique<WriteQuit>(state, "Write Quit"));
	commands.push_back(std::make_unique<ReplaceChar>(state, "Replace Char"));
	commands.push_back(std::make_unique<StartOfLine>(state, "Move to Start of Line"));
	commands.push_back(std::make_unique<MoveToLineNum>(state, "Move to Line Number"));
	commands.push_back(std::make_unique<MoveToLastLine>(state, "Move to the Last Line"));
	commands.push_back(std::make_unique<ScrollDownLine>(state, "Move the Frame Down"));
	commands.push_back(std::make_unique<ScrollUpLine>(state, "Move the Frame Up"));
	commands.push_back(std::make_unique<ScrollDownPage>(state, "Scroll Down a Page"));
	commands.push_back(std::make_unique<ScrollUpPage>(state, "Scroll Up a Page"));
	commands.push_back(std::make_unique<MoveToFirstNonBlank>(state, "Move to First Non Blank Line"));
	commands.push_back(std::make_unique<SearchForward>(state, "Search Forward"));
	commands.push_back(std::make_unique<SearchBackward>(state, "Search Backward"));
	commands.push_back(std::make_unique<MotionWordFront>(state, "Move Word Forward"));
	commands.push_back(std::make_unique<MotionWordBack>(state, "Move Word Back"));
	commands.push_back(std::make_unique<MotionUp>(state, "Move Up"));
	commands.push_back(std::make_unique<MotionDown>(state, "Move Down"));
	commands.push_back(std::make_unique<MotionLeft>(state, "Move Left"));
	commands.push_back(std::make_unique<MotionRight>(state, "Move Right"));
	commands.push_back(std::make_unique<EndOfLine>(state, "Move To End of Line"));
}

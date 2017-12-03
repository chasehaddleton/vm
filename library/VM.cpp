//
// Created by Chase Haddleton on 2017-12-02.
//

#include "VM.h"

bool handleMoveCommand(const int &ch, VMModel &m) {
	if (ch == VMKeyboard::key.LEFT) {
		m.moveCursorLeft();
	} else if (ch == VMKeyboard::key.RIGHT) {
		m.moveCursorRight();
	} else if (ch == VMKeyboard::key.UP) {
		m.moveCursorUp();
	} else if (ch == VMKeyboard::key.DOWN) {
		m.moveCursorRight();
	} else {
		return false;
	}

	return true;
}

void VM::run(const std::string &fileName) {
	state.setOpenFileName(fileName);
	VMModel model{state};
	display.bind(model);
	keyBuff = "";

	auto vmkIt = keyboard.begin();
	int numExecutions = 0;

	display.update();
	int c = *vmkIt;
	while (state.isRunning()) {
		if (c == VMKeyboard::key.RESIZE) {
			display.resize();
			continue;
		}

		switch (state.getMode()) {
			case ModeType::COMMAND: {
				if (c == VMKeyboard::key.ESCAPE) {
					// Special key which erases the current command, nothing else if then required to be done until
					// the next keypress

					state.setDisplayCommand(false);
					keyBuff.clear();
					continue;
				} else {
					if (keyBuff.empty()) {
						// Check for special key-character/commands
						if (c == ':') {
							state.setDisplayCommand(true);
							continue;
						} else if (handleMoveCommand(c, model)) {
							continue;
						} else if ('0' <= c && c <= '9') {
							numExecutions = numExecutions * 10 + (c - '0');
							continue;
						}
					} else if (keyBuff.size() == 2 && keyBuff.at(0) == 'q') {
						state.setRunning(false);
					}

					keyBuff.push_back(c);

					int commandMatch = 0;

					for (auto &x:commands) {
						int score = x.match(keyBuff);

						if (score == MatchType::FULL) {
							// TODO: make the command execute
							// TODO: move to insert mode if it's an insert command
							for (int i = 0; i < numExecutions; ++i) {
								x.execute(keyBuff);
							}

							// Command ran, clear it's content
							keyBuff.clear();
							numExecutions = 0;
						}

						commandMatch += score;
					}

					if (commandMatch == 0) {
						state.setDisplayCommand(false);
						keyBuff.clear();
					}

				}

				break;
			}
			case ModeType::INSERT: {

				break;
			}
			case ModeType::MACRO_RECORD: {
				break;
			}
			case ModeType::MACRO_PLAYBACK: {
				break;
			}
		}

		++vmkIt;
		c = *vmkIt;
		display.update();
	}
}

VM::VM() : state{}, display{state}, keyboard{} {}

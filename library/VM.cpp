//
// Created by Chase Haddleton on 2017-12-02.
//

#include "VM.h"

bool handleMoveCommand(const int &ch, VMModel &m) {
	if (ch == VMKeyboard::key.LEFT) {
		m.moveLeft();
	} else if (ch == VMKeyboard::key.RIGHT) {
		m.moveRight();
	} else if (ch == VMKeyboard::key.UP) {
		m.moveUp();
	} else if (ch == VMKeyboard::key.DOWN) {
		m.moveDown();
	} else {
		return false;
	}

	return true;
}

void VM::run(const std::string &fileName) {
	state.setOpenFileName(fileName);
	VMModel model{state};
	auto vmkIt = keyboard.begin();
	int numExecutions = 0;

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
						if (keyBuff.at(0) == ':') {
							state.setDisplayCommand(true);
							continue;
						} else if (handleMoveCommand(c, model)) {
							continue;
						} else if ('0' <= c && c <= '9') {
							numExecutions = numExecutions * 10 + (c - '0');
							continue;
						}
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
	}
}

VM::VM() : state{}, display{state}, keyboard{} {}

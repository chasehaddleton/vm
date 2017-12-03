//
// Created by Chase Haddleton on 2017-12-02.
//

#include "VM.h"
#include "commands/Exit.h"
#include "commands/Save.h"

bool handleMoveCommand(const int &ch, VMModel &m) {
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

	return true;
}

void VM::run(const std::string &fileName) {
	state.setOpenFileName(fileName);
	VMModel model{state};
	display.bind(model);
	state.getStatusBar().bind(state, model.getCursor());
	state.keyBuff = "";

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

					state.hideCommand();
					state.keyBuff.clear();
					continue;
				} else {
					if (state.keyBuff.empty()) {
						// Check for special key-character/commands
						if (c == ':') {
							state.displayCommand();
							state.addChar(c);
							continue;
						} else if (handleMoveCommand(c, model)) {
							continue;
						} else if ('0' <= c && c <= '9') {
							numExecutions = numExecutions * 10 + (c - '0');
							continue;
						}
					}

					state.addChar(c);

					int commandMatch = 0;

					for (auto &x:commands) {
						int score = x->match(state.keyBuff);

						if (score == MatchType::FULL) {
							numExecutions = std::max(1, numExecutions);

							// TODO: move to insert mode if it's an insert command
							for (int i = 0; i < numExecutions; ++i) {
								x->execute(state.keyBuff, model);
							}

							// Command ran, reset state
							commandMatch = 0;
							break;
						} else {
							commandMatch += score;
						}
					}

					if (commandMatch == 0) {
						numExecutions = 0;
						state.hideCommand();
						state.keyBuff.clear();
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
	}
}

VM::VM() : state{}, display{state}, keyboard{} {
	commands.push_back(std::make_unique<Exit>(state, "Exit"));
	commands.push_back(std::make_unique<Save>(state, "Save"));

}

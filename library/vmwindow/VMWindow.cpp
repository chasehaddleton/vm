//
// Created by Chase Haddleton on 2017-11-28.
//

#include "VMWindow.h"

void VMWindow::run() {

}

bool VMWindow::handleInput(int ch) {
	// TODO: fix up to not move to the end of the new line

	switch (ch) {
		case VMKeyboard::key.RESIZE:
			display.resize();
			break;
		case VMKeyboard::key.LEFT:
			if (cursorPosition->x != 0) {
				--cursorPosition->x;
			}
			break;
		case VMKeyboard::key.RIGHT:
			if (cursorPosition->x + 1 < dsIt->size()) {
				++cursorPosition->x;
			}
			break;
		case VMKeyboard::key.UP:
			if (cursorPosition->y > 0) {
				if (cursorPosition->y == printStart) {
					// printStart has room to move up
					--printStart;
				}

				--cursorPosition->y;
				--dsIt;

				if (dsIt->size() <= cursorPosition->x) {
					cursorPosition->x = static_cast<int>(dsIt->size()) - 1;
				}
			}
			break;
		case display.key.DOWN:
			if (cursorPosition->y + 1 < f->size()) {
				// Do not go past the end of the file
				if (printStart + display.getYSize() - 1 == cursorPosition->y) {
					++printStart;
				}

				++cursorPosition->y;
				++dsIt;

				if (dsIt->size() < cursorPosition->x) {
					cursorPosition->x = static_cast<int>(dsIt->size()) - 1;
				}
			}
			break;
		case VMKeyboard::key.ENTER:
		case '\n':
			++cursorPosition->y;
			cursorPosition->x = 0;
			break;
		case VMKeyboard::key.BACKSPACE:
		case VMKeyboard::key.DELETE:
		case 127:
			--cursorPosition->x;
			break;
		default:
			return false;
	}

	return true;

}

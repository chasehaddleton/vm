//
// Created by Chase Haddleton on 2017-11-28.
//

#include "VMWindow.h"

void VMWindow::run() {
	int ch = *keyIt;

	while (ch != 'q') {

		++keyIt;
		ch = *keyIt;
	}
}

bool VMWindow::handleInput(int ch) {
	// TODO: fix up to not move to the end of the new line

	switch (ch) {
		case VMKeyboard::key.RESIZE:
			display.resize();
			break;
		case VMKeyboard::key.LEFT:
			cursor.moveLeft();
			break;
		case VMKeyboard::key.RIGHT:
			cursor.moveRight();
			break;
		case VMKeyboard::key.UP:
			if (cursor.getYPos() > 0 && cursor.getYPos() == printStart) {
				// printStart has room to move up
				--printStart;
			}

			cursor.moveUp();
			break;
		case VMKeyboard::key.DOWN:
			auto tmpIt = ++cursor.getIT();

			if (tmpIt != model.end() && printStart + display.getYSize() - 1 == cursor.getYPos()) {
				++printStart;
			}

			cursor.moveDown();

			break;
		case VMKeyboard::key.ENTER:
		case '\n':
			// TODO: Implement Enter
			//++cursorPosition->y;
			//cursorPosition->x = 0;
			break;
		case VMKeyboard::key.BACKSPACE:
		case VMKeyboard::key.DELETE:
		case 127:
			// TODO: Implement backspace/delete
			// --cursorPosition->x;
			break;
		default:
			return false;
	}

	return true;

}

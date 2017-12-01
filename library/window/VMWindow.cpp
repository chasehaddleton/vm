//
// Created by Chase Haddleton on 2017-11-28.
//

#include "VMWindow.h"

VMWindow::VMWindow() : keyboard{}, keyIt{keyboard.begin()}, model{}, cursor{model.getCursor()},
                       printStart{new int {0}}, display{model.getDataSource(), cursor, printStart} {}

VMWindow::VMWindow(std::string fileName)
		: keyboard{}, keyIt{keyboard.begin()}, model{fileName}, cursor{model.getCursor()},
		  printStart{new int {0}}, display{model.getDataSource(), cursor, printStart} {}

void VMWindow::run() {
	display.update();
	int ch = *keyIt;

	while (ch != 'q') {
		display.update();

		++keyIt;
		ch = *keyIt;
	}
}

bool VMWindow::handleInput(int ch) {
	// TODO: fix up to not move to the end of the new line

	if (ch == VMKeyboard::key.RESIZE) {
		display.resize();
	} else if (ch == VMKeyboard::key.LEFT) {
		cursor.moveLeft();
	} else if (ch == VMKeyboard::key.RIGHT) {
		cursor.moveRight();
	} else if (ch == VMKeyboard::key.UP) {
		if (cursor.getYPos() > 0 && cursor.getYPos() == *printStart) {
			// printStart has room to move up
			--(*printStart);
		}

		cursor.moveUp();
	} else if (ch == VMKeyboard::key.DOWN) {
		auto tmpIt = ++cursor.getIT();

		if (tmpIt != model.end() && *printStart + display.getYSize() - 1 == cursor.getYPos()) {
			++(*printStart);
		}

		cursor.moveDown();
	} else if (ch == VMKeyboard::key.ENTER || ch == '\n') {
		// TODO: Implement Enter
		//++cursorPosition->y;
		//cursorPosition->x = 0;
	} else if (ch == VMKeyboard::key.BACKSPACE || ch == VMKeyboard::key.DELETE || ch == 127) {
		// TODO: Implement backspace/delete
		// --cursorPosition->x;
	} else {
		return false;
	}

	return true;
}

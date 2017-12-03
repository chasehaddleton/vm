//
// Created by Chase Haddleton on 2017-11-16.
//

#include "VMDisplay.h"
#include <ncurses.h>
#include <cstddef>

void VMDisplay::init() {
	initscr();
	vmState.setWindowX(COLS);
	vmState.setWindowY(LINES);
	keypad(stdscr, true);
	noecho();
	raw();
}

void VMDisplay::end() {
	clear();
	endwin();
}

VMDisplay::~VMDisplay() {
	endwin();
}

void VMDisplay::resize() {
	end();
	init();
	doUpdate();
}

void VMDisplay::print(std::string s, int y) {
	move(y, 0);
	clrtoeol();

	if (s.size() > vmState.getWindowX()) {
		move(y + 1, 0);
		clrtoeol();
	}

	mvaddstr(y, 0, s.c_str());
}

void VMDisplay::doUpdate() {
	if (*printStart + vmState.getWindowX() < cursor->getYPos()) {
		*printStart += (cursor->getYPos() - (*printStart + vmState.getWindowX()));
	}

	int longLineSkip = 0;
	auto displayXPos = static_cast<int>(cursor->getXPos());
	auto displayYPos = static_cast<int>(cursor->getYPos() - *printStart);
	auto it = cursor->getIT();

	// curPos.y + printStart == position in file wrt screen cursor
	std::advance(it, -(static_cast<std::ptrdiff_t>(cursor->getYPos()) - static_cast<std::ptrdiff_t>(*printStart)));

	for (int i = 0; i < vmState.getWindowY(); ++i) {
		if (it != ds->end()) {
			print(it->toString(), i);

			if (it->size() > vmState.getWindowX()) {
				if ((i - longLineSkip) < cursor->getYPos()) {
					++longLineSkip;
				}
				++i;
			}
			++it;
		} else {
			print("~", i);
		}
	}

	if (cursor->getXPos() >= vmState.getWindowX()) {
		++longLineSkip;
		displayXPos -= vmState.getWindowX();
	}

	move(displayYPos + longLineSkip, displayXPos);

	refresh();
}

VMDisplay::VMDisplay(VMState &vmState) : vmState{vmState} {
	init();
}

void VMDisplay::bind(VMModel vmModel) {

}

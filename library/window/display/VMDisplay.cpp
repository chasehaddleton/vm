//
// Created by Chase Haddleton on 2017-11-16.
//

#include "VMDisplay.h"

void VMDisplay::init() {
	initscr();
	xSize = COLS;
	ySize = LINES;
	keypad(stdscr, true);
	noecho();
	raw();
}

void VMDisplay::end() {
	clear();
	endwin();
}

VMDisplay::VMDisplay(VMDisplay::dataType &ds, Cursor &c, std::shared_ptr<int> printStart)
		: ds{ds}, cursor{c}, printStart{std::move(printStart)} {
	init();
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

	if (s.size() > xSize) {
		move(y + 1, 0);
		clrtoeol();
	}

	mvaddstr(y, 0, s.c_str());
}

void VMDisplay::doUpdate() {
	int longLineSkip = 0;
	int displayXPos = static_cast<int>(cursor.getXPos());
	int displayYPos = static_cast<int>(cursor.getYPos()) - *printStart;
	auto it = cursor.getIT();

	// curPos.y + printStart == position in file wrt screen cursor
	std::advance(it, -displayYPos);

	for (int i = 0; i < ySize; ++i) {
		if (it != ds.end()) {
			print(**it, i);

			if (it->size() > xSize) {
				if ((i - longLineSkip) < cursor.getYPos()) {
					++longLineSkip;
				}
				++i;
			}
			++it;
		} else {
			print("~", i);
		}
	}

	if (cursor.getXPos() >= xSize) {
		++longLineSkip;
		displayXPos -= xSize;
	}

	move(displayYPos + longLineSkip, displayXPos);

	refresh();
}

int VMDisplay::getXSize() const {
	return xSize;
}

int VMDisplay::getYSize() const {
	return ySize;
}

// TODO: move handle input into the VMWindow class

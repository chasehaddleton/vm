//
// Created by Chase Haddleton on 2017-11-16.
//

#include "VMDisplay.h"
#include <ncurses.h>

void VMDisplay::init() {
	initscr();
	xSize = COLS;
	ySize = LINES;
	keypad(stdscr, TRUE);
	noecho();
	raw();
}

void VMDisplay::end() {
	clear();
	endwin();
}

VMDisplay::VMDisplay(std::shared_ptr<std::list<std::string>> f, std::shared_ptr<Point> p) : f{f}, curPos{p} {
	init();
	fIt = f->begin();
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
	int displayXPos = curPos->x;
	int displayYPos = curPos->y - printStart;
	auto it = fIt;

	// curPos.y + printStart == position in file wrt screen cursor
	std::advance(it, -(curPos->y - printStart));

	for (int i = 0; i < ySize; ++i) {
		if (it != f->end()) {
			print(*it, i);
			if (it->size() > xSize) {
				if ((i - longLineSkip) < curPos->y) {
					++longLineSkip;
				}
				++i;
			}
			++it;
		} else {
			print("~", i);
		}
	}

	if (curPos->x >= xSize) {
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

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
	display();
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

void VMDisplay::display() {
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

// TODO: move handle input into the VMWindow class
bool VMDisplay::handleInput(int ch) {
	switch (ch) {
		case KEY_RESIZE:
			resize();
			break;
		case KEY_LEFT:
			if (curPos->x != 0) {
				--curPos->x;
			}
			break;
		case KEY_RIGHT:
			if (curPos->x + 1 < fIt->size()) {
				++curPos->x;
			}
			break;
		case KEY_UP:
			if (curPos->y > 0) {
				if (curPos->y == printStart) {
					// printStart has room to move up
					--printStart;
				}

				--curPos->y;
				--fIt;

				if (fIt->size() <= curPos->x) {
					curPos->x = static_cast<int>(fIt->size()) - 1;
				}
			}
			break;
		case KEY_DOWN:
			if (curPos->y + 1 < f->size()) {
				// Do not go past the end of the file
				if (printStart + ySize - 1 == curPos->y) {
					++printStart;
				}

				++curPos->y;
				++fIt;

				if (fIt->size() < curPos->x) {
					curPos->x = static_cast<int>(fIt->size()) - 1;
				}
			}
			break;
		case KEY_ENTER:
		case '\n':
			++curPos->y;
			curPos->x = 0;
			break;
		case KEY_BACKSPACE:
		case KEY_DC:
		case 127:
			--curPos->x;
			break;
		default:
			return false;
	}

	return true;
}

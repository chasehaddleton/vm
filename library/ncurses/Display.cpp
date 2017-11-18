//
// Created by Chase Haddleton on 2017-11-16.
//

#include "Display.h"
#include <ncurses.h>

int const Display::BACKSPACE = KEY_BACKSPACE;

Display::Display() : init{false} {
	begin();
}

Display::~Display() {
	end();
}

void Display::begin() {
	if (!init) {
		initscr();
		raw();
		noecho();
		curs_set('|');
		init = true;
	}
}

void Display::print(std::string s) {
	printw(s.c_str());
}

void Display::print(char c) {
	addch(c);
}

void Display::movePos(const Point pos) {
	move(pos.y, pos.x);
}

void Display::erasePos(Point pos) {
	mvdelch(pos.y, pos.x);
}

void Display::printXY(std::string s, Point pos) {
	mvprintw(pos.y, pos.x, s.c_str());

}

int Display::receiveInput() {
	return getch();
}

void Display::update() {
	refresh();
}

void Display::end() {
	if (init) {
		endwin();
	}
}
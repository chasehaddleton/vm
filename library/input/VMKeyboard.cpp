//
// Created by Chase Haddleton on 2017-11-28.
//

#include "VMKeyboard.h"
#include <ncurses.h>

int VMKeyboard::Iterator::operator*() {
	return getch();
}

bool VMKeyboard::Iterator::operator!=(const VMKeyboard::Iterator &other) {
	return false;
}

VMKeyboard::Iterator VMKeyboard::Iterator::operator++() {
	return *this;
}

VMKeyboard::Iterator VMKeyboard::begin() {
	return Iterator{};
}


VMKeyboard::Iterator VMKeyboard::end() {
	return Iterator{};
}

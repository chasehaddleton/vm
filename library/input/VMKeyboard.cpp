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

const int VMKeyboard::Key::DOWN = KEY_DOWN;
const int VMKeyboard::Key::UP = KEY_UP;
const int VMKeyboard::Key::LEFT = KEY_LEFT;
const int VMKeyboard::Key::RIGHT = KEY_RIGHT;
const int VMKeyboard::Key::HOME = KEY_HOME;
const int VMKeyboard::Key::BACKSPACE = KEY_BACKSPACE;
const int VMKeyboard::Key::F0 = KEY_F0;
const int VMKeyboard::Key::F1 = KEY_F(1); // TODO: define the rest of the functions keys
const int VMKeyboard::Key::DELETE_LINE = KEY_DL;
const int VMKeyboard::Key::INSERT_LINE = KEY_IL;
const int VMKeyboard::Key::DELECT_CHARACTER = KEY_DC;
const int VMKeyboard::Key::INSERT_CHARACTER = KEY_IC;
const int VMKeyboard::Key::ENTER = KEY_ENTER;
const int VMKeyboard::Key::CANCEL = KEY_CANCEL;
const int VMKeyboard::Key::COMMAND = KEY_COMMAND;
const int VMKeyboard::Key::END = KEY_END;
const int VMKeyboard::Key::EXIT = KEY_EXIT;
const int VMKeyboard::Key::REDO = KEY_REDO;
const int VMKeyboard::Key::SAVE = KEY_SAVE;
const int VMKeyboard::Key::UNDO = KEY_UNDO;
const int VMKeyboard::Key::RESIZE = KEY_RESIZE;
const int VMKeyboard::Key::ESCAPE = 27;
const int VMKeyboard::Key::DELETE = KEY_DC;
/*#define KEY_SF        0520        *//* scroll-forward key *//*
#define KEY_SR        0521        *//* scroll-backward key *//*
#define KEY_NPAGE    0522        *//* next-page key *//*
#define KEY_PPAGE    0523        *//* previous-page key *//*
#define KEY_PRINT    0532        *//* print key *//*
#define KEY_LL        0533        *//* lower-left key (home down) *//*
#define KEY_A1        0534        *//* upper left of keypad *//*
#define KEY_A3        0535        *//* upper right of keypad *//*
#define KEY_B2        0536        *//* center of keypad *//*
#define KEY_C1        0537        *//* lower left of keypad *//*
#define KEY_C3        0540        *//* lower right of keypad *//*
#define KEY_BTAB    0541        *//* back-tab key *//*
#define KEY_BEG        0542        *//* begin key *//*
#define KEY_COPY    0546        *//* copy key *//*
#define KEY_CLOSE    0544        *//* close key *//*
#define KEY_CREATE    0547        *//* create key *//*
#define KEY_OPTIONS    0561        *//* options key *//*
#define KEY_PREVIOUS    0562        *//* previous key *//*
#define KEY_RESUME    0570        *//* resume key */

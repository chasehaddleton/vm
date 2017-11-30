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

struct VMKeyboard::Key {
	const int DOWN = KEY_DOWN;
	const int UP = KEY_UP;
	const int LEFT = KEY_LEFT;
	const int RIGHT = KEY_RIGHT;
	const int HOME = KEY_HOME;
	const int BACKSPACE = KEY_BACKSPACE;
	const int F0 = KEY_F0;
	const int F1 = KEY_F(1); // TODO: define the rest of the functions keys
	const int DELETE_LINE = KEY_DL;
	const int INSERT_LINE = KEY_IL;
	const int DELECT_CHARACTER = KEY_DC;
	const int INSERT_CHARACTER = KEY_IC;
	const int ENTER = KEY_ENTER;
	const int CANCEL = KEY_CANCEL;
	const int COMMAND = KEY_COMMAND;
	const int END = KEY_END;
	const int EXIT = KEY_EXIT;
	const int REDO = KEY_REDO;
	const int SAVE = KEY_SAVE;
	const int UNDO = KEY_UNDO;
	const int RESIZE = KEY_RESIZE;
	const int ESCAPE = 27;
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
};

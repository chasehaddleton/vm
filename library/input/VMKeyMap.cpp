//
// Created by Chase Haddleton on 2017-12-03.
//

#include "VMKeyMap.h"
#include <ncurses.h>

const int VMKeyMap::DOWN = KEY_DOWN;
const int VMKeyMap::UP = KEY_UP;
const int VMKeyMap::LEFT = KEY_LEFT;
const int VMKeyMap::RIGHT = KEY_RIGHT;
const int VMKeyMap::HOME = KEY_HOME;
const int VMKeyMap::BACKSPACE = KEY_BACKSPACE;
const int VMKeyMap::F0 = KEY_F0;
const int VMKeyMap::F1 = KEY_F(1); // TODO: define the rest of the functions keys
const int VMKeyMap::DELETE_LINE = KEY_DL;
const int VMKeyMap::INSERT_LINE = KEY_IL;
const int VMKeyMap::DELECT_CHARACTER = KEY_DC;
const int VMKeyMap::INSERT_CHARACTER = KEY_IC;
const std::string VMKeyMap::ENTER = "^J";
const int VMKeyMap::ENTER_ASCII = 10;
const int VMKeyMap::CANCEL = KEY_CANCEL;
const int VMKeyMap::COMMAND = KEY_COMMAND;
const int VMKeyMap::END = KEY_END;
const int VMKeyMap::EXIT = KEY_EXIT;
const int VMKeyMap::REDO = KEY_REDO;
const int VMKeyMap::SAVE = KEY_SAVE;
const int VMKeyMap::UNDO = KEY_UNDO;
const int VMKeyMap::RESIZE = KEY_RESIZE;
const int VMKeyMap::ESCAPE_ASCII = 27;
const int VMKeyMap::DELETE = KEY_DC;
const int VMKeyMap::DELETE_ASCII = 127;
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

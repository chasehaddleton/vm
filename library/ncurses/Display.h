//
// Created by Chase Haddleton on 2017-11-16.
//

#ifndef VM_NCURSES_H
#define VM_NCURSES_H

#include <string>
#include "../Point.h"

class Display {
	bool init;

	void begin();

public:
	static int const BACKSPACE;

	Display();

	~Display();

	void print(std::string s);

	void print(char c);

	void movePos(Point pos);

	void erasePos(Point pos);

	void printXY(std::string s, Point pos);

	int receiveInput();

	void update();

	void end();
};


#endif //VM_NCURSES_H

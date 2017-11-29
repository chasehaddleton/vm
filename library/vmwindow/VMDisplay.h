//
// Created by Chase Haddleton on 2017-11-16.
//

#ifndef VM_VMDISPLAY_H
#define VM_VMDISPLAY_H

#include <list>
#include <string>
#include "../Point.h"
#include <memory>

class window_resized {
};

class VMDisplay {
	std::shared_ptr<std::list<std::string>> f;
	std::list<std::string>::iterator fIt;
	std::shared_ptr<Point> curPos;

	int printStart = 0;
	int xSize = 0;
	int ySize = 0;

	void init();

	void end();

public:

	VMDisplay(std::shared_ptr<std::list<std::string>> f, std::shared_ptr<Point> p);

	~VMDisplay();

	void display();

	void resize();

	void print(std::string s, int y);

	bool handleInput(int ch);
};


#endif //VM_VMDISPLAY_H

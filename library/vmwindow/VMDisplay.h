//
// Created by Chase Haddleton on 2017-11-16.
//

#ifndef VM_VMDISPLAY_H
#define VM_VMDISPLAY_H

#include <list>
#include <string>
#include "../Point.h"
#include <memory>
#include "../abstractions/Display.h"

class VMDisplay : public Display {
	std::shared_ptr<std::list<std::string>> f;
	std::shared_ptr<std::list<std::string>::iterator> fIt;

	std::list<std::string>::iterator fIt;
	std::shared_ptr<Point> curPos;
	std::shared_ptr<int> printStart;

	int xSize = 0;
	int ySize = 0;

	void init();

	void end();

	void doUpdate();

public:

	VMDisplay(std::shared_ptr<std::list<std::string>> f, std::shared_ptr<std::list<std::string>::iterator> fIt,
	          std::shared_ptr<Point> p);

	~VMDisplay();

	void resize();

	void print(std::string s, int y);

	bool handleInput(int ch);

	int getXSize() const;

	int getYSize() const;
};


#endif //VM_VMDISPLAY_H

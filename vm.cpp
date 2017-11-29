#include <iostream>
#include <string>
#include <list>
#include "library/vmwindow/VMDisplay.h"
#include "library/input/VMKeyboard.h"
#include "library/Point.h"

int main(int argc, const char *argv[]) {
	std::shared_ptr<std::list<std::string>> st{new std::list<std::string>{}};

	for (int i = 0; i < 15; ++i) {
		st->push_back(std::to_string(i) +
		              "jafhksdjhfkjahsdnkjfnakjsdnfkjasdnfkjansdkjfnasdkjfnkajsdnfkjasndfkjasdfhaiorhjgndjfna");
	}

	std::shared_ptr<Point> curPos{new Point{}};
	VMDisplay vmd{st, curPos};
	VMKeyboard vmk{};
	auto kIt = vmk.begin();

	vmd.display();
	int c = *kIt;

	while (c != 'q') {
		vmd.handleInput(c);
		vmd.display();

		c = *kIt;
	}
}

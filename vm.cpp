#include "library/ncurses/Display.h"

int main() {
	Display n{};

	char in;

	int x = 0;
	int y = 0;

	do {
		in = static_cast<char>(n.receiveInput());

		if (in == Display::BACKSPACE) {
			n.movePos({--x, y});
			n.erasePos({x, y});
		} else if (in == '\n') {
			n.print(in);
			++y;
		} else {
			n.print(in);
		}

		n.update();
	} while (in != 'y');

	return 0;
}
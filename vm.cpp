#include "library/vmwindow/VMDisplay.h"
#include "library/abstractions/Command.h"
#include <vector>

int main() {
	Display n{};

	char in;

	int x = 0;
	int y = 0;

    unsigned short tabStop;

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

	std::vector<std::unique_ptr<Command>> commands;

	/**
	 * Create the commands and put them into commands
	 */

	commands.push_back(new Macro());

	bool running, commandMode, insertMode;

	while (running) {
		if (commandMode) {
			in = static_cast<char>(n.receiveInput());

			if (in == 'a') {

			}
		} else if (insertMode) {

		} else { // Macro record mode?

		}
	}

	return 0;
}


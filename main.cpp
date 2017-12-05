
#include "library/VM.h"
#include <iostream>

int main(int argc, const char *argv[]) {
	std::string fileName{};

	if (argc > 1) {
		fileName = argv[1];
	}

	VM vm;

	try {
		vm.run(fileName);
	} catch (std::invalid_argument &e) {
		std::cerr << "Error: file name given is invalid";
	}
}

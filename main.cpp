
#include "library/VM.h"

int main(int argc, const char *argv[]) {
	std::string fileName{};

	if (argc > 1) {
		fileName = argv[1];
	}

	VM vm;
	vm.run(fileName);
}

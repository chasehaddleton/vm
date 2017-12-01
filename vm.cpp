#include "library/window/VMWindow.h"
#include <string>

int main(int argc, const char *argv[]) {
	if (argc > 1) {
		VMWindow vmw{std::string{argv[1]}};
		vmw.run();
	} else {
		VMWindow vmw{};
		vmw.run();
	}

}

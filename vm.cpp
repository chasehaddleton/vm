#include "library/window/VMWindow.h"

int main(int argc, const char *argv[]) {
	VMWindow vmw{std::string{argv[1]}};
	vmw.run();
}

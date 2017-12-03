//
// Created by Chase Haddleton on 2017-12-02.
//

#ifndef VM_VMSTATUSBAR_H
#define VM_VMSTATUSBAR_H

#include <string>

class VMState;
class Cursor;

class VMStatusBar {
	VMState *state{nullptr};
	Cursor *cursor{nullptr};
	std::string message;

public:
	explicit VMStatusBar() = default;

	void bind(VMState &state, Cursor &cursor);

	std::string operator*();

	void setMessage(const std::string &m);
};


#endif //VM_VMSTATUSBAR_H

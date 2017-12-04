//
// Created by Chase Haddleton on 2017-12-02.
//

#ifndef VM_VMSTATUSBAR_H
#define VM_VMSTATUSBAR_H

#include <string>
#include "../abstractions/observer/Observer.h"

class VMState;
class Cursor;

class VMStatusBar : public Observer {
	VMState *state{nullptr};
	Cursor *cursor{nullptr};
	std::string message;

	void doNotify(const Subject *sub) override;

public:
	explicit VMStatusBar(std::string name = "Status Bar");

	void bind(VMState &state, Cursor &cursor);

	std::string operator*();

	void setMessage(const std::string &m);
};


#endif //VM_VMSTATUSBAR_H

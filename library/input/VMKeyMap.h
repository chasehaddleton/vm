//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_VMKEYMAP_H
#define VM_VMKEYMAP_H


#include <string>

struct VMKeyMap {
	static const int DOWN;
	static const int UP;
	static const int LEFT;
	static const int RIGHT;
	static const int HOME;
	static const int BACKSPACE;
	static const int DELETE;
	static const int DELETE_ASCII;
	static const int F0;
	static const int F1;
	static const int DELETE_LINE;
	static const int INSERT_LINE;
	static const int DELECT_CHARACTER;
	static const int INSERT_CHARACTER;
	static const std::string ENTER;
	static const int ENTER_ASCII;
	static const int CANCEL;
	static const int COMMAND;
	static const int END;
	static const int EXIT;
	static const int REDO;
	static const int SAVE;
	static const int UNDO;
	static const int RESIZE;
	static const int ESCAPE_ASCII;
};


#endif //VM_VMKEYMAP_H

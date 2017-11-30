//
// Created by Chase Haddleton on 2017-11-28.
//

#ifndef VM_VMKEYBOARD_H
#define VM_VMKEYBOARD_H

class VMKeyboard {
	class Iterator {
		Iterator() = default;

	public:
		int operator*();

		bool operator!=(const Iterator &other);

		Iterator operator++();

		friend class VMKeyboard;
	};

public:
	struct Key {
		const int DOWN;
		const int UP;
		const int LEFT;
		const int RIGHT;
		const int HOME;
		const int BACKSPACE;
		const int F0;
		const int F1;
		const int DELETE_LINE;
		const int INSERT_LINE;
		const int DELECT_CHARACTER;
		const int INSERT_CHARACTER;
		const int ENTER;
		const int CANCEL;
		const int COMMAND;
		const int END;
		const int EXIT;
		const int REDO;
		const int SAVE;
		const int UNDO;
		const int REIZE;
		const int ESCAPE;
	};

	static Key key;

	VMKeyboard() = default;

	Iterator begin();

	Iterator end();
};

#endif //VM_VMKEYBOARD_H

//
// Created by Chase Haddleton on 2017-11-28.
//

#ifndef VM_VMKEYBOARD_H
#define VM_VMKEYBOARD_H

class VMKeyboard {
public:
	class Iterator {
		Iterator() = default;

	public:
		int operator*();

		bool operator!=(const Iterator &other);

		Iterator operator++();

		friend class VMKeyboard;
	};

	struct Key {
		static const int DOWN;
		static const int UP;
		static const int LEFT;
		static const int RIGHT;
		static const int HOME;
		static const int BACKSPACE;
		static const int DELETE;
		static const int F0;
		static const int F1;
		static const int DELETE_LINE;
		static const int INSERT_LINE;
		static const int DELECT_CHARACTER;
		static const int INSERT_CHARACTER;
		static const int ENTER;
		static const int CANCEL;
		static const int COMMAND;
		static const int END;
		static const int EXIT;
		static const int REDO;
		static const int SAVE;
		static const int UNDO;
		static const int RESIZE;
		static const int ESCAPE;
	};

	static Key key;

	VMKeyboard() = default;

	Iterator begin();

	Iterator end();
};

#endif //VM_VMKEYBOARD_H

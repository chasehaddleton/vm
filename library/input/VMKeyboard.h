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
	VMKeyboard() = default;

	Iterator begin();

	Iterator end();
};

#endif //VM_VMKEYBOARD_H

//
// Created by Chase Haddleton on 2017-11-28.
//

#ifndef VM_VMKEYBOARD_H
#define VM_VMKEYBOARD_H

#include "VMKeyMap.h"

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

	static VMKeyMap key;

	VMKeyboard() = default;

	Iterator begin();

	Iterator end();
};

#endif //VM_VMKEYBOARD_H

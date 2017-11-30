//
// Created by Chase Haddleton on 2017-11-30.
//

#ifndef VM_INPUT_H
#define VM_INPUT_H

class Input {
	class Iterator;

public:
	virtual int getCh() =0;

	virtual Iterator begin() = 0;

	virtual Iterator end() = 0;
};

#endif //VM_INPUT_H

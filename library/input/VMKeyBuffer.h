//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_VMKEYBUFFER_H
#define VM_VMKEYBUFFER_H


#include "../abstractions/observer/Subject.h"

class VMKeyBuffer : public Subject {
	std::string keyBuffer;

public:
	void push_back(int ch);

	std::string operator*() const;

	std::string toString() const;

	void clear();

	void removeLast();

	bool empty();

	size_t size() const;
};


#endif //VM_VMKEYBUFFER_H

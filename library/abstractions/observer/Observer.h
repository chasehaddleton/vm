//
// Created by Chase Haddleton on 2017-12-01.
//

#ifndef VM_OBSERVER_H
#define VM_OBSERVER_H

#include <string>
#include "../Event.h"
#include "Subject.h"

class Observer {
	std::string name;

	virtual void doNotify(Subject &s) = 0;

public:

	void notify(Subject &s);

	bool operator==(const Observer &other);
};

#endif //VM_OBSERVER_H

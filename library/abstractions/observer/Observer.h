//
// Created by Chase Haddleton on 2017-12-01.
//

#ifndef VM_OBSERVER_H
#define VM_OBSERVER_H

#include <string>

class Observer {
	std::string name;

	virtual void doNotify() const = 0;

public:
	void notify() const;

	bool operator==(const Observer &other);
};

#endif //VM_OBSERVER_H

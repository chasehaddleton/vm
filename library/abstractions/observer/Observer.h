//
// Created by Chase Haddleton on 2017-12-01.
//

#ifndef VM_OBSERVER_H
#define VM_OBSERVER_H

#include <string>

class Subject;

class Observer {
	std::string name;

	virtual void doNotify(const Subject *sub) = 0;

public:
	explicit Observer(const std::string &name);

	void notify(const Subject *sub);

	bool operator==(const Observer &other);

	const std::string &getName() const;
};

#endif //VM_OBSERVER_H

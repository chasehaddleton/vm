//
// Created by Chase Haddleton on 2017-12-01.
//

#ifndef VM_SUBJECT_H
#define VM_SUBJECT_H

#include "Observer.h"
#include <list>
#include <memory>

class Subject {
	std::list<std::shared_ptr<Observer>> observers;

public:
	virtual Event &update() = 0;

	void registerOb(std::shared_ptr<Observer> &ob);

	void deregisterOb(std::shared_ptr<Observer> &ob);

	void notifyObservers();
};

#endif //VM_SUBJECT_H

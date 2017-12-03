//
// Created by Chase Haddleton on 2017-12-01.
//

#ifndef VM_SUBJECT_H
#define VM_SUBJECT_H

#include "./Observer.h"
#include <list>
#include <memory>

class Subject {
	std::list<Observer *> observers;

public:
	void registerOb(Observer &ob);

	void deregisterOb(Observer &ob);

	void notifyObservers() const;
};

#endif //VM_SUBJECT_H

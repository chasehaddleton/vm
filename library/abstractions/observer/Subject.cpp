//
// Created by Chase Haddleton on 2017-12-01.
//

#include "Subject.h"

void Subject::registerOb(std::shared_ptr<Observer> &ob) {
	observers.push_back(ob);
}

void Subject::deregisterOb(std::shared_ptr<Observer> &ob) {
	observers.remove(ob);
}

void Subject::notifyObservers() {
	for(auto &ob : observers) {
		//ob.notify();
	}
}

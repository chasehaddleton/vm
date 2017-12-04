//
// Created by Chase Haddleton on 2017-12-01.
//

#include "Subject.h"

void Subject::registerOb(Observer &ob) {
	observers.push_back(&ob);
}

void Subject::deregisterOb(Observer &ob) {
	observers.remove(&ob);
}

void Subject::notifyObservers() const {
	for(auto ob : observers) {
		ob->notify(this);
	}
}

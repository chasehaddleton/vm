//
// Created by Chase Haddleton on 2017-12-01.
//

#include "Observer.h"

Observer::Observer(const std::string &name) : name{name} {}

void Observer::notify() const {
	doNotify();
}

bool Observer::operator==(const Observer &other) {
	return name == other.name;
}

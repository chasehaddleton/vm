//
// Created by Chase Haddleton on 2017-12-01.
//

#include "Observer.h"
#include "Subject.h"

Observer::Observer(const std::string &name) : name{name} {}

void Observer::notify(const Subject *sub) {
	doNotify(sub);
}

bool Observer::operator==(const Observer &other) {
	return name == other.name;
}

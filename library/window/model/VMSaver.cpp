//
// Created by Chase Haddleton on 2017-12-03.
//

#include "VMSaver.h"

void VMSaver::doNotify() const {
	save.saveFile();
}

VMSaver::VMSaver(Saveable &save, const std::string &name) : Observer(name), save(save) {}


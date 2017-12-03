//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_VMSAVER_H
#define VM_VMSAVER_H


#include "../../abstractions/observer/Observer.h"
#include "../../abstractions/Saveable.h"

class VMSaver : public Observer {
	Saveable &save;

	void doNotify() const override;

public:
	VMSaver(Saveable &save, const std::string &name);
};


#endif //VM_VMSAVER_H

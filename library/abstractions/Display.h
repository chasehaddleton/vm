//
// Created by Slayorious on 2017-11-23.
//

#ifndef VM_DISPLAY_H
#define VM_DISPLAY_H

class Display {
	virtual void doUpdate() = 0;

public:

	void update() {
		doUpdate();
	}
};

#endif //VM_DISPLAY_H

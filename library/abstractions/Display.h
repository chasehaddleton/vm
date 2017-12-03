//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_DISPLAY_H
#define VM_DISPLAY_H

class Display {
	virtual void doUpdate() const = 0;

public:

	void update() const;
};


#endif //VM_DISPLAY_H

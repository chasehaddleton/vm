//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_SAVEABLE_H
#define VM_SAVEABLE_H


#include <string>

class Saveable {
public:
	virtual void saveFile() const = 0;

	virtual void saveFile(std::string fileName) = 0;
};


#endif //VM_SAVEABLE_H

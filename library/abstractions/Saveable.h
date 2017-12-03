//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_SAVEABLE_H
#define VM_SAVEABLE_H

#include <string>

class Saveable {
	virtual void doSaveFile() const = 0;

	virtual void doSaveFile(std::string fileName) = 0;

public:
	void saveFile() const;

	void saveFile(std::string fileName);
};

#endif //VM_SAVEABLE_H

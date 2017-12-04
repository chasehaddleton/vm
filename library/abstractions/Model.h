//
// Created by Chase Haddleton on 2017-12-03.
//

#ifndef VM_MODEL_H
#define VM_MODEL_H

#include "Saveable.h"

class Model : public Saveable {
	virtual void doAddLine() = 0;

	virtual void doRemoveLine() = 0;

	virtual void doUndo() = 0;

	virtual void doRedo() = 0;

	virtual void doAddChar(char c) = 0;

	virtual void doRemoveChar() = 0;

public:

	void addChar(char c);

	void removeChar();

	void addLine();

	void removeLine();

	void undo();

	void redo();
};

#endif //VM_MODEL_H

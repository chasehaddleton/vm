//
// Created by Chase Haddleton on 2017-12-03.
//

#include "Model.h"

void Model::addChar(char c) {
	doAddChar(c);
}

void Model::removeChar() {
	doRemoveChar();
}

void Model::addLine() {
	doAddLine();
}

void Model::removeLine() {
	doRemoveLine();
}

void Model::undo() {
	doUndo();
}

void Model::redo() {
	doRedo();
}

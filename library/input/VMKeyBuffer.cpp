//
// Created by Chase Haddleton on 2017-12-03.
//

#include "VMKeyBuffer.h"
#include "VMKeyboard.h"

void VMKeyBuffer::push_back(int ch) {
	keyBuffer.append(VMKeyboard::getKeyname(ch));
	notifyObservers();
}

std::string VMKeyBuffer::operator*() const {
	return keyBuffer;
}

std::string VMKeyBuffer::toString() const {
	return keyBuffer;
}

void VMKeyBuffer::clear() {
	keyBuffer.clear();
}

bool VMKeyBuffer::empty() {
	return keyBuffer.empty();
}

size_t VMKeyBuffer::size() const {
	return keyBuffer.size();
}

void VMKeyBuffer::removeLast() {
	keyBuffer.pop_back();
	notifyObservers();
}



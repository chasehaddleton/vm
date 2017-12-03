//
// Created by Chase Haddleton on 2017-12-03.
//

#include "VMKeyBuffer.h"

void VMKeyBuffer::push_back(int ch) {
	keyBuffer.push_back(ch);
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



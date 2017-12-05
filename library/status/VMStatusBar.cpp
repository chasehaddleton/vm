//
// Created by Chase Haddleton on 2017-12-02.
//

#include "VMStatusBar.h"
#include "../window/model/Cursor.h"
#include "VMState.h"
#include "../input/VMKeyBuffer.h"

std::string VMStatusBar::operator*() {
	std::string left;

	if (message.empty()) {
		switch (state->getMode()) {
			case ModeType::COMMAND: {
				left = "-- Command Mode --";
				break;
			}
			case ModeType::INSERT : {
				left = "-- Insert Mode --";
				break;
			}
			case ModeType::MACRO_RECORD: {
				left = "recording";
				break;
			}
			default: {
				left = "";
				break;
			}
		}
	} else {
		left = message;
	}

	std::string cur = cursor->toString();

	auto leftOverWidth = state->getWindowX() - left.size() - cur.size();

	std::string padd;
	for (int i = 0; i < leftOverWidth; ++i) {
		padd.push_back(' ');
	}
	return left + padd + cur;
}

void VMStatusBar::bind(VMState &state, Cursor &cursor) {
	this->state = &state;
	this->cursor = &cursor;
}

void VMStatusBar::setMessage(const std::string &m) {
	message = m;
}

void VMStatusBar::clearMessage() {
	message = "";
}

void VMStatusBar::doNotify(const Subject *sub) {
	if (state->isCommandShown()) {
		auto buff = dynamic_cast<const VMKeyBuffer *>(sub);

		if (buff) {
			setMessage(buff->toString());
		}
	}
}

VMStatusBar::VMStatusBar(std::string name) : Observer(name) {}

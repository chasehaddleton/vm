//
// Created by Chase Haddleton on 2017-12-02.
//

#include "VMState.h"

VMState::VMState(const std::string &openFileName) : openFileName(openFileName) {}

void VMState::setOpenFileName(const std::string &openFileName) {
	VMState::openFileName = openFileName;
}

void VMState::setDisplayPastEnd(bool displayPastEnd) {
	VMState::displayPastEnd = displayPastEnd;
}

ModeType VMState::getMode() const {
	return mode;
}

const std::string &VMState::getOpenFileName() const {
	return openFileName;
}

bool VMState::isDisplayPastEnd() const {
	return displayPastEnd;
}

void VMState::setMode(ModeType mode) {
	VMState::mode = mode;
}

bool VMState::isDisplayCommand() const {
	return displayCommand;
}

void VMState::setDisplayCommand(bool displayCommand) {
	VMState::displayCommand = true;
}

bool VMState::isRunning() const {
	return running;
}

void VMState::setRunning(bool running) {
	VMState::running = running;
}

int VMState::getWindowX() const {
	return windowX;
}

void VMState::setWindowX(int windowX) {
	VMState::windowX = windowX;
}

int VMState::getWindowY() const {
	return windowY;
}

void VMState::setWindowY(int windowY) {
	VMState::windowY = windowY;
}

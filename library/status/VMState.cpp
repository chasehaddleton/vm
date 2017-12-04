//
// Created by Chase Haddleton on 2017-12-02.
//

#include "VMState.h"
#include "../window/model/VMModel.h"

VMState::VMState(const std::string &openFileName) : openFileName(openFileName) {}

void VMState::reset() {
	mode = ModeType::COMMAND;
	VMStatusBar statusBar{};
	openFileName = "";
	running = true;
	displayPastEnd = false;
	fileModified = false;
	windowX = 0;
	windowY = 0;
}

void VMState::setOpenFileName(const std::string &openFileName) {
	VMState::openFileName = openFileName;
}

const std::string &VMState::getOpenFileName() const {
	return openFileName;
}

void VMState::setDisplayPastEnd(bool displayPastEnd) {
	VMState::displayPastEnd = displayPastEnd;
}

ModeType VMState::getMode() const {
	return mode;
}

void VMState::setMode(ModeType mode) {
	VMState::mode = mode;
}

bool VMState::isDisplayPastEnd() const {
	return displayPastEnd;
}

void VMState::displayCommand() {
	showCommand = true;
	statusBar.setMessage(*keyBuff);
}

void VMState::hideCommand() {
	if (showCommand) {
		showCommand = false;
		statusBar.setMessage("");
	}
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

bool VMState::isFileModified() const {
	return fileModified;
}

void VMState::setFileModified(bool fileModified) {
	VMState::fileModified = fileModified;
}

bool VMState::isEnableSaveHistory() {
	return enableHistorySave;
}

void VMState::setEnableHistorySave(bool enable) {
	enableHistorySave = enable;
}

VMStatusBar &VMState::getStatusBar() {
	return statusBar;
}

void VMState::addChar(int ch) {
	keyBuff.push_back(ch);
}

bool VMState::isCommandShown() const {
	return showCommand;
}

void VMState::bind(VMModel &m) {
	statusBar.bind(*this, m.getCursor());
	keyBuff.registerOb(statusBar);
}

void VMState::resetCommandState() {
	if (showCommand) {
		hideCommand();
	}

	keyBuff.clear();
}

void VMState::setCurrentCount(int count) {
	currentCount = count;
}

int VMState::getCurrentCount() {
	return currentCount;
}
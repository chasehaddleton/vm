//
// Created by Chase Haddleton on 2017-12-02.
//

#include "VMStatusBar.h"

const std::string &VMStatusBar::getLeftSide() const {
	return leftSide;
}

void VMStatusBar::setLeftSide(const std::string &leftSide) {
	VMStatusBar::leftSide = leftSide;
}

const std::string &VMStatusBar::getRightSide() const {
	return rightSide;
}

void VMStatusBar::setRightSide(const std::string &rightSide) {
	VMStatusBar::rightSide = rightSide;
}

VMStatusBar::VMStatusBar(const std::string &leftSide , const std::string &rightSide) : leftSide(leftSide),
                                                                                      rightSide(rightSide) {}

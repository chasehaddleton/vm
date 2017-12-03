//
// Created by Chase Haddleton on 2017-12-02.
//

#ifndef VM_VMSTATUSBAR_H
#define VM_VMSTATUSBAR_H


#include <string>

class VMStatusBar {
	std::string leftSide;
	std::string rightSide;
public:
	VMStatusBar(const std::string &leftSide = "", const std::string &rightSide = "");

	const std::string &getLeftSide() const;

	void setLeftSide(const std::string &leftSide);

	const std::string &getRightSide() const;

	void setRightSide(const std::string &rightSide);
};


#endif //VM_VMSTATUSBAR_H

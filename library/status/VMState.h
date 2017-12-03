//
// Created by Chase Haddleton on 2017-12-02.
//

#ifndef VM_VMSTATUS_H
#define VM_VMSTATUS_H

#include <string>
#include "ModeType.h"
#include "VMStatusBar.h"

class VMState {
	ModeType mode{ModeType::COMMAND};
	VMStatusBar statusBar{};
	std::string openFileName{""};
	bool running{true};
	bool displayPastEnd{false};
	bool displayCommand{false};
	int windowX{0};
	int windowY{0};

public:

	explicit VMState(const std::string &openFileName = "");

	bool isDisplayCommand() const;

	void setDisplayCommand(bool displayCommand);

	ModeType getMode() const;

	const std::string &getOpenFileName() const;

	bool isDisplayPastEnd() const;

	void setOpenFileName(const std::string &openFileName);

	void setDisplayPastEnd(bool displayPastEnd);

	void setMode(ModeType mode);

	bool isRunning() const;

	void setRunning(bool running);

	int getWindowX() const;

	void setWindowX(int windowX);

	int getWindowY() const;

	void setWindowY(int windowY);
};

#endif //VM_VMSTATUS_H

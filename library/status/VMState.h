//
// Created by Chase Haddleton on 2017-12-02.
//

#ifndef VM_VMSTATUS_H
#define VM_VMSTATUS_H

#include <string>
#include "ModeType.h"
#include "VMStatusBar.h"
#include "../input/VMKeyBuffer.h"

class VMModel;

class VMState {
	ModeType mode{ModeType::COMMAND};
	VMStatusBar statusBar{};
	std::string openFileName{""};
	bool running{true};
	bool displayPastEnd{false};
	bool showCommand{false};
	bool fileModified{false};
	bool enableHistorySave{true};
	int windowX{0};
	int windowY{0};
	int scrollAmount{0};
	int currentCount{0};

	void reset();

public:
	VMKeyBuffer keyBuff;

	explicit VMState(const std::string &openFileName = "");

	void addChar(int ch);

	void displayCommand();

	bool isCommandShown() const;

	void hideCommand();

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

	int getScrollAmount() const;

	void setScrollAmount(int scrollAmount);

	bool isFileModified() const;

	void setFileModified(bool fileModified);

	bool isEnableSaveHistory();

	void setEnableHistorySave(bool enable);

	VMStatusBar &getStatusBar();

	void bind(VMModel &m);

	void resetCommandState();

	void setCurrentCount(int count);

	int getCurrentCount();

	friend class VM;
};

#endif //VM_VMSTATUS_H

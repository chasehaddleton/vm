//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_HISTORYSTACK_H
#define VM_HISTORYSTACK_H

#include <stack>
#include <memory>
#include "HistoryFrame.h"

class HistoryStack {
	std::stack<HistoryFrame> history;
public:
    void clear();

	void push(HistoryFrame &frame);

	HistoryFrame pop();
};

#endif //VM_HISTORYSTACK_H

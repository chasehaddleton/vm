//
// Created by Slayorious on 2017-11-26.
//

#ifndef VM_HISTORYSTACK_H
#define VM_HISTORYSTACK_H

#include <stack>
#include <memory>
#include "HistoryFrame.h"

class HistoryStack {
	std::stack<std::shared_ptr<HistoryFrame>> history;
public:
    void clear();

	void push(std::shared_ptr<HistoryFrame> &frame);

	std::shared_ptr<HistoryFrame> pop();
};

#endif //VM_HISTORYSTACK_H

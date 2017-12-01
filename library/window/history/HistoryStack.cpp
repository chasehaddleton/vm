//
// Created by Slayorious on 2017-11-26.
//

#include "HistoryStack.h"

void HistoryStack::push(std::shared_ptr<HistoryFrame> &frame) {
    history.push(frame);
}

std::shared_ptr<HistoryFrame> HistoryStack::pop() {
    std::shared_ptr<HistoryFrame> tmp{std::move(history.top())};
    history.pop();
    return tmp;
}

void HistoryStack::clear(){
    while(!history.empty()) {
        history.pop();
    }
}
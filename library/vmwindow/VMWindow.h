//
// Created by Slayorious on 2017-11-28.
//

#ifndef VM_VMWINDOW_H
#define VM_VMWINDOW_H

#include "VMDataSource.h"

class VMWindow {
    VMDataSource dataSource;
    // Some kind of cursor?
    //VMDisplay display;

    // Notifies the display when a change is made to the VMDataSource
    void drawDisplay();

public:
    // Give the window a character to deal with
    void recieveInput(const char c);
};

#endif //VM_VMWINDOW_H

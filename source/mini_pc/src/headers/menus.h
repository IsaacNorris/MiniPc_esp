#pragma once

#include "graphics.h"

class tMenuManager
{
public:
    tMenuManager(tGraphicManager *graphics) : graphics_(graphics)
    {
    }
    ~tMenuManager()
    {
    }

    void DisplayMenu();

private:
    tGraphicManager *graphics_;
};

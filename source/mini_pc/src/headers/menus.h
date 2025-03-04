#pragma once

#include "graphics.h"

enum class eInputType
{
    Up,
    Down,
    Enter
};

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

    void Input(eInputType type);

    // TODO: add in the funcitonality form the watch.

private:
    tGraphicManager *graphics_;
};

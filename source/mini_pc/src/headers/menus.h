#pragma once

#include "graphics.h"
#include "menuItems.h"

#include <vector>
#include <algorithm>

enum class eInputType
{
    Up,
    Down,
    Enter
};

enum class eMenuType
{
    MainMenu,
    SettingsMenu
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
    eMenuType currentMenu = eMenuType::MainMenu;
};

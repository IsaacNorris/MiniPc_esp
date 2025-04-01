#pragma once

#include "graphics.h"
#include "menuItems.h"

#include <vector>
#include <algorithm>

// this is where im makeing the menus lol;
// it seems this is the best way to do this
// if there is a performance hit it should only be on the first startup on the watch

namespace MakeMenus
{

    tMenu mainMenu;
    tMenu settingMenu;

    void MakeMenus()
    {
        // main menu

        tListItem *mainSetting = new tListItem("Settings", eListType::Empty);
        mainSetting->nextList = &settingMenu;

        mainMenu.AddItem(new tListItem("Set Time", eListType::Empty));
        mainMenu.AddItem(mainSetting);
        mainMenu.AddItem(new tListItem("Connections", eListType::Empty));
        mainMenu.AddItem(new tListItem("Exit", eListType::Empty));

        // settings menu

        tListItem *settingsExit = new tListItem("Exit", eListType::Empty);
        settingsExit->nextList = &mainMenu;

        settingMenu.AddItem(new tListItem("24 Hour Time", eListType::Toggle));
        settingMenu.AddItem(new tListItem("Turn Off Time", eListType::Toggle));
        settingMenu.AddItem(settingsExit);
    }
}

class tMenuManager
{
public:
    tMenuManager(tGraphicManager *graphics) : graphics_(graphics)
    {
        MakeMenus::MakeMenus();
    }
    ~tMenuManager()
    {
    }

    void DisplayMenu();

    void Input(eInputType type);

    // TODO: add in the funcitonality form the watch.

private:
    tMenu *currentMenuItem = &MakeMenus::mainMenu;

    tGraphicManager *graphics_;
};

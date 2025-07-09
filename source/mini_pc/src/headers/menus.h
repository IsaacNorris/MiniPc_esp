#pragma once

#include "graphics.h"
#include "menuItems.h"

#include <vector>
#include <algorithm>

class tMenuManager
{
public:
    tMenuManager(tGraphicManager *graphics) : graphics_(graphics)
    {
        MakeMenus();
        currentMenuItem = &mainMenu;
    }
    ~tMenuManager()
    {
    }

    void DisplayMenu();

    bool Input(eInputType type);

    // TODO: add in the funcitonality form the watch.

private:
    tMenu *currentMenuItem; 

    tMenu mainMenu;
    tMenu settingMenu;
    tMenu setTimeMenu;

    tGraphicManager *graphics_;

    void MakeMenus()
    {
        // main menu

        tListItem *mainSetting = new tListItem("Settings", eListType::Empty);
        mainSetting->nextList = &settingMenu;

        mainMenu.AddItem(mainSetting);
        mainMenu.AddItem(new tListItem("Connections", eListType::Empty));
        mainMenu.AddItem(new tListItem("Exit", eListType::Empty));

        // settings menu

        tListItem *settingsExit = new tListItem("Exit", eListType::Empty);
        settingsExit->nextList = &mainMenu;

        tListItem *setTimeSetting = new tListItem("Set Time", eListType::Empty);
        setTimeSetting->nextList = &setTimeMenu;

        settingMenu.AddItem(setTimeSetting);
        settingMenu.AddItem(new tListItem("24 Hour Time", eListType::Toggle));
        settingMenu.AddItem(new tListItem("Turn Off Time", eListType::Toggle));
        settingMenu.AddItem(settingsExit);

        // set time menu

        tListItem *setTimeExit = new tListItem("Exit", eListType::Empty);
        setTimeExit->nextList = &settingMenu;

        setTimeMenu.AddItem(new tListItem("Secs", eListType::Number, 0, 59));
        setTimeMenu.AddItem(new tListItem("Mins", eListType::Number, 0, 59));
        setTimeMenu.AddItem(new tListItem("Hours", eListType::Number, 0, 24));
        setTimeMenu.AddItem(setTimeExit);
    }
};

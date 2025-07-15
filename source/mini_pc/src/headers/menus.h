#pragma once

#include "graphics.h"
#include "menuItems.h"
#include "settings.h"

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
        auto fEmpty = [](uint8_t){};
        // main menu

        tListItem *mainSetting = new tListItem("Settings", eListType::Empty, fEmpty);
        mainSetting->nextList = &settingMenu;

        mainMenu.AddItem(mainSetting);
        mainMenu.AddItem(new tListItem("Connections", eListType::Empty, fEmpty));
        mainMenu.AddItem(new tListItem("Exit", eListType::Empty, fEmpty));

        // settings menu

        tListItem *settingsExit = new tListItem("Exit", eListType::Empty, [](uint8_t data){Settings::settings.SaveSettings();});
        settingsExit->nextList = &mainMenu;

        tListItem *setTimeSetting = new tListItem("Set Time", eListType::Empty, [this](uint8_t){
            setTimeMenu.GetListItemsMod().at(0)->SetData(static_cast<int>(Settings::settings.GetSec()));
            setTimeMenu.GetListItemsMod().at(1)->SetData(static_cast<int>(Settings::settings.GetMin()));
            setTimeMenu.GetListItemsMod().at(2)->SetData(static_cast<int>(Settings::settings.GetHour()));
        });
        setTimeSetting->nextList = &setTimeMenu;

        settingMenu.AddItem(setTimeSetting);
        settingMenu.AddItem(new tListItem("24 Hour Time", eListType::Toggle, fEmpty));
        settingMenu.AddItem(new tListItem("Turn Off Time", eListType::Toggle, fEmpty));
        settingMenu.AddItem(settingsExit);

        // set time menu

        tListItem *setTimeExit = new tListItem("Exit", eListType::Empty, fEmpty);
        setTimeExit->nextList = &settingMenu;

        setTimeMenu.AddItem(new tListItem("Secs", eListType::Number, [](uint8_t data){Settings::settings.SetSec(data); }, 0, 59));
        setTimeMenu.AddItem(new tListItem("Mins", eListType::Number, [](uint8_t data){Settings::settings.SetMin(data); }, 0, 59));
        setTimeMenu.AddItem(new tListItem("Hours", eListType::Number, [](uint8_t data){Settings::settings.SetHour(data); }, 0, 24));
        setTimeMenu.AddItem(setTimeExit);
    }
};

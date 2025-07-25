#pragma once

#include "graphics.h"
#include "menuItems.h"
#include "settings.h"

#include <vector>
#include <algorithm>

class tMenuManager
{
public:
    tMenuManager(tGraphicManager *graphics, tSettings *settings) : graphics_(graphics), settings_(settings)
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
    tSettings *settings_;

    tMenu *currentMenuItem; 

    tMenu mainMenu;
    tMenu settingMenu;
    tMenu setTimeMenu;
    tMenu setDateMenu;
    tMenu displayMenu;

    tGraphicManager *graphics_;

    void MakeMenus()
    {
        auto fEmpty = [](int){};
        // main menu

        tListItem *mainSetting = new tListItem("Settings", eListType::Empty, [this](int){});
        mainSetting->nextList = &settingMenu;

        mainMenu.AddItem(mainSetting);
        mainMenu.AddItem(new tListItem("Connections", eListType::Empty, fEmpty));
        mainMenu.AddItem(new tListItem("Exit", eListType::Empty, fEmpty));

        // settings menu

        tListItem *settingsExit = new tListItem("Exit", eListType::Empty, [this](int data){settings_->SaveSettings();});
        settingsExit->nextList = &mainMenu;

        tListItem *setTimeSetting = new tListItem("Set Time", eListType::Empty, [this](int){
            setTimeMenu.GetListItemsMod().at(0)->SetData(static_cast<int>(settings_->GetSec()));
            setTimeMenu.GetListItemsMod().at(1)->SetData(static_cast<int>(settings_->GetMin()));
            setTimeMenu.GetListItemsMod().at(2)->SetData(static_cast<int>(settings_->GetHour()));
        });
        setTimeSetting->nextList = &setTimeMenu;

        tListItem *setDateSetting = new tListItem("Set Date", eListType::Empty, [this](int){
            setDateMenu.GetListItemsMod().at(0)->SetData(static_cast<int>(settings_->GetDay()));
            setDateMenu.GetListItemsMod().at(1)->SetData(static_cast<int>(settings_->GetMonth()));
            setDateMenu.GetListItemsMod().at(2)->SetData(static_cast<int>(settings_->GetYear()));
        });
        setDateSetting->nextList = &setDateMenu;

        tListItem * displaySetting = new tListItem("Display", eListType::Empty, [this](int){
            displayMenu.GetListItemsMod().at(0)->SetData(static_cast<int>(settings_->GetTwentyFour())); 
            displayMenu.GetListItemsMod().at(1)->SetData(static_cast<int>(settings_->GetTurnOffSecs()));
            displayMenu.GetListItemsMod().at(2)->SetData(static_cast<int>(settings_->GetDarkMode()));
        });
        displaySetting->nextList = &displayMenu;

        settingMenu.AddItem(setTimeSetting);
        settingMenu.AddItem(setDateSetting);
        settingMenu.AddItem(displaySetting);
        settingMenu.AddItem(settingsExit);

        // set time menu

        tListItem *setTimeExit = new tListItem("Exit", eListType::Empty, [this](int){
            settings_->SetTimeOnly(setTimeMenu.GetListItemsMod().at(0)->GetData(), setTimeMenu.GetListItemsMod().at(1)->GetData(), setTimeMenu.GetListItemsMod().at(2)->GetData());
        });
        setTimeExit->nextList = &settingMenu;

        setTimeMenu.AddItem(new tListItem("Secs", eListType::Number, fEmpty, 0, 59));
        setTimeMenu.AddItem(new tListItem("Mins", eListType::Number, fEmpty, 0, 59));
        setTimeMenu.AddItem(new tListItem("Hours", eListType::Number, fEmpty, 0, 23));
        setTimeMenu.AddItem(setTimeExit);

        //set date menu

        tListItem *setDateExit = new tListItem("Exit", eListType::Empty, [this](int){
            settings_->SetDateOnly(setDateMenu.GetListItemsMod().at(0)->GetData(), setDateMenu.GetListItemsMod().at(1)->GetData(), setDateMenu.GetListItemsMod().at(2)->GetData());
        });
        setDateExit->nextList = &settingMenu;

        setDateMenu.AddItem(new tListItem("Day", eListType::Number, fEmpty, 1, 31));
        setDateMenu.AddItem(new tListItem("Month", eListType::Number, fEmpty, 1, 12));
        setDateMenu.AddItem(new tListItem("Year", eListType::Number, fEmpty, 2025, 2199));
        setDateMenu.AddItem(setDateExit);

        //set display settings

        tListItem * displayExit = new tListItem("Exit", eListType::Empty, [this](int){

        });
        displayExit->nextList = &settingMenu;

        displayMenu.AddItem(new tListItem("24 Hour Time", eListType::Toggle, [this](int data){ settings_->SetTwentyFour(static_cast<bool>(data)); }));
        displayMenu.AddItem(new tListItem("Turn Off Time", eListType::Number, [this](int data){ settings_->SetTurnOffSecs(data); }, 5, 30, 5));
        displayMenu.AddItem(new tListItem("Dark Mode", eListType::Toggle, [this](int data){ settings_->SetDarkMode(static_cast<bool>(data)); }));

        displayMenu.AddItem(displayExit);

    }
};

#pragma once

#include "Arduino.h"
#include "graphics.h"
#include "devices.h"
#include "menus.h"
#include "settings.h"

enum class eStates
{
    Start,
    Idle,
    Menu,
    sleep,
    // TODO add other states.
    Size
};

class tStateManager
{
public:
    tStateManager(tDeviceManager *deviceManager, tGraphicManager *graphicManager, tSettings *settings) : deviceManager_(deviceManager), graphicManager_(graphicManager), menus_(graphicManager, settings), settings_(settings)
    {
    }
    ~tStateManager()
    {
    }
    void Loop();
    void SetState(eStates state);

private:
    void Start();
    void Idle();
    void Menu();
    void Sleep(); 

    tDeviceManager *deviceManager_;
    tGraphicManager *graphicManager_;
    tSettings *settings_;

    tMenuManager menus_;

    eStates currentState_;
};
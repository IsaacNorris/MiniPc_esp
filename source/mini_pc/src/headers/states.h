#pragma once

#include "Arduino.h"
#include "graphics.h"
#include "devices.h"
#include "clock.h"
#include "menus.h"
#include "settings.h"

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

private:
    void Start();
    void Idle();
    void Menu();

    enum class eStates
    {
        Start,
        Idle,
        Menu,
        // TODO add other states.
        Size
    };

    tDeviceManager *deviceManager_;
    tGraphicManager *graphicManager_;
    tSettings *settings_;

    tMenuManager menus_;

    eStates currentState_;
};
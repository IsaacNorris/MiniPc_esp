#pragma once

#include "Arduino.h"
#include "graphics.h"
#include "devices.h"
#include "clock.h"
#include "menus.h"

class tStateManager
{
public:
    tStateManager(tDeviceManager *deviceManager, tGraphicManager *graphicManager, tSysClock *sysClock) : deviceManager_(deviceManager), graphicManager_(graphicManager), sysClock_(sysClock), menus_(graphicManager)
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
    tSysClock *sysClock_;

    tMenuManager menus_;

    eStates currentState_;
};
#pragma once

#include "Arduino.h"
#include "graphics.h"
#include "devices.h"
#include "clock.h"

class tStateManager
{
public:
    tStateManager(tDeviceManager *deviceManager, tGraphicManager *graphicManager, tSysClock *sysClock) : deviceManager_(deviceManager), graphicManager_(graphicManager), sysClock_(sysClock)
    {
    }
    ~tStateManager()
    {
    }
    void Loop();

private:
    void Start();
    void Idle();

    enum class eStates
    {
        Start,
        Idle,
        // TODO add other states.
        Size
    };

    tDeviceManager *deviceManager_;
    tGraphicManager *graphicManager_;
    tSysClock *sysClock_;

    eStates currentState_;
};
#pragma once

#include "Arduino.h"

class tStateManager
{
public:
    tStateManager()
    {
    }
    ~tStateManager()
    {
    }
    void Loop();

private:
    enum class eStates
    {
        Start,
        Idle,
        // TODO add other states.
        Size
    };

    eStates currentState_;
};
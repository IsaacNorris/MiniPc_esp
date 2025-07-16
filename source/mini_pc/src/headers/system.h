#pragma once

#include <Arduino.h>
#include "wire.h"

#include "graphics.h"
#include "devices.h"
#include "comms.h"
#include "states.h"
#include "clock.h"

class tSystem
{
public:
    tSystem() : states_(&devices_, &graphics_, &clock_, &settings_), clock_(&settings_)
    {
        Serial.begin(9600);
        startMillis = millis();
    }

    ~tSystem()
    {
    }

    void StartUp();
    void Loop();

    static constexpr int secondLength = 1000;
    unsigned long startMillis;
    unsigned long currentMillis;

private:
    void controlTick();

    tGraphicManager graphics_;
    tDeviceManager devices_;
    tCommsManager comms_;
    tStateManager states_;
    tSysClock clock_;
    tSettings settings_;
};

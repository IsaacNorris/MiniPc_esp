#pragma once

#include <Arduino.h>
#include "wire.h"

#include "graphics.h"
#include "devices.h"
#include "comms.h"
#include "states.h"

class tSystem
{
public:
    tSystem() : graphics_(&settings_), states_(&devices_, &graphics_, &settings_)
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
    tGraphicManager graphics_;
    tDeviceManager devices_;
    tCommsManager comms_;
    tStateManager states_;
    tSettings settings_;
};

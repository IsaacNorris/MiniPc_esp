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
    tSystem() : settings_(), graphics_(&settings_), states_(&devices_, &graphics_, &settings_)
    {
        Serial.begin(9600);
        startMillis = millis();
    }

    ~tSystem()
    {
    }

    void StartUp();
    void Loop();
private:

    unsigned long startMillis;
    unsigned long currentMillis;

    tGraphicManager graphics_;
    tDeviceManager devices_;
    tCommsManager comms_;
    tStateManager states_;
    tSettings settings_;

    void SleepTimer();
    int GetBatteryPercentage();

    static constexpr unsigned int secondFromMs = 1000; 
};

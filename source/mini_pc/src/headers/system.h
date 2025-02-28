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
    tSystem()
    {
        Serial.begin(9600);
    }

    ~tSystem()
    {
    }

    void StartUp();
    void Loop();

private:
    tGraphicManager graphics_;
    tDeviceManager devices_;
    tCommsManager comms_;
    tStateManager states_;
};

// TODO: add the menu options similar to the old watch interface
// TODO: add a proccess manager
// TODO: add a clock process
// TODO: add a storage manager
// TODO: add a stopwatch process
// TODO: add a timer process
// TODO: add a adxl device
// TODO: add a step tracker process
// TODO: add a led graphic that is connected to the clock/timer/stopwatch processes
// TODO: figure out how to run multithread processes
// TODO: finish comms/network/bluetooth managers and link them to do functional things
//  - talk to ben about what the bluetooth/wifi would do.
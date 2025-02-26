#pragma once

#include <Arduino.h>
#include "graphics.h"
#include "wire.h"

class tSystem
{
public:
    tSystem() : graphics_(new tGraphicManager)
    {
        Serial.begin(9600);
    };

    ~tSystem()
    {
        delete graphics_;
    };

    void StartUp();
    void Loop();

private:
    tGraphicManager *graphics_;
};
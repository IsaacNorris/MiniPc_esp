#pragma once

#include "wire.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

class tGraphicManager
{
public:
    tGraphicManager() : display_(Adafruit_SSD1306(128, 64, &Wire))
    {
    }

    ~tGraphicManager()
    {
    }

    bool BeginDisplay();
    void ClearDisplay();
    void WriteToScreen(const String &str);
    void Display();

    void PrintToScreen(const String &str);

private:
    Adafruit_SSD1306 display_;
};

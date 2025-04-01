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
    void WriteToScreen(const std::string &str);
    void Display();

    void PrintToScreen(const std::string &str);

private:
    Adafruit_SSD1306 display_;
};

// TODO: add themes in for the watch face.

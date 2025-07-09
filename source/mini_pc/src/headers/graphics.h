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
    void WriteToScreen(const std::string &str, uint8_t x = 0, uint8_t y = 0, uint8_t ts = 1);
    void Display();

    void PrintToScreen(const std::string &str);

    void PrintClockToScreen(const std::string &str);

private:
    Adafruit_SSD1306 display_;
};

// TODO: add themes in for the watch face.

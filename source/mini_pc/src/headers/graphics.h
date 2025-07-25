#pragma once

#include "wire.h"
#include "settings.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

class tGraphicManager
{
public:
    tGraphicManager(tSettings* setting) : display_(Adafruit_SSD1306(128, 64, &Wire)), settings_(setting)
    {
    }

    ~tGraphicManager()
    {
    }

    bool BeginDisplay();
    void ClearDisplay();
    void WriteToScreen(const std::string &str, int x = 0, int y = 0, int ts = 1);
    void Display();

    void PrintToScreen(const std::string &str);

    void PrintClockToScreen(const std::string &str);
    void PrintAmPmAndDateToScreen(const std::string &ampmStr, const std::string &dateStr, const std::string &batteryString);

private:
    Adafruit_SSD1306 display_;
    tSettings* settings_;

    static constexpr int maxLineLength = 22;
};

// TODO: add themes in for the watch face.

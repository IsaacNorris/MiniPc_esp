#pragma once

#include "wire.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

class tGraphics {
public:
    tGraphics():
    display_(new Adafruit_SSD1306(128, 64, &Wire, -1))
    {

    }

    ~tGraphics(){
        delete display_;
    }

    bool BeginDisplay();
    void ClearDisplay();
    void WriteToScreen(const String& str);
    void Display();

    void PrintToScreen(const String& str);

private:
    Adafruit_SSD1306* display_;
};

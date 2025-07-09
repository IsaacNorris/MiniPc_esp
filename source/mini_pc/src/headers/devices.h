#pragma once

#include <Arduino.h>
#include <ezButton.h>
#include <array>
#include "constant.h"

enum class eButtonType
{
    Up,
    Down,
    Enter,
    Size
};

class tDeviceManager
{
public:
    tDeviceManager() : upButton_(BUTTON_UP_PIN, INTERNAL_PULLDOWN),
                       downButton_(BUTTON_DOWN_PIN, INTERNAL_PULLDOWN),
                       enterButton_(BUTTON_ENTER_PIN, INTERNAL_PULLDOWN)
    {
        upButton_.setDebounceTime(10);
        downButton_.setDebounceTime(10);
        enterButton_.setDebounceTime(10);
    }

    ~tDeviceManager()
    {
    }

    void Loop();

    eButtonType ButtonPressed();

private:
    ezButton upButton_;
    ezButton downButton_;
    ezButton enterButton_;
};
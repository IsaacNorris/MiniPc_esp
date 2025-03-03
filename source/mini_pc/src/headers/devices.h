#pragma once

#include <Arduino.h>
#include <ezButton.h>
#include <array>

#define WATCH_PRj false

enum class eButtonType
{
    Up,
    Down,
    Enter,
    Right,
    Left,
    Back,
    Size
};

class tDeviceManager
{
public:
    tDeviceManager() : upButton_(buttonUpPin, INTERNAL_PULLDOWN),
                       downButton_(buttonDownPin, INTERNAL_PULLDOWN),
                       enterButton_(buttonEnterPin, INTERNAL_PULLDOWN) /*,
     leftButton_(buttonLeftPin, INTERNAL_PULLDOWN),
     rightButton_(buttonRightPin, INTERNAL_PULLDOWN),
     backButton_(buttonBackPin, INTERNAL_PULLDOWN)*/
    // re-include this if using the MINIPC PCB/PRJ
    {
        upButton_.setDebounceTime(50);
        downButton_.setDebounceTime(50);
        enterButton_.setDebounceTime(50);
    }

    ~tDeviceManager()
    {
    }

    void Loop();

    bool ButtonPressed(eButtonType type);

private:
    ezButton *GetButton(eButtonType type);

    ezButton upButton_;
    ezButton downButton_;
    ezButton enterButton_;
    // ezButton leftButton_;
    // ezButton rightButton_;
    // ezButton backButton_;
#if WATCH_PRj
#warning Get Ben to tell me the pin numbers. for the input buttons.
    static constexpr uint8_t buttonUpPin = 20;
    static constexpr uint8_t buttonDownPin = 20;
    static constexpr uint8_t buttonEnterPin = 20;
#else
    static constexpr uint8_t buttonUpPin = 25;
    static constexpr uint8_t buttonDownPin = 33;
    static constexpr uint8_t buttonEnterPin = 35;
    // static constexpr uint8_t buttonLeftPin = 26;
    // static constexpr uint8_t buttonRightPin = 32;
    // static constexpr uint8_t buttonBackPin = 34;
#endif
};
#pragma once

#include <Arduino.h>
#include <array>

struct tButton
{
    tButton(uint8_t pin) : pin_(pin)
    {
        pinMode(pin_, INPUT);
    }

    enum class eButtonState
    {
        Off,
        Pressed,
        Released
    };

    uint8_t pin_;
    bool isActive_;
    eButtonState currentState_;

    void CheckInput()
    {
        if (digitalRead(pin_) == HIGH)
        {
            currentState_ = eButtonState::Pressed;
            isActive_ = true;
        }
        else if (isActive_)
        {
            currentState_ = eButtonState::Released;
            isActive_ = false;
        }
        else
        {
            currentState_ = eButtonState::Off;
            isActive_ = false;
        }
    }
};

class tDeviceManager
{
public:
    tDeviceManager() : upButton_(buttonUpPin), downButton_(buttonDownPin), enterButton_(buttonEnterPin)
    {
    }

    ~tDeviceManager()
    {
    }

    void Loop();

private:
    tButton upButton_;
    tButton downButton_;
    tButton enterButton_;

#warning Get Ben to tell me the pin numbers. for the input buttons.
    static constexpr uint8_t buttonUpPin = 20;
    static constexpr uint8_t buttonDownPin = 20;
    static constexpr uint8_t buttonEnterPin = 20;
};
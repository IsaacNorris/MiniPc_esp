#include "../headers/devices.h"

void tDeviceManager::Loop()
{
    upButton_.loop();
    downButton_.loop();
    enterButton_.loop();
}

ezButton *tDeviceManager::GetButton(eButtonType type)
{
    switch (type)
    {
    case eButtonType::Up:
        return &upButton_;
        break;
    case eButtonType::Down:
        return &downButton_;
        break;
    case eButtonType::Enter:
        return &enterButton_;
        break;
    case eButtonType::Size:
        Serial.println("error: eButtonType::size reached");
        break;
    }
}

bool tDeviceManager::ButtonPressed(eButtonType type)
{
    return GetButton(type)->isPressed();
}
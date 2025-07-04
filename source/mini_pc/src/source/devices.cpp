#include "../headers/devices.h"

void tDeviceManager::Loop()
{
    enterButton_.loop();
    upButton_.loop();
    downButton_.loop();
}

eButtonType tDeviceManager::ButtonPressed()
{
    eButtonType type = eButtonType::Size; 

    if(downButton_.isPressed()){
        type = eButtonType::Down;
    }  
    else if(upButton_.isPressed()){
        type = eButtonType::Up;
    }
    else if(enterButton_.isPressed()){
        type = eButtonType::Enter;
    }
    return type;
}
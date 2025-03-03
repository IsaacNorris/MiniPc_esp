#include "../headers/states.h"

void tStateManager::Loop()
{
    switch (currentState_)
    {
    case eStates::Start:
        Start();
        break;
    case eStates::Idle:
        Idle();
        break;
    case eStates::Size:
        // Should not come to this
        Serial.println("ERROR: STATE MACHINE FAILURE");
        break;
    };
}

void tStateManager::Start()
{
    Serial.println("start state machin");
    currentState_ = eStates::Idle;
}

void tStateManager::Idle()
{

    graphicManager_->PrintToScreen(sysClock_->DisplayFace().c_str());

    if (deviceManager_->ButtonPressed(eButtonType::Up))
    {
        graphicManager_->PrintToScreen("Up");
    }
    else if (deviceManager_->ButtonPressed(eButtonType::Down))
    {
        graphicManager_->PrintToScreen("Down");
    }
    else if (deviceManager_->ButtonPressed(eButtonType::Enter))
    {
        graphicManager_->PrintToScreen("Enter");
    }
}
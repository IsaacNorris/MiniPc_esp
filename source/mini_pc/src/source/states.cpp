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
    case eStates::Menu:
        Menu();
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

    if (deviceManager_->ButtonPressed(eButtonType::Enter))
    {
        currentState_ = eStates::Menu;
    }
}

void tStateManager::Menu()
{
    menus_.DisplayMenu();

    if (deviceManager_->ButtonPressed(eButtonType::Enter))
    {
        if(!menus_.Input(eInputType::Enter)){
            currentState_ = eStates::Idle;
        }
    } else if (deviceManager_->ButtonPressed(eButtonType::Down))
    {
        menus_.Input(eInputType::Down);
    }else if (deviceManager_->ButtonPressed(eButtonType::Up))
    {
        menus_.Input(eInputType::Up);
    }
}
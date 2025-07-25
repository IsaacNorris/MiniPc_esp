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
    case eStates::sleep:
        Sleep();
        break;
    case eStates::Size:
        // Should not come to this
        Serial.println("ERROR: STATE MACHINE FAILURE");
        break;
    };
}

void tStateManager::SetState(eStates state)
{
    currentState_ = state;
}

void tStateManager::Start()
{
    Serial.println("start state machin");
    currentState_ = eStates::Idle;
}

void tStateManager::Idle()
{

    graphicManager_->PrintAmPmAndDateToScreen(settings_->GetAmPm(), settings_->GetDate(), settings_->GetBatteryString());
    graphicManager_->PrintClockToScreen(settings_->GetTime());

    switch(deviceManager_->ButtonPressed()){
        case eButtonType::Enter:
            Serial.println("Enter");

            currentState_ = eStates::Menu;
            break;
        case eButtonType::Down:
            Serial.println("Down");
            break;
        case eButtonType::Up:
            Serial.println("Up");
            break;
        default:
            break;
    }
}

void tStateManager::Menu()
{
    menus_.DisplayMenu();

    switch(deviceManager_->ButtonPressed()){
        case eButtonType::Enter:
            Serial.println("Enter");
            if(!menus_.Input(eInputType::Enter)){
                currentState_ = eStates::Idle;
            }
            break;
        case eButtonType::Down:
            Serial.println("Down");
            menus_.Input(eInputType::Down);
            break;
        case eButtonType::Up:
            Serial.println("Up");
            menus_.Input(eInputType::Up);
            break;
        default:
            break;
    } 
}

void tStateManager::Sleep()
{
    settings_->SetDarkMode(false);
    graphicManager_->ClearDisplay();
    graphicManager_->Display();
    esp_deep_sleep_start();
}

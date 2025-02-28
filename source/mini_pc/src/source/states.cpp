#include "../headers/states.h"

void tStateManager::Loop()
{
    switch (currentState_)
    {
    case eStates::Start:
        break;
    case eStates::Idle:
        break;
    case eStates::Size:
        // Should not come to this
        Serial.println("ERROR: STATE MACHINE FAILURE");
        break;
    };
}
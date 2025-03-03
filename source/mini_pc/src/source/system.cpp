#include "../headers/system.h"

void tSystem::StartUp()
{
    if (graphics_.BeginDisplay())
        Serial.println("SCREEN CONNECTED");
    else
        Serial.println("SCREEN NOT CONNECTED");

    graphics_.PrintToScreen("starting ...");
    delay(500);
}

void tSystem::Loop()
{
    devices_.Loop(); // should be first thing in loop :)
    comms_.Loop();
    states_.Loop();

    if (devices_.ButtonPressed(eButtonType::Up))
    {
        graphics_.PrintToScreen("Up");
    }
    else if (devices_.ButtonPressed(eButtonType::Down))
    {
        graphics_.PrintToScreen("Down");
    }
    else if (devices_.ButtonPressed(eButtonType::Enter))
    {
        graphics_.PrintToScreen("Enter");
    }
}

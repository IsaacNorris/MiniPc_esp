#include "../headers/system.h"

void tSystem::StartUp()
{
    if (graphics_.BeginDisplay())
    {
        Serial.println("SCREEN CONNECTED");
    }
    else
    {
        Serial.println("SCREEN NOT CONNECTED");
    }

    graphics_.ClearDisplay();
    graphics_.PrintClockToScreen("starting");
    settings_.LoadSettings();
    
    delay(2000);
}

void tSystem::Loop()
{
    devices_.Loop(); // should be first thing in loop :)
    comms_.Loop();

    states_.Loop();
}
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

    graphics_.PrintToScreen("starting ...");
    delay(1000);
}

void tSystem::Loop()
{
    devices_.Loop(); // should be first thing in loop :)
    comms_.Loop();

    currentMillis = millis();
    controlTick();

    states_.Loop();
}

void tSystem::controlTick()
{
    if (currentMillis - startMillis >= 1000)
    {
        clock_.UpdateClock();
        startMillis = currentMillis;
    }
}
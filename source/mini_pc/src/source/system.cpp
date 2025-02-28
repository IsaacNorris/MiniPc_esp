#include "../headers/system.h"

void tSystem::StartUp()
{
#warning Need to confirm this with a working esp32 and ssd1306 display
    if (graphics_.BeginDisplay())
        Serial.println("SCREEN CONNECTED");
    else
        Serial.println("SCREEN NOT CONNECTED");

    graphics_.PrintToScreen("started");
}

void tSystem::Loop()
{
    devices_.Loop(); // should be first thing in loop :)
    comms_.Loop();
    states_.Loop();
}

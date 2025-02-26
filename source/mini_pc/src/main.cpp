#include <Arduino.h>

#include "headers/system.h"

tSystem sys__;

void setup()
{
    sys__.StartUp();
}

void loop()
{
    sys__.Loop();
}
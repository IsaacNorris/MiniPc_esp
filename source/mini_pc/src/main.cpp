#include <Arduino.h>
#include "System.h"

tSystem system;

void setup() {
  system.SystemStartup();
}

void loop() {
  system.SystemLoop();
}

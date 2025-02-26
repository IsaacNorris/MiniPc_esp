#include "../headers/system.h"

void tSystem::StartUp(){
    
    if(graphics_->BeginDisplay()) Serial.println("SCREEN CONNECTED");
    else Serial.println("SCREEN NOT CONNECTED");
    
    graphics_->PrintToScreen("started");
}

void tSystem::Loop(){
    
}


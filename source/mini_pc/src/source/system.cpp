#include "../headers/system.h"

void tSystem::StartUp()
{
    Serial.begin(9600);

    if (graphics_.BeginDisplay())
    {
        Serial.println("SCREEN CONNECTED");
    }
    else
    {
        Serial.println("SCREEN NOT CONNECTED");
    }

    graphics_.ClearDisplay();

    esp_deep_sleep_enable_gpio_wakeup(BIT(D1), ESP_GPIO_WAKEUP_GPIO_HIGH);

    startMillis = millis();
    settings_.LoadSettings();    
}

void tSystem::Loop()
{
    devices_.Loop(); // should be first thing in loop :)

    SleepTimer();

    comms_.Loop();

    states_.Loop(); 
}

void tSystem::SleepTimer(){
    if(devices_.ButtonPressed() != eButtonType::Size){
        startMillis = millis();
    }

    currentMillis = millis();

    if((currentMillis - startMillis) >= settings_.GetTurnOffSecs() * secondFromMs){ 
        states_.SetState(eStates::sleep);
    }
}
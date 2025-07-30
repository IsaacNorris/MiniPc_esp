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

    // sets up the battery monitor pin.
    pinMode(A0, INPUT);

    startMillis = millis();
    settings_.LoadSettings();
}

void tSystem::Loop()
{
    devices_.Loop(); // should be first thing in loop :)

    SleepTimer();
    settings_.SetBattery(GetBatteryPercentage());

    comms_.Loop();

    states_.Loop(); 
}

int tSystem::GetBatteryPercentage(){
    int vBatt = 0;
    for(int i = 0; i < 16; i++){
        vBatt += analogReadMilliVolts(A0);
    }
    float vBattf = 2 * vBatt / 16;
    const float battMax = 4200;
    const float battMin = 3000;

    float battPercentage = (vBattf - battMin) / (battMax - battMin);
    battPercentage *= 100;

    return static_cast<int>(battPercentage);
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
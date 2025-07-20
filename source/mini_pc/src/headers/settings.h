#pragma once

#include "arduino.h"
#include <Preferences.h> 
#include <ESP32Time.h>

class tSettings{
public:
    tSettings(){
    } 

    void SaveSettings(){
        preferences.begin(settingsAddressNamespace, false);        

        preferences.putBool(twentyFourHourAddress, twentyFourHour_);
        preferences.putUChar(turnOffSecsAddress, turnOffSecs_);

        preferences.end();
    }

    void SetTime(int sec, int min, int hour, int day, int month, int year){
        rtc_.setTime(sec, min, hour, day, month, year);
    }

    void SetTimeOnly(int sec, int min, int hour){
        rtc_.setTime(sec, min, hour, rtc_.getDay(), rtc_.getMonth(), rtc_.getYear());
    }

    std::string GetTime(){
        return std::string(rtc_.getTime().c_str());
    }

    void LoadSettings(){
        preferences.begin(settingsAddressNamespace, true);        

        twentyFourHour_ = preferences.getBool(twentyFourHourAddress, defaultTwentyFour);
        turnOffSecs_ = preferences.getUChar(turnOffSecsAddress, defaultTurnOffSecs);

        preferences.end();

        SetTime(0, 0, 0, 0, 0, 2025);
    }

    void ResetSettings(){
        preferences.begin(settingsAddressNamespace, false);        
        preferences.clear();
        preferences.end();        
        LoadSettings();
    }

    void SetSec(int value){
        SetTime(value, rtc_.getMinute(), rtc_.getHour(), rtc_.getDay(), rtc_.getMonth(), rtc_.getYear());
    }

    const uint8_t GetSec() { return static_cast<uint8_t>(rtc_.getSecond()); }

    void SetMin(int value){ 
        SetTime(rtc_.getSecond(), value, rtc_.getHour(), rtc_.getDay(), rtc_.getMonth(), rtc_.getYear());
    }

    const uint8_t GetMin() { return static_cast<uint8_t>(rtc_.getMinute()); }

    void SetHour(int value){ 
        SetTime(rtc_.getSecond(), rtc_.getMinute(), value, rtc_.getDay(), rtc_.getMonth(), rtc_.getYear());
    }

    const uint8_t GetHour() { return static_cast<uint8_t>(rtc_.getHour()); }


    const bool GetTwentyFour() const { return twentyFourHour_; }
    void SetTwentyFour(bool value){ twentyFourHour_ = value; }

    const uint8_t GetTurnOffSecs() const { return turnOffSecs_; }
    void SetTurnOffSecs(uint8_t value){ turnOffSecs_ = value; }

private:

Preferences preferences;
ESP32Time rtc_;

// default values:
static constexpr bool defaultTwentyFour = true;
static constexpr uint8_t defaultTurnOffSecs = 30;

// addresses
static constexpr const char* settingsAddressNamespace = "settings";

static constexpr const char* twentyFourHourAddress = "twentyfour";
static constexpr const char* turnOffSecsAddress = "turnoffsecs";


// values:
bool twentyFourHour_;
uint8_t turnOffSecs_;

};
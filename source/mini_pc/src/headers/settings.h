#pragma once

#include "arduino.h"
#include <Preferences.h> 

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

    void LoadSettings(){
        preferences.begin(settingsAddressNamespace, true);        

        twentyFourHour_ = preferences.getBool(twentyFourHourAddress, defaultTwentyFour);
        turnOffSecs_ = preferences.getUChar(turnOffSecsAddress, defaultTurnOffSecs);

        preferences.end();
    }

    void ResetSettings(){
        preferences.begin(settingsAddressNamespace, false);        
        preferences.clear();
        preferences.end();        
        LoadSettings();
    }

    const uint8_t GetSec() const { return sec_; }
    void SetSec(uint8_t value){ sec_ = value; }

    const uint8_t GetMin() const { return min_; }
    void SetMin(uint8_t value){ min_ = value; }

    const uint8_t GetHour() const { return hour_; }
    void SetHour(uint8_t value){ hour_ = value; }

    const bool GetTwentyFour() const { return twentyFourHour_; }
    void SetTwentyFour(bool value){ twentyFourHour_ = value; }

    const uint8_t GetTurnOffSecs() const { return turnOffSecs_; }
    void SetTurnOffSecs(uint8_t value){ turnOffSecs_ = value; }

private:

Preferences preferences;

// default values:
static constexpr bool defaultTwentyFour = true;
static constexpr uint8_t defaultTurnOffSecs = 30;

// addresses
static constexpr const char* settingsAddressNamespace = "settings";

static constexpr const char* twentyFourHourAddress = "twentyfour";
static constexpr const char* turnOffSecsAddress = "turnoffsecs";


// values:
uint8_t sec_;
uint8_t min_;
uint8_t hour_;

bool twentyFourHour_;
uint8_t turnOffSecs_;

};
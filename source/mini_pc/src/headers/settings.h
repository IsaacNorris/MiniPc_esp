#pragma once

#include "arduino.h"
#include <Preferences.h> 

class tSettings{
public:
    tSettings(){
    } 

    void SaveSettings(){
        preferences.begin(settingsAddressNamespace, false);        

        preferences.putUChar(secAddress, sec_);
        preferences.putUChar(minAddress, min_);
        preferences.putUChar(hourAddress, hour_);

        preferences.end();
    }

    void LoadSettings(){
        preferences.begin(settingsAddressNamespace, true);        

        sec_ = preferences.getUChar(secAddress, defaultSec);
        min_ = preferences.getUChar(minAddress, defaultMin);
        hour_ = preferences.getUChar(hourAddress, defaultHour);

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

private:

Preferences preferences;

static constexpr size_t eepromSize = 64; 

// default values:
static constexpr uint8_t defaultHour = 0;
static constexpr uint8_t defaultMin = 0;
static constexpr uint8_t defaultSec = 0;

// addresses
static constexpr const char* settingsAddressNamespace = "settings";

static constexpr const char* secAddress = "sec";
static constexpr const char* minAddress = "min";
static constexpr const char* hourAddress = "hour";

// values:
uint8_t sec_;
uint8_t min_;
uint8_t hour_;
};
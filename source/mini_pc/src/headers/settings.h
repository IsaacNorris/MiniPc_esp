#pragma once

#include "arduino.h"
#include <EEPROM.h>

#define EEPROM_SIZE 64

namespace Settings{
enum class eAddress{
    Seconds = 1,
    Minutes = 2,
    Hours = 3,
};


class tSettings{
public:
    tSettings(){
        
    } 

    void SaveSettings(){
        EEPROM.write(static_cast<int>(eAddress::Seconds), sec_);
        EEPROM.write(static_cast<int>(eAddress::Minutes), min_);
        EEPROM.write(static_cast<int>(eAddress::Hours), hour_);
    
        EEPROM.commit();
    }

    void LoadSettings(){
        sec_ = EEPROM.read(static_cast<int>(eAddress::Seconds));
        min_ = EEPROM.read(static_cast<int>(eAddress::Minutes));
        hour_ = EEPROM.read(static_cast<int>(eAddress::Hours));
    }

    void ResetSettings(){
        SetSec(defaultSec);
        SetMin(defaultMin);
        SetHour(defaultHour);
    }

    const uint8_t GetSec() const { return sec_; }
    void SetSec(uint8_t value){ sec_ = value; }

    const uint8_t GetMin() const { return min_; }
    void SetMin(uint8_t value){ min_ = value; }

    const uint8_t GetHour() const { return hour_; }
    void SetHour(uint8_t value){ hour_ = value; }

private:
// default values:
static constexpr uint8_t defaultHour = 0;
static constexpr uint8_t defaultMin = 0;
static constexpr uint8_t defaultSec = 0;

// values:
uint8_t sec_;
uint8_t min_;
uint8_t hour_;
};

static tSettings settings;

};
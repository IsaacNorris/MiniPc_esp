#pragma once

#include "arduino.h"

namespace Settings{
class tSettings{
public:
    tSettings(){
        ResetSettings();
    }

    ~tSettings(){

    }

    void SaveSettings(){

    }

    void LoadSettings(){

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
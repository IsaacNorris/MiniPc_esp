#pragma once

#include "arduino.h"
#include "settings.h"

struct tTime
{
    uint16_t time;

    enum class eFormat
    {
        AM,
        PM
    };
    enum class eTimeType
    {
        TwelveHour,
        TwentyFourHour
    };

    eFormat format;
    eTimeType timeType;

    void UpdateTime();
    void UpdateFace();

    std::string displayFace;

    void SetSec(int num);
    void SetMin(int num);
    void SetHour(int num);

    uint8_t Sec();
    uint8_t Min();
    uint8_t Hour();

    tSettings *settings_;
};

class tSysClock
{
public:
    tSysClock(tSettings *settings)
    {
        time_.settings_ = settings;
    }
    ~tSysClock()
    {
    }

    void UpdateClock();
    std::string &DisplayFace();

private:
    tTime time_;
};
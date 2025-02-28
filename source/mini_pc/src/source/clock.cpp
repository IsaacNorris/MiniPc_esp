#include "../headers/clock.h"

void tTime::UpdateTime()
{
    sec_++;
    if (sec_ == 60)
    {
        sec_ = 0;
        min_++;
    }
    if (min_ == 60)
    {
        min_ = 0;
        hour_++;
    }
    if (timeType == eTimeType::TwentyFourHour)
    {
        if (format == eFormat::PM)
        {
            hour_ += 12;
            format = eFormat::AM;
        }
        if (hour_ >= 24)
        {
            hour_ = 0;
        }
    }
    else
    {
        if (hour_ == 12)
            hour_ = 0;
        else if (hour_ > 12)
        {
            hour_ -= 12;
            format = format == eFormat::AM ? eFormat::PM : eFormat::AM;
        }
    }
}

void tTime::UpdateFace()
{
    displayFace.clear();
    if (hour_ < 10)
        displayFace.append("0");
    displayFace.append(std::to_string(hour_));
    displayFace.append(":");
    if (min_ < 10)
        displayFace.append("0");
    displayFace.append(std::to_string(min_));
    displayFace.append(":");
    if (sec_ < 10)
        displayFace.append("0");
    displayFace.append(std::to_string(sec_));

    if (timeType == eTimeType::TwelveHour)
    {
        std::string AMPMString = format == eFormat::AM ? "\n am" : "\n pm";
        displayFace.append(AMPMString.c_str());
    }
}

void tTime::SetSec()
{
}
void tTime::SetMin()
{
}
void tTime::SetHour()
{
}

uint8_t tTime::Sec()
{
    return sec_;
}
uint8_t tTime::Min()
{
    return min_;
}
uint8_t tTime::Hour()
{
    return hour_;
}

void tSysClock::UpdateClock()
{
    time_.UpdateTime();
}
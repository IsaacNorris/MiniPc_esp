#include "../headers/clock.h"

void tTime::UpdateTime()
{
    uint8_t sec_ = settings_->GetSec();
    uint8_t min_ = settings_->GetMin();
    uint8_t hour_ = settings_->GetHour();

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
        if (hour_ == 12){
            hour_ = 0;
        }else if (hour_ > 12)
        {
            hour_ -= 12;
            format = format == eFormat::AM ? eFormat::PM : eFormat::AM;
        }
    }

    settings_->SetSec(sec_);
    settings_->SetMin(min_);
    settings_->SetHour(hour_);

    UpdateFace();
}

void tTime::UpdateFace()
{
    uint8_t sec_ = settings_->GetSec();
    uint8_t min_ = settings_->GetMin();
    uint8_t hour_ = settings_->GetHour();
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
        std::string AMPMString = format == eFormat::AM ? "\n    am" : "\n    pm";
        displayFace.append(AMPMString.c_str());
    }
}

void tTime::SetSec(int num)
{
    uint8_t sec_ = num;
    if (sec_ < 0)
    {
        sec_ = 59;
    }
    if (sec_ > 59)
    {
        sec_ = 0;
    }

    settings_->SetSec(sec_);
}
void tTime::SetMin(int num)
{
    uint8_t min_ = num;
    if (min_ < 0)
    {
        min_ = 59;
    }
    if (min_ > 59)
    {
        min_ = 0;
    }

    settings_->SetMin(min_);
}
void tTime::SetHour(int num)
{
    uint8_t hour_ = num;
    if (timeType == eTimeType::TwentyFourHour)
    {
        if (hour_ < 0)
        {
            hour_ = 23;
        }
        if (hour_ > 23)
        {
            hour_ = 0;
        }
    }
    else
    {
        if (hour_ < 1)
        {
            hour_ = 12;
            format = format == eFormat::AM ? eFormat::PM : eFormat::AM;
        }
        if (hour_ > 12)
        {
            hour_ = 1;
            format = format == eFormat::AM ? eFormat::PM : eFormat::AM;
        }
    }

    settings_->SetHour(hour_);
}

uint8_t tTime::Sec()
{
    return settings_->GetSec();
}
uint8_t tTime::Min()
{
    return settings_->GetMin();
}
uint8_t tTime::Hour()
{
    return settings_->GetHour();
}

void tSysClock::UpdateClock()
{
    time_.UpdateTime();
}

std::string &tSysClock::DisplayFace()
{
    return time_.displayFace;
}
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
        preferences.putBool(darkModeAddress, darkMode_);

        preferences.end();
    }

    void SetTime(int sec, int min, int hour, int day, int month, int year){
        rtc_.setTime(sec, min, hour, day, month, year);
    }

    void SetTimeOnly(int sec, int min, int hour){
        rtc_.setTime(sec, min, hour, rtc_.getDay(), rtc_.getMonth() + 1, rtc_.getYear());
    }

    void SetDateOnly(int day, int month, int year){
        rtc_.setTime(rtc_.getSecond(), rtc_.getMinute(), rtc_.getHour(true), day, month, year);
    }

    std::string GetTime(){
        if(twentyFourHour_){
            return std::string(rtc_.getTime().c_str());
        }else{
            std::string time = "";
            int hour = rtc_.getHour();
            int minute = rtc_.getMinute();
            int second = rtc_.getSecond();
            if(hour < 10) time.append("0");
            time.append(std::to_string(hour));
            time.append(":");
            if(minute < 10) time.append("0");
            time.append(std::to_string(minute));
            time.append(":");
            if(second < 10) time.append("0");
            time.append(std::to_string(second));
            return time;
        }
    }

    void SetBattery(int value){
        batteryPercentage_ = value;
    }

    std::string GetBatteryString(){
        std::string battery = "";
        if(batteryPercentage_ < 100) battery.append(" ");
        if(batteryPercentage_ < 10) battery.append(" ");
        battery.append(std::to_string(batteryPercentage_));
        battery.append("%");
        return battery;
    }

    std::string GetAmPm(){
        return std::string(rtc_.getAmPm().c_str());
    }

    std::string GetDate(){
        std::string date = "";
        int day = rtc_.getDay();
        int month = rtc_.getMonth() + 1;
        int year = rtc_.getYear();
        if(day < 10) date.append("0");
        date.append(std::to_string(day));
        date.append("/");
        if(month < 10) date.append("0");
        date.append(std::to_string(month));
        date.append("/");
        date.append(std::to_string(year));
        return date;
    }

    void LoadSettings(){
        preferences.begin(settingsAddressNamespace, true);        

        twentyFourHour_ = preferences.getBool(twentyFourHourAddress, defaultTwentyFour);
        turnOffSecs_ = preferences.getUChar(turnOffSecsAddress, defaultTurnOffSecs);
        darkMode_ = preferences.getBool(darkModeAddress, defaultDarkMode);

        preferences.end();

        //My check  to see if the time has already been set. 
        //without this the time will be reset on wakeup.
        if(rtc_.getYear() < 2025){
            SetTime(0, 0, 0, 1, 11, 2025);
        }
    }

    void ResetSettings(){
        preferences.begin(settingsAddressNamespace, false);        
        preferences.clear();
        preferences.end();        
        LoadSettings();
    }

    // void SetSec(int value){
    //     SetTime(value, rtc_.getMinute(), rtc_.getHour(true), rtc_.getDay(), rtc_.getMonth() + 1, rtc_.getYear());
    // }

    const int GetSec() { return static_cast<int>(rtc_.getSecond()); }

    // void SetMin(int value){ 
    //     SetTime(rtc_.getSecond(), value, rtc_.getHour(true), rtc_.getDay(), rtc_.getMonth() + 1, rtc_.getYear());
    // }

    const int GetMin() { return static_cast<int>(rtc_.getMinute()); }

    // void SetHour(int value){ 
    //     SetTime(rtc_.getSecond(), rtc_.getMinute(), value, rtc_.getDay(), rtc_.getMonth() + 1, rtc_.getYear());
    // }

    const int GetHour() { return static_cast<int>(rtc_.getHour(true)); }

    const int GetDay() { return static_cast<int>(rtc_.getDay()); }

    const int GetMonth() { return static_cast<int>(rtc_.getMonth() + 1); }

    const int GetYear() { return static_cast<int>(rtc_.getYear()); }


    const bool GetTwentyFour() const { return twentyFourHour_; }
    void SetTwentyFour(bool value){ twentyFourHour_ = value; }

    const int GetTurnOffSecs() const { return turnOffSecs_; }
    void SetTurnOffSecs(int value){ turnOffSecs_ = value; }

    const bool GetDarkMode() const { return darkMode_; }
    void SetDarkMode(bool value){ darkMode_ = value; }

private:

Preferences preferences;
ESP32Time rtc_;

// default values:
static constexpr bool defaultTwentyFour = true;
static constexpr int defaultTurnOffSecs = 10;
static constexpr bool defaultDarkMode = false;

// addresses
static constexpr const char* settingsAddressNamespace = "settings";

static constexpr const char* twentyFourHourAddress = "twentyfour";
static constexpr const char* turnOffSecsAddress = "turnoffsecs";
static constexpr const char* darkModeAddress = "darkmode";

// values:
bool twentyFourHour_;
int turnOffSecs_;
int batteryPercentage_ = 100;
bool darkMode_;

};
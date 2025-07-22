#include "../headers/graphics.h"

bool tGraphicManager::BeginDisplay()
{
    return display_.begin(SSD1306_SWITCHCAPVCC, 0x3c);
}

void tGraphicManager::ClearDisplay()
{
    display_.clearDisplay();
}

void tGraphicManager::WriteToScreen(const std::string &str, int x, int y, int ts)
{
    display_.setTextColor(WHITE);
    display_.setTextSize(ts);
    display_.setCursor(x, y);

    display_.print(str.c_str());
}

void tGraphicManager::Display()
{
    display_.display();
}

void tGraphicManager::PrintToScreen(const std::string &str)
{
    ClearDisplay();
    WriteToScreen(str);
    Display();
}

void tGraphicManager::PrintAmPmAndDateToScreen(const std::string &ampmStr, const std::string &dateStr, const std::string &batteryString){
    ClearDisplay();    
    std::string str = "";
    str.append(dateStr);
    std::string whiteSpace = "       ";
    str.append(whiteSpace);
    str.append(batteryString);
    str.append(ampmStr);
    WriteToScreen(str, 0, 0, 1);
}

void tGraphicManager::PrintClockToScreen(const std::string &str){
    WriteToScreen(str, 16, 24, 2);
    Display();
}
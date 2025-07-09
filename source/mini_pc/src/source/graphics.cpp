#include "../headers/graphics.h"

bool tGraphicManager::BeginDisplay()
{
    return display_.begin(SSD1306_SWITCHCAPVCC, 0x3c);
}

void tGraphicManager::ClearDisplay()
{
    display_.clearDisplay();
}

void tGraphicManager::WriteToScreen(const std::string &str, uint8_t x, uint8_t y, uint8_t ts)
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

void tGraphicManager::PrintClockToScreen(const std::string &str){
    ClearDisplay();    
    WriteToScreen(str, 16, 24, 2);
    Display();
}
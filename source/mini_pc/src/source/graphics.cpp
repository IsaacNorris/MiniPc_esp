#include "../headers/graphics.h"

bool tGraphicManager::BeginDisplay()
{
    return display_.begin(SSD1306_SWITCHCAPVCC, 0x3c);
}

void tGraphicManager::ClearDisplay()
{
    display_.clearDisplay();
}

void tGraphicManager::WriteToScreen(const std::string &str)
{
    display_.setTextColor(WHITE);
    display_.setTextSize(1);
    display_.setCursor(0, 0);

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

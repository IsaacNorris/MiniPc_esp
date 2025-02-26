#include "../headers/graphics.h"

bool tGraphics::BeginDisplay(){
    return display_->begin(SSD1306_SWITCHCAPVCC, 0x78);
}

void tGraphics::ClearDisplay(){
    display_->clearDisplay();
}

void tGraphics::WriteToScreen(const String& str){
    display_->setTextColor(WHITE);
    display_->setTextSize(1);
    display_->setCursor(0, 0);

    display_->print(str);
}

void tGraphics::Display(){
    display_->display();
}

void tGraphics::PrintToScreen(const String& str){
    display_->fillRect(0, 0, 128, 64, BLACK);
    WriteToScreen(str);
    Display();
}

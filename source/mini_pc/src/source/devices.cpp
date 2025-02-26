#include "../headers/devices.h"

void tDeviceManager::Loop()
{
    upButton_.CheckInput();
    downButton_.CheckInput();
    enterButton_.CheckInput();
}
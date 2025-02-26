#include "../headers/comms.h"

void tNetworkManager::Loop()
{
}

void tBluetoothManager::Loop()
{
}

void tCommsManager::Loop()
{
    networkManager_.Loop();
    bluetoothManager_.Loop();
}
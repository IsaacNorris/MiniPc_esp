#pragma once

class tNetworkManager
{
public:
    tNetworkManager()
    {
    }
    ~tNetworkManager()
    {
    }

    void Loop();

private:
};

class tBluetoothManager
{
public:
    tBluetoothManager()
    {
    }
    ~tBluetoothManager()
    {
    }

    void Loop();

private:
};

class tCommsManager
{
public:
    tCommsManager()
    {
    }
    ~tCommsManager()
    {
    }

    void Loop();

private:
    tNetworkManager networkManager_;
    tBluetoothManager bluetoothManager_;
};
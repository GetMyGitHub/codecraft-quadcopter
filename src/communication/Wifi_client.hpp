#include <Arduino.h>

#ifndef Wifi_client_H
#define Wifi_client_H

class Wifi_client
{
protected:

public:
    Wifi_client();
    virtual ~Wifi_client() {};
    virtual boolean connect();
    virtual boolean isConnected();
};

#endif
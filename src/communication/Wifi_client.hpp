#ifndef WIFI_CLIENT_HPP
#define WIFI_CLIENT_HPP

#include <Arduino.h>


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
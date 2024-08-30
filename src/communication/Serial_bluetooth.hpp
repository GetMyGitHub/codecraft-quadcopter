#ifndef SERIAL_BLUETOOTH_HPP
#define SERIAL_BLUETOOTH_HPP

#include <Arduino.h>
#include <string>

using namespace std;

class FlyController; // Déclaration anticipée de FlyController

class Serial_bluetooth
{

// FlyController* flyController;

protected:
public:
    Serial_bluetooth();
    // Serial_bluetooth(FlyController *flyController);
    virtual ~Serial_bluetooth() {};
    void setup();
    virtual void read();
    virtual String readString();
    virtual void write(char value);
    virtual void write(string value);    
    virtual int serialAvailable();
    virtual String updateSerial();
};

#endif

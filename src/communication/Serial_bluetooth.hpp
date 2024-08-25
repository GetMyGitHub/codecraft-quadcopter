#include <Arduino.h>
#include <string>

class Serial_bluetooth
{
protected:
    virtual void initialize();

public:
    Serial_bluetooth();
    virtual ~Serial_bluetooth() {};
    virtual void read();
    virtual void write(int value);
    virtual int serialAvailable();
    virtual void updateSerial();
};

#ifndef FLYCONTROLLER_HPP
#define FLYCONTROLLER_HPP

#include <Arduino.h>
#include <string>
#include <control/ESC/ESC_Controller.hpp>

using namespace std;

class FlyController
{
    ESC_Controller* escController;
protected:    
    void initialize();
public:
    FlyController();
    virtual ~FlyController(){};
    void setup();
    void loop();
    void serialPrint(string value, boolean debug = false);
    void serialPrintln(string value, boolean debug = false);
};

#endif // FLYCONTROLLER_H
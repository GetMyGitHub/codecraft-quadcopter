#ifndef FLYCONTROLLER_HPP
#define FLYCONTROLLER_HPP

#include <Arduino.h>
#include <string>
#include <control/ESC/ESC_Controller.hpp>
#include <communication/Serial_bluetooth.hpp>
#include <communication/Interpretor.hpp>

using namespace std;

class FlyController
{
    ESC_Controller escController;
    Serial_bluetooth serialBluetooth;
    Interpretor interpretor;

protected:    
    void initialize();
public:
    FlyController();
    virtual ~FlyController();
    void setup();
    void loop();
    void serialPrint(string value, boolean debug = false);
    void serialPrintln(string value, boolean debug = false);
    ESC_Controller getEscController();
    void readRotorCommand(vector<string> command);
};

#endif // FLYCONTROLLER_H
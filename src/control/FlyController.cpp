#include <Arduino.h>
#include <control/FlyController.hpp>
#include <configs/Configs.hpp>
#include <string>
#include <tools/TextTools.hpp>

using namespace std;

FlyController::FlyController() : escController(this), serialBluetooth(this), interpretor(this)
{
}

FlyController::~FlyController()
{
}

void FlyController::setup()
{
    delay(1000); // For start
    Serial.begin(CODECRAFT_SERIAL_BAUDRATE);
    FlyController::serialPrintln("FlyController : setup", true);
    escController.setup();    
    serialBluetooth.setup();    
    delay(1000);
    // escController.setPulseAll(1100);
}

void FlyController::loop(){
    if(Serial.available()){      

        String ret = Serial.readString();
        TextTools::removeSpacesAndNewlines(ret);
        serialBluetooth.write((ret + "\n").c_str());
        interpretor.serialCommand(ret, this);        
    }
    if(serialBluetooth.serialAvailable()){
        String ret = serialBluetooth.readString();
        TextTools::removeSpacesAndNewlines(ret);
        interpretor.serialCommand(ret, this);
    }
}

void FlyController::serialPrint(string value, boolean debug)
{
    if (!debug || (debug && CODECRAFT_LOG_DEBUG))
    {
        Serial.print(value.c_str());
        serialBluetooth.write(value.c_str());
    }
}

void FlyController::serialPrintln(string value, boolean debug)
{
    if (!debug || (debug && CODECRAFT_LOG_DEBUG))
    {
        Serial.println(value.c_str());
        serialBluetooth.write((value + "\n").c_str());
    }
}

ESC_Controller FlyController::getEscController(){
    return escController;
}

void FlyController::readRotorCommand(vector<string> command){
    TextTools::removeElementFromVector(command, "R");
    if(command[0] == "ALL") escController.setPulseAll(stoi(command[1]));
}
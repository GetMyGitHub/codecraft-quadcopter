#include <Arduino.h>
#include <control/FlyController.hpp>
#include <configs/Configs.hpp>
#include <string>

using namespace std;

FlyController::FlyController() : escController(new ESC_Controller(this))
{
    if (CODECRAFT_LOG_DEBUG)
        Serial.println("FlyController : constructor");
}

FlyController::~FlyController()
{
    delete escController;
}

void FlyController::setup()
{
    delay(2000); // For start
    Serial.begin(CODECRAFT_SERIAL_BAUDRATE);
    FlyController::serialPrintln("Quadcopter main program : setup");
    FlyController::initialize();
}

void FlyController::initialize()
{
    FlyController::serialPrintln("Quadcopter main program : initialize");
    escController = new ESC_Controller(this);
}

void FlyController::loop(){

}

void FlyController::serialPrint(string value, boolean debug)
{
    if (!debug || (debug && CODECRAFT_LOG_DEBUG))
    {
        Serial.print(value.c_str());
    }
}

void FlyController::serialPrintln(string value, boolean debug)
{
    if (!debug || (debug && CODECRAFT_LOG_DEBUG))
    {
        Serial.println(value.c_str());
    }
}
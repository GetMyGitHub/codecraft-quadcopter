#include <Arduino.h>

#include <communication/Serial_bluetooth.hpp>
#include <configs/Configs.hpp>

#include "BluetoothSerial.h"
#include <string>
#include "Serial_bluetooth.hpp"
#include <control/FlyController.hpp>
#include <tools/TextTools.hpp>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

using namespace std;

Serial_bluetooth::Serial_bluetooth()
{
}

Serial_bluetooth::Serial_bluetooth(FlyController *pFlycontroller)
{
  flyController = pFlycontroller;
}

void Serial_bluetooth::setup()
{
  flyController->serialPrintln("Serial_bluetooth : setup", true);
  SerialBT.begin(CODECRAFT_BLUETOOTH_DEVICE_NAME.c_str());
}

void Serial_bluetooth::read()
{
  if (SerialBT.available())
  {
    Serial.write(SerialBT.read());
  }
}

String Serial_bluetooth::readString()
{  
    return SerialBT.readString();
}

void Serial_bluetooth::write(char value)
{
  if (value != 0)
  {
    SerialBT.write(Serial.read());
  }
}

void Serial_bluetooth::write(string value)
{
  for (int i = 0; i < value.length(); i++)
  {
    SerialBT.write(value[i]);
  }
}

int Serial_bluetooth::serialAvailable()
{
  return SerialBT.available();
}

String Serial_bluetooth::updateSerial()
{
  String ret = "";
  if (SerialBT.available())
  {
    ret =  SerialBT.readString();
    TextTools::removeSpacesAndNewlines(ret);
  }

  // string ret;
  // while (Serial.available())
  // {
  //   ret += Serial.read();
  // }
  // Serial.print("Test : ");
  // Serial.println(TextTools::removeSpacesAndNewlines(ret).c_str());

  // if (Serial.available()) {

  //   int test = Serial.read();
  //   if(test != -1){
  //     ret = char (test);
  //   }
  //   // ret = Serial.readString().c_str();
  //   // FlyController::serialPrintln(test,true);
  //   SerialBT.write(test);
  // }
  // if (SerialBT.available()) {
  //   Serial.write(SerialBT.read());
  // }
  return ret;
}
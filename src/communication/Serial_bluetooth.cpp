#include <Arduino.h>

#include <communication/Serial_bluetooth.hpp>

#include "BluetoothSerial.h"
#include <string>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

Serial_bluetooth::Serial_bluetooth()
{
    Serial.println("Serial_bluetooth : constructor");
    Serial_bluetooth::initialize();
}

void Serial_bluetooth::initialize()
{
    Serial.println("Serial_bluetooth : initialize");
    SerialBT.begin("Codecraft_Quedcoptere");
    Serial.println("Serial_bluetooth : set 'Codecraft_Quedcoptere' for device name");
}

void Serial_bluetooth::read(){
    if (SerialBT.available())
    {
       Serial.write(SerialBT.read());
    } 
}

void Serial_bluetooth::write(int value)
{
    if(value != 0){
        SerialBT.write(Serial.read());
    }
}

int Serial_bluetooth::serialAvailable(){
    return SerialBT.available();
}

void Serial_bluetooth::updateSerial(){
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
}
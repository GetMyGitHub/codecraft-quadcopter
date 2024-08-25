#include <Arduino.h>

#include <configs/Configs.hpp>
#include <communication/Wifi_client.hpp>
#include <communication/Serial_bluetooth.hpp>

// Configs configs;
// Wifi_client* wifiClient;

// Serial_bluetooth SerialBluetooth;

// Serial_bluetooth serialBluetooth;

Serial_bluetooth* serialBluetooth;
uint16_t GLOBAL_MIN_DELAY_MS = 10;


void initialize(){
  Serial.println("Quadcopter main program : initialize");
  // Wifi_client wifiClient;
  // if(wifiClient.connect()) {
    
  // };   
  serialBluetooth = new Serial_bluetooth();

}


void setup() {
  delay(2000); // For start
  Serial.begin(115200);
  Serial.println("Quadcopter main program : setup");
  initialize();
}

void loop() {
  serialBluetooth->updateSerial();
  delay(GLOBAL_MIN_DELAY_MS);
}



// HELPS : 
// Serial.println(CODECRAFT_WIFI_SSID.c_str());


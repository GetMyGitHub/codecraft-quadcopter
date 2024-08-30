#include <Arduino.h>

// #include <configs/Configs.hpp>
// #include <communication/Wifi_client.hpp>
// #include <communication/Serial_bluetooth.hpp>
// #include <communication/Interpretor.hpp>
// #include <control/ESC/ESC_Controller.hpp>
#include <control/FlyController.hpp>

// Configs configs;
// Wifi_client* wifiClient;

// Serial_bluetooth serialBluetooth;
// ESC_Controller escController;
// Interpretor* interpretor;
FlyController flyController;

uint16_t GLOBAL_MIN_DELAY_MS = 10;

using namespace std;

void initialize(){
  // delay(2000); // For start
  // Wifi_client wifiClient;
  // if(wifiClient.connect()) {
    
  // };   
  // serialBluetooth = new Serial_bluetooth();
  // // escController = new ESC_Controller();
  // interpretor = new Interpretor();
  // flyController = new FlyController();

}


void setup() {
  flyController.setup();
  // flyController->setup();
  // delay(2000); // For start
  // Serial.begin(115200);
  // Serial.println("Quadcopter main program : setup");
  // initialize();
}

void loop() {
  flyController.loop();
  // flyController->loop();

  // if (Serial.available()) {    
  //   // interpretor->serialCommand(Serial.readString().c_str());
  // }

  // serialBluetooth->updateSerial();
  delay(GLOBAL_MIN_DELAY_MS);
}



// HELPS : 
// Serial.println(CODECRAFT_WIFI_SSID.c_str());


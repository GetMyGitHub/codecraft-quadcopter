#include <Arduino.h>
#include <configs/Configs.hpp>
#include <string>

// WIFI
extern const std::string CODECRAFT_WIFI_SSID = "Test";
extern const std::string CODECRAFT_WIFI_PASSWORD = "test1234";
// ESC PINS
extern const int CODECRAFT_ESC_MIN_PULSE = 1000;
extern const int CODECRAFT_ESC_MAX_PULSE = 2000;
extern const int CODECRAFT_ESC_PIN_FRONT_LEFT = 32;
extern const int CODECRAFT_ESC_PIN_FRONT_RIGHT = 33;
extern const int CODECRAFT_ESC_PIN_BACK_LEFT = 25;
extern const int CODECRAFT_ESC_PIN_BACK_RIGHT = 26;
// COMMUNICATION
extern const std::string CODECRAFT_COMMAND_DELIMITER = "_";
// DEBUG
extern const boolean CODECRAFT_LOG_DEBUG = true;

extern const int CODECRAFT_SERIAL_BAUDRATE = 115200;
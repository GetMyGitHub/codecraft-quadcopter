#include <Arduino.h>
#include <ESP32Servo.h>

#include <control/ESC/ESC_Controller.hpp>
#include <configs/Configs.hpp>


ESC_Controller::ESC_Controller(){
    Serial.println("ESC_Controller : constructor");
    ESC_Controller::attachMotors();
    delay(1000); // Wait attaching motors.
    ESC_Controller::initiateMotors();
}

void ESC_Controller::attachMotors(){
    Serial.println("ESC_Controller : attachMotors");
    esc_front_left.attach(CODECRAFT_ESC_PIN_FRONT_LEFT, CODECRAFT_ESC_MIN_PULSE, CODECRAFT_ESC_MAX_PULSE);
    esc_front_right.attach(CODECRAFT_ESC_PIN_FRONT_RIGHT, CODECRAFT_ESC_MIN_PULSE, CODECRAFT_ESC_MAX_PULSE);
    esc_back_left.attach(CODECRAFT_ESC_PIN_BACK_LEFT, CODECRAFT_ESC_MIN_PULSE, CODECRAFT_ESC_MAX_PULSE);
    esc_back_right.attach(CODECRAFT_ESC_PIN_BACK_RIGHT, CODECRAFT_ESC_MIN_PULSE, CODECRAFT_ESC_MAX_PULSE);
}

void ESC_Controller::initiateMotors(){
    Serial.println("ESC_Controller : initiateMotors");
    esc_front_left.write(0);
    esc_front_right.write(0);
    esc_back_left.write(0);
    esc_back_right.write(0);
}
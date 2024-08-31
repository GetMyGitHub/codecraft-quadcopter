#include <Arduino.h>
#include <ESP32Servo.h>

#include <control/ESC/ESC_Controller.hpp>
#include <configs/Configs.hpp>
#include <control/FlyController.hpp>

#include <vector>
#include <tools/TextTools.hpp>

using namespace std;

ESC_Controller::ESC_Controller(){
}

ESC_Controller::ESC_Controller(FlyController *pFlycontroller){
    flyController = pFlycontroller;
}


void ESC_Controller::setup(){
    flyController->serialPrintln("ESC_Controller : setup", true);
    ESC_Controller::attachMotors();
    delay(1000); // Wait attaching motors.
    ESC_Controller::initiateMotors();
    delay(1000); // Wait initiating motors.
}

void ESC_Controller::attachMotors(){
    flyController->serialPrintln("ESC_Controller : attachMotors", true);
    esc_front_left.attach(CODECRAFT_ESC_PIN_FRONT_LEFT, CODECRAFT_ESC_MIN_PULSE, CODECRAFT_ESC_MAX_PULSE);
    esc_front_right.attach(CODECRAFT_ESC_PIN_FRONT_RIGHT, CODECRAFT_ESC_MIN_PULSE, CODECRAFT_ESC_MAX_PULSE);
    esc_back_left.attach(CODECRAFT_ESC_PIN_BACK_LEFT, CODECRAFT_ESC_MIN_PULSE, CODECRAFT_ESC_MAX_PULSE);
    esc_back_right.attach(CODECRAFT_ESC_PIN_BACK_RIGHT, CODECRAFT_ESC_MIN_PULSE, CODECRAFT_ESC_MAX_PULSE);
}

void ESC_Controller::initiateMotors(){
    flyController->serialPrintln("ESC_Controller : initiateMotors", true);
    esc_front_left.write(0);
    esc_front_left_actual_pulse = 0;
    esc_front_right.write(0);
    esc_front_right_actual_pulse = 0;
    esc_back_left.write(0);
    esc_back_left_actual_pulse = 0;
    esc_back_right.write(0);
    esc_back_right_actual_pulse = 0;
}

void ESC_Controller::setFrontLeftPulse(int pulseValue){
    esc_front_left_actual_pulse = pulseValue;
    esc_front_left.write(pulseValue);
}

void ESC_Controller::setFrontRightPulse(int pulseValue){
    esc_front_right_actual_pulse = pulseValue;
    esc_front_right.write(pulseValue);
}

void ESC_Controller::setBackLeftPulse(int pulseValue){
    esc_back_left_actual_pulse = pulseValue;
    esc_back_left.write(pulseValue);
}

void ESC_Controller::setBackRightPulse(int pulseValue){
    esc_back_right_actual_pulse = pulseValue;
    esc_back_right.write(pulseValue);
}

void ESC_Controller::setPulseAll(int pulseValue){
    ESC_Controller::setFrontLeftPulse(pulseValue);
    ESC_Controller::setFrontRightPulse(pulseValue);
    ESC_Controller::setBackLeftPulse(pulseValue);
    ESC_Controller::setBackRightPulse(pulseValue);
}

void ESC_Controller::readCommandR(vector<string> command){
    TextTools::removeElementFromVector(command, "R");
    if(command[0] == "ALL") ESC_Controller::setPulseAll(stoi(command[1]));
    if(command[0] == "FL") ESC_Controller::setFrontLeftPulse(stoi(command[1]));
    if(command[0] == "FR") ESC_Controller::setFrontRightPulse(stoi(command[1]));
    if(command[0] == "BL") ESC_Controller::setBackLeftPulse(stoi(command[1]));
    if(command[0] == "BF") ESC_Controller::setBackRightPulse(stoi(command[1]));
}
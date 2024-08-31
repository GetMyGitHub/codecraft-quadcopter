#ifndef ESC_CONTROLLER_HPP
#define ESC_CONTROLLER_HPP

#include <ESP32Servo.h>
#include <vector>

using namespace std;

class FlyController; // Déclaration anticipée de FlyController

class ESC_Controller
{
    int minPulse;
    int maxPulse;

    int esc_front_left_actual_pulse;
    int esc_front_right_actual_pulse;
    int esc_back_left_actual_pulse;
    int esc_back_right_actual_pulse;

    Servo esc_front_left;
    Servo esc_front_right;
    Servo esc_back_left;
    Servo esc_back_right;

    FlyController *flyController;

protected:
    void attachMotors();
    void initiateMotors();
public:
    ESC_Controller();
    ESC_Controller(FlyController *flyController);
    virtual ~ESC_Controller() {};
    void setup();
    int getFrontLeftPulse(int pulseValue);
    int getFrontRightPulse(int pulseValue);
    int getBackLeftPulse(int pulseValue);
    int getBackRightPulse(int pulseValue);

    void setFrontLeftPulse(int pulseValue);
    void setFrontRightPulse(int pulseValue);
    void setBackLeftPulse(int pulseValue);
    void setBackRightPulse(int pulseValue);

    void setPulseAll(int pulseValue);

    void readCommandR(vector<string> vector);

};

#endif

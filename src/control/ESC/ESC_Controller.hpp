#include <ESP32Servo.h>

class ESC_Controller
{
    int minPulse;
    int maxPulse;

    Servo esc_front_left;
    Servo esc_front_right;
    Servo esc_back_left;
    Servo esc_back_right;

protected:
    void attachMotors();
    void initiateMotors();
public:
    ESC_Controller();
    virtual ~ESC_Controller() {};
};

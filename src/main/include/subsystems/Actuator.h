#pragma once


#include <frc/PWM.h>

class Actuator
{
public:
    void SetSpeed(double);
    
private:
    frc::PWM controller{0};
};
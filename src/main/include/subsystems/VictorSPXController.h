#include <ctre/phoenix/motorcontrol/can/victorspx.h>

using namespace ctre::phoenix;

class VictorSPXController
{
public:
    VictorSPXController(int id) : motor(id) {};

    void SetMotorPower(double power);

    motorcontrol::can::VictorSPX *GetMotor() { return &motor; }
    
private:
    motorcontrol::can::VictorSPX motor;
};
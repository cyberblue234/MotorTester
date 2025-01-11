#include <ctre/phoenix/motorcontrol/can/victorspx.h>
#include <frc/smartdashboard/SmartDashboard.h>

class VictorSPXController
{
public:
    void SetMotorPower(double power);
    
private:
    int canID = 1;

    ctre::phoenix::motorcontrol::can::VictorSPX victorMotor{canID};
    
};
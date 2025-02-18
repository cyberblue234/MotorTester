#include "subsystems/VictorSPXController.h"

void VictorSPXController::SetMotorPower(double power) 
{
    motor.Set(motorcontrol::ControlMode::PercentOutput, power);
}
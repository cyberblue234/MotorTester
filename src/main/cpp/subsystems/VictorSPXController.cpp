#include "subsystems/VictorSPXController.h"

void VictorSPXController::SetMotorPower(double power) 
{
    victorMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, power);
}
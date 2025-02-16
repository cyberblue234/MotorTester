#include "subsystems/TalonFXController.h"

void TalonFXController::SetMotorPower(double power) 
{
    motor.Set(power);
}

double TalonFXController::GetEncoderCount()
{
    return motor.GetPosition().GetValue().value();
}
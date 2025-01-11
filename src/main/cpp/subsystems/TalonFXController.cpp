#include "subsystems/TalonFXController.h"

void TalonFXController::SetMotorPower(double power) 
{
    talonFX1Motor.Set(power);
    frc::SmartDashboard::PutNumber("power", power);
    frc::SmartDashboard::PutNumber("encoder", GetEncoderCount());
}

double TalonFXController::GetEncoderCount()
{
    return talonFX1Motor.GetPosition().GetValue().value();
}
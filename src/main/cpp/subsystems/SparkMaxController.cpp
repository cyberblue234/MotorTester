#include "subsystems/SparkMaxController.h"

void SparkMaxController::SetMotorPower(double power) 
{
    sparkMaxMotor.Set(power);
    frc::SmartDashboard::PutNumber("power", power);
    frc::SmartDashboard::PutNumber("encoder", GetEncoderCount());
}

double SparkMaxController::GetEncoderCount()
{
    return sparkMaxEncoder.GetPosition();
}
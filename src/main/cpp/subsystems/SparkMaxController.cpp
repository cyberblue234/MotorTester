#include "subsystems/SparkMaxController.h"

void SparkMaxController::SetMotorPower(double power) 
{
    motor.Set(power);
}

double SparkMaxController::GetEncoderCount()
{
    return motor.GetEncoder().GetPosition();
}
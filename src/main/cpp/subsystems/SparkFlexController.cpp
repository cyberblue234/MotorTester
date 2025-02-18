#include "subsystems/SparkFlexController.h"

void SparkFlexController::SetMotorPower(double power) 
{
    motor.Set(power);
}

double SparkFlexController::GetEncoderCount()
{
    return motor.GetEncoder().GetPosition();
}
#include "subsystems/SparkFlexController.h"

void SparkFlexController::SetMotorPower(double power) 
{
    sparkFlexMotor.Set(power);
}

double SparkFlexController::GetEncoderCount()
{
    return sparkFlexEncoder.GetPosition();
}
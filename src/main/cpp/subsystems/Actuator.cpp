#include "subsystems/Actuator.h"

void Actuator::SetSpeed(double power)
{
    controller.SetSpeed(power);
}
#include "subsystems/CANrange.h"

double CANrangeController::GetDistance()
{
    return range.GetDistance().GetValueAsDouble();
}
#include "rev/SparkMax.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <units/voltage.h>

class SparkMaxController
{
public:
    void SetMotorPower(double power);
    double GetEncoderCount();
    
private:
    int canID = 7;
    rev::spark::SparkMax sparkMaxMotor{canID, rev::spark::SparkMax::MotorType::kBrushless};
    rev::spark::SparkRelativeEncoder sparkMaxEncoder = sparkMaxMotor.GetEncoder();
};
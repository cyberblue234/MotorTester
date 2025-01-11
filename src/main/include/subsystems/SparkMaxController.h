#include "rev/CANSparkMax.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <units/voltage.h>

class SparkMaxController
{
public:
    SparkMaxController() {sparkMaxMotor.RestoreFactoryDefaults();};
    void SetMotorPower(double power);
    double GetEncoderCount();
    
private:
    int canID = 7;
    rev::CANSparkMax sparkMaxMotor{canID, rev::CANSparkMax::MotorType::kBrushless};
    rev::SparkRelativeEncoder sparkMaxEncoder = sparkMaxMotor.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);
};
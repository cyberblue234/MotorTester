#include "rev/SparkFlex.h"
#include <frc/smartdashboard/SmartDashboard.h>

class SparkFlexController
{
public:
    void SetMotorPower(double power);
    double GetEncoderCount();
    
private:
    int canID = frc::SmartDashboard::GetNumber("Flex id", 0);
    rev::spark::SparkFlex sparkFlexMotor{canID, rev::spark::SparkFlex::MotorType::kBrushless};
    rev::spark::SparkRelativeEncoder sparkFlexEncoder = sparkFlexMotor.GetEncoder();
};
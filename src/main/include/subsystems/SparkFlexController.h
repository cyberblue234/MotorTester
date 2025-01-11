#include "rev/SparkFlex.h"

class SparkFlexController
{
public:
    void SetMotorPower(double power);
    double GetEncoderCount();
    
private:
    int canID = 2;
    rev::spark::SparkFlex sparkFlexMotor{canID, rev::spark::SparkFlex::MotorType::kBrushless};
    rev::spark::SparkRelativeEncoder sparkFlexEncoder = sparkFlexMotor.GetEncoder();
};
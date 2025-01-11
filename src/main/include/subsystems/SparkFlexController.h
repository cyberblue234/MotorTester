#include "rev/CANSparkFlex.h"

class SparkFlexController
{
public:
    void SetMotorPower(double power);
    double GetEncoderCount();
    
private:
    int canID = 2;
    rev::CANSparkFlex sparkFlexMotor{canID, rev::CANSparkFlex::MotorType::kBrushless};
    rev::SparkRelativeEncoder sparkFlexEncoder = sparkFlexMotor.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);
};
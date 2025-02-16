#include "rev/SparkFlex.h"

using namespace rev::spark;

class SparkFlexController
{
public:
    SparkFlexController(int id) : motor(id, rev::spark::SparkFlex::MotorType::kBrushless) {}

    void SetMotorPower(double power);
    double GetEncoderCount();

    SparkFlex *GetMotor() { return &motor; }
    
private:
    SparkFlex motor;
};
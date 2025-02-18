#include "rev/SparkMax.h"

using namespace rev::spark;

class SparkMaxController
{
public:
    SparkMaxController(int id) : motor(id, SparkMax::MotorType::kBrushless) {}

    void SetMotorPower(double power);
    double GetEncoderCount();

    SparkMax *GetMotor() { return &motor; }
    
private:
    SparkMax motor;
};
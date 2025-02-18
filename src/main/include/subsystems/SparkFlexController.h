#include "rev/SparkFlex.h"
#include "rev/config/SparkFlexConfig.h"

using namespace rev::spark;

class SparkFlexController
{
public:
    SparkFlexController(int id) : motor(id, rev::spark::SparkFlex::MotorType::kBrushless) 
    {
        SparkFlexConfig config{};
        config.SetIdleMode(SparkBaseConfig::kBrake);
        motor.Configure(config, SparkBase::ResetMode::kResetSafeParameters, SparkBase::PersistMode::kNoPersistParameters);
    }

    void SetMotorPower(double power);
    double GetEncoderCount();

    SparkFlex *GetMotor() { return &motor; }
    
private:
    SparkFlex motor;
};
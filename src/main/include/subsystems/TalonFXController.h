#include <ctre/phoenix6/TalonFX.hpp>

using namespace ctre::phoenix6;

class TalonFXController
{
public:
    TalonFXController(int id) : motor(id, "rio") {};
    void SetMotorPower(double power);
    double GetEncoderCount();

    hardware::TalonFX *GetMotor() { return &motor; }
    
private:
    hardware::TalonFX motor;

};
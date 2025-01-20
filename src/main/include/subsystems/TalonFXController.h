#include <ctre/phoenix6/TalonFX.hpp>
#include <frc/smartdashboard/SmartDashboard.h>

class TalonFXController
{
public:
    void SetMotorPower(double power);
    double GetEncoderCount();
    
private:
    int canID = frc::SmartDashboard::GetNumber("Talon id", 0);
    ctre::phoenix6::hardware::TalonFX talonFX1Motor{canID, "rio"};

};
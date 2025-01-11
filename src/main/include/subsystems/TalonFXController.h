#include <ctre/phoenix6/TalonFX.hpp>

class TalonFXController
{
public:
    void SetMotorPower(double power){};
    double GetEncoderCount(){};
    
private:
    int canID = 7;

    ctre::phoenix6::hardware::TalonFX talonFX1Motor{canID, "rio"};
};
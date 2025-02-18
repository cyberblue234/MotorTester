#include <ctre/phoenix6/CANrange.hpp>

using namespace ctre::phoenix6;

class CANrangeController
{
public:
    CANrangeController(int id) : range(id, "rio") {};
    double GetDistance();
    bool IsDetected() { return range.GetIsDetected().GetValue(); }

    hardware::CANrange *GetRange() { return &range; }
    
private:
    hardware::CANrange range;

};
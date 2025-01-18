// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() 
{
  static double power;
  bool direction1 = gamepad.GetYButton();
  bool direction2 = gamepad.GetAButton();
  
  power = frc::SmartDashboard::GetNumber("Power", 0.0);
  frc::SmartDashboard::PutNumber("Power", power);
  
  if(direction1)
  {
    power = -power;
  }
  else if(direction2)
  {
    power = power;
  }
  else
  {
    power = 0.0;
  }
  frc::SmartDashboard::PutNumber("ShowPower", power);
  sparkFlexController.SetMotorPower(power);
  sparkMaxController.SetMotorPower (power);
  talonFXController.SetMotorPower  (power);
  victorSPXController.SetMotorPower(power);
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

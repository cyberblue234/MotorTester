#include "Robot.h"

#include <fmt/core.h>
#include <frc/shuffleboard/Shuffleboard.h>

void Robot::RobotInit() 
{
	frc::SmartDashboard::PutString("To select SparkMax Controller", "d-pad up");
	frc::SmartDashboard::PutString("To select SparkFlex Controller", "d-pad right");
	frc::SmartDashboard::PutString("To select TalonFX Controller", "d-pad down");
	frc::SmartDashboard::PutString("To select VictorSPX Controller", "d-pad left");
	frc::SmartDashboard::PutString("To select CANrange Controller", "x");
	frc::SmartDashboard::PutString("To create motor controller", "left bumper");
	frc::SmartDashboard::PutString("To close motor controller", "right bumper");
	frc::SmartDashboard::PutNumber("ID", 0);
	frc::SmartDashboard::PutNumber("Power", 0.0);
}

void Robot::RobotPeriodic() 
{
	frc::SmartDashboard::PutBoolean("SparkMax Controller?", sparkMaxController.has_value());
	frc::SmartDashboard::PutBoolean("SparkFlex Controller?", sparkFlexController.has_value());
	if (sparkFlexController.has_value()) frc::SmartDashboard::PutNumber("SparkFlexID", sparkFlexController.value().GetMotor()->GetDeviceId());
	else frc::SmartDashboard::PutNumber("SparkFlexID", -1);
	frc::SmartDashboard::PutBoolean("TalonFX Controller?", talonFXController.has_value());
	if (talonFXController.has_value()) frc::SmartDashboard::PutNumber("TalonFXID", talonFXController.value().GetMotor()->GetDeviceID());
	else frc::SmartDashboard::PutNumber("TalonFXID", -1);
	frc::SmartDashboard::PutBoolean("VictorSPX Controller?", victorSPXController.has_value());
	frc::SmartDashboard::PutBoolean("CANrange Controller?", canRangeController.has_value());
	if (canRangeController.has_value())
	{
		frc::SmartDashboard::PutNumber("CANrange Distance", canRangeController.value().GetDistance());
	}
	else 
	{
		frc::SmartDashboard::PutNumber("CANrange Distance", -1);
	}
}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() 
{
	double power;
	bool direction1 = gamepad.GetYButton();
	bool direction2 = gamepad.GetAButton();
	
	power = frc::SmartDashboard::GetNumber("Power", 0.0);
	
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

	if (sparkMaxController.has_value())
	{
		sparkMaxController.value().SetMotorPower(power);
	}
	if (sparkFlexController.has_value())
	{
		if (canRangeController)
		{
			if (canRangeController.value().IsDetected() && power < 0) sparkFlexController.value().SetMotorPower(0);
			else sparkFlexController.value().SetMotorPower(power);
		}
		else sparkFlexController.value().SetMotorPower(power);
	}
	if (talonFXController.has_value())
	{
		talonFXController.value().SetMotorPower(power);
	}
	if (victorSPXController.has_value())
	{
		victorSPXController.value().SetMotorPower(power);
	}
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() 
{
	int id = frc::SmartDashboard::GetNumber("ID", 0);

	if (gamepad.GetXButtonPressed())
	{
		if (gamepad.GetLeftBumperButton()) 
		{
			if (!canRangeController.has_value() || canRangeController.value().GetRange()->GetDeviceID() != id) canRangeController.emplace(id);
		}
		else if (gamepad.GetRightBumperButton()) canRangeController = std::nullopt;
		return;
	}
	switch(gamepad.GetPOV())
	{
		case 0:
			if (gamepad.GetLeftBumperButton()) 
			{
				if (!sparkMaxController.has_value()) sparkMaxController.emplace(sparkMaxID);
			}
			else if (gamepad.GetRightBumperButton()) sparkMaxController = std::nullopt;
			break;
		case 90:
			if (gamepad.GetLeftBumperButton()) 
			{
				if (!sparkFlexController.has_value() || sparkFlexController.value().GetMotor()->GetDeviceId() != id || id != sparkMaxID) sparkFlexController.emplace(id);
			}
			else if (gamepad.GetRightBumperButton()) sparkFlexController = std::nullopt;
			break;
		case 180:
			if (gamepad.GetLeftBumperButton()) 
			{
				if (!talonFXController.has_value() || talonFXController.value().GetMotor()->GetDeviceID() != id) talonFXController.emplace(id);
			}
			else if (gamepad.GetRightBumperButton()) talonFXController = std::nullopt;
			break;
		case 270:
			if (gamepad.GetLeftBumperButton()) 
			{
				if (!victorSPXController.has_value()) victorSPXController.emplace(victorSPXID);
			}
			else if (gamepad.GetRightBumperButton()) victorSPXController = std::nullopt;
			break;
		default:
			return;
	}
}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

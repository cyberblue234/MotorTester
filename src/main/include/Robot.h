#pragma once

#include <string>
#include <optional>

#include <frc/TimedRobot.h>

#include <frc/smartdashboard/SendableChooser.h>

#include "subsystems/SparkFlexController.h"
#include "subsystems/SparkMaxController.h"
#include "subsystems/TalonFXController.h"
#include "subsystems/VictorSPXController.h"

#include "frc/XboxController.h"

#include "frc/smartdashboard/SmartDashboard.h"

class Robot : public frc::TimedRobot
{
public:
	void RobotInit() override;
	void RobotPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void TestInit() override;
	void TestPeriodic() override;
	void SimulationInit() override;
	void SimulationPeriodic() override;

	enum MotorControllers
	{
		SparkMax, SparkFlex, TalonFX, VictorSPX
	};

private:
	std::optional<SparkMaxController> sparkMaxController;
	int sparkMaxID = 7;
	std::optional<SparkFlexController> sparkFlexController;
	std::optional<TalonFXController> talonFXController;
	std::optional<VictorSPXController> victorSPXController;
	int victorSPXID = 1;

	frc::XboxController gamepad{0};
};

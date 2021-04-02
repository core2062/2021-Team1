#pragma once

#include <string>
#include <iostream>
#include <frc/RobotBase.h>
#include <frc/TimedRobot.h>
#include <CORERobotLib.h>
#include <COREFramework/COREScheduler.h>

#include "Config.h"
#include "DriveSubsystem.h"
#include "LauncherSubsystem.h"
#include "ConveyorSubsystem.h"
#include "ClimberSubsystem.h"
#include "Config.h"
#include "auto/DriveRoutine.h"
#include "auto/ThreeShotAutonRoutine.h"

using namespace CORE;
using namespace std;

class Robot : public CORERobot {
public: 
 	Robot();
	void robotInit() override;
    void teleopInit() override;
    void teleop() override;
	void test() override;
	void testInit() override;
	static Robot * GetInstance();
	DriveSubsystem driveSubsystem;
	LauncherSubsystem launcherSubsystem;
	ConveyorSubsystem conveyorSubsystem;
	ClimberSubsystem climberSubsystem;
	DriveRoutine driveRoutine;
	ThreeShotRoutine threeShotRoutine;

private:
	static Robot * m_instance;
};

#pragma once

#include <frc/Compressor.h>
#include <frc/Solenoid.h>
#include <ctre/Phoenix.h>
#include <CORERobotLib.h>
#include "Config.h"

using namespace CORE;
using namespace frc;

//Define PLS
#define PNEUMATIC_LAUNCHER_SYSTEM_PCM 0
#define PNEUMATIC_LAUNCHER_SYSTEM_OPEN 10
#define PNEUMATIC_LAUNCHER_SYSTEM_CLOSED 11

class LauncherSubsystem : public CORESubsystem {
public:
	LauncherSubsystem();
	void robotInit() override;
	void teleopInit() override;
	void teleop() override;
	void teleopEnd() override;
	void auton();
	void initTalons();
    void launcherTriggered();

private:
	Solenoid m_launcherSolenoidOne,m_launcherSolenoidTwo;
	bool m_solenoidActivated;
};

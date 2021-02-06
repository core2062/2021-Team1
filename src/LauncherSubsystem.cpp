#include "LauncherSubsystem.h"

using namespace CORE;

LauncherSubsystem::LauncherSubsystem() : m_launcherSolenoid(PCM, PNEUMATIC_LAUNCHER_SYSTEM_OPEN, PNEUMATIC_LAUNCHER_SYSTEM_CLOSED)
                                        {}

void LauncherSubsystem::robotInit() {
    driverJoystick->RegisterButton(CORE::COREJoystick::B_BUTTON);
}

void LauncherSubsystem::teleopInit() {
    m_solenoidActivated = false;
}


void LauncherSubsystem::teleop() {
    if (driverJoystick->GetRisingEdge(CORE::COREJoystick::B_BUTTON) && !m_solenoidActivated) {
        launcherTriggered();
    }
}

void LauncherSubsystem::launcherTriggered() {
    if (m_solenoidActivated) {
        m_launcherSolenoid.Set(DoubleSolenoid::kForward);
        m_solenoidActivated = false;
    } else if (!m_solenoidActivated) {
        m_launcherSolenoid.Set(DoubleSolenoid::kReverse);
        m_solenoidActivated = true;
    }
}
void LauncherSubsystem::teleopEnd() {
	
}
#include "LauncherSubsystem.h"

using namespace CORE;

LauncherSubsystem::LauncherSubsystem() : m_launcherSolenoidOne(PCM, PNEUMATIC_LAUNCHER_SYSTEM_OPEN_1),
                                         m_launcherSolenoidTwo(PCM, PNEUMATIC_LAUNCHER_SYSTEM_OPEN_2)
                                        {}

void LauncherSubsystem::robotInit() {
    operatorJoystick->RegisterButton(CORE::COREJoystick::B_BUTTON);
}

void LauncherSubsystem::teleopInit() {
    m_solenoidActivated = false;
}


void LauncherSubsystem::teleop() {
    if (operatorJoystick->GetRisingEdge(CORE::COREJoystick::B_BUTTON)) {
        launcherTriggered();
    }
}

void LauncherSubsystem::launcherTriggered() {
    if (m_solenoidActivated) {
        m_launcherSolenoidOne.Set(m_solenoidActivated);
        m_launcherSolenoidTwo.Set(m_solenoidActivated);
        std::cout<<"fired";
        m_solenoidActivated = false;
    } else if (!m_solenoidActivated) {
        m_launcherSolenoidOne.Set(m_solenoidActivated);
        m_launcherSolenoidTwo.Set(m_solenoidActivated);
        std::cout<<"returned";
        m_solenoidActivated = true;
    }
}
void LauncherSubsystem::teleopEnd() {
	
}
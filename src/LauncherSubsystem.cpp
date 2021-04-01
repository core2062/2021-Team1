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
        launcherTriggered(m_solenoidActivated);
    }
}

void LauncherSubsystem::launcherTriggered(bool firing) {
    if (!firing) {
        m_launcherSolenoidOne.Set(!firing);
        m_launcherSolenoidTwo.Set(!firing);
        std::cout<<"fired";
        m_solenoidActivated = true;
    }else if (m_solenoidActivated) {
        m_launcherSolenoidOne.Set(!firing);
        m_launcherSolenoidTwo.Set(!firing);
        std::cout<<"returned";
        m_solenoidActivated = false;
    }
}
void LauncherSubsystem::teleopEnd() {
	
}
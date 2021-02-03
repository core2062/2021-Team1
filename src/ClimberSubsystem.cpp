#include "ClimberSubsystem.h"

ClimberSubsystem::ClimberSubsystem() : m_stilt1(CLIMBER_1_PORT),
                                       m_stilt2(CLIMBER_2_PORT) {

                                      }

void ClimberSubsystem::robotInit() {
    initTalons();
}

void ClimberSubsystem::teleopInit() {
    initTalons();
}

void ClimberSubsystem::teleop() {

}

void ClimberSubsystem::initTalons(){
    m_stilt1.Set(ControlMode::PercentOutput, 0);
    m_stilt2.Set(ControlMode::PercentOutput, 0);
    m_stilt1.SetInverted(true);
    m_stilt2.SetInverted(true);
}

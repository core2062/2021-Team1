#include "ClimberSubsystem.h"

ClimberSubsystem::ClimberSubsystem() :  m_stilt1(CLIMBER_1_PORT),
                                        m_stilt2(CLIMBER_2_PORT),
                                        m_stilt1Gear(CLIMBER_2_PORT_GEAR),
                                        m_stilt2Gear(CLIMBER_2_PORT_GEAR)
                                      {}

void ClimberSubsystem::robotInit() {
    initTalons();
    driverJoystick->RegisterButton(CORE::COREJoystick::LEFT_TRIGGER);
    driverJoystick->RegisterAxis(CORE::COREJoystick::LEFT_STICK_Y);
}

void ClimberSubsystem::teleopInit() {
    initTalons();
}

void ClimberSubsystem::teleop() {
    if (driverJoystick->GetRisingEdge(CORE::COREJoystick::LEFT_TRIGGER) && (m_stilt1.GetSelectedSensorPosition(0) && m_stilt2.GetSelectedSensorPosition(0)) < m_stiltLenthInTicks) {
        m_stilt1.Set(ControlMode::PercentOutput, 0.5);
        m_stilt2.Set(ControlMode::PercentOutput, 0.5);
        m_stiltsActivated = true;
    } else if (){

    }else{
        m_stilt1.Set(ControlMode::PercentOutput, 0);
        m_stilt2.Set(ControlMode::PercentOutput, 0);
        m_stiltsActivated = false;
    }

    if (m_stiltsActivated) {
        m_stilt1Gear.Set(ControlMode::PercentOutput, driverJoystick->GetAxis(CORE::COREJoystick::LEFT_STICK_Y));
        m_stilt2Gear.Set(ControlMode::PercentOutput, driverJoystick->GetAxis(CORE::COREJoystick::LEFT_STICK_Y));
    } else {
        m_stilt1Gear.Set(ControlMode::PercentOutput, 0);
        m_stilt2Gear.Set(ControlMode::PercentOutput, 0);
    }
}

void ClimberSubsystem::initTalons(){
    m_stilt1.Set(ControlMode::PercentOutput, 0);
    m_stilt2.Set(ControlMode::PercentOutput, 0);
    m_stilt1Gear.Set(ControlMode::PercentOutput, 0);
    m_stilt2Gear.Set(ControlMode::PercentOutput, 0);
    m_stilt1.SetInverted(true);
    m_stilt2.SetInverted(true);
    m_stilt1Gear.SetInverted(true);
    m_stilt2Gear.SetInverted(true);
}

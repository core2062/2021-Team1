#include "ConveyorSubsystem.h"

ConveyorSubsystem::ConveyorSubsystem() : conveyorSpeed("Conveyor Speed", 0.75),
                                         m_conveyorMotor(CONVEYOR_PORT_1) {
}

void ConveyorSubsystem::robotInit(){
    initTalons();
    driverJoystick->RegisterButton(CORE::COREJoystick::Y_BUTTON);
}

void ConveyorSubsystem::teleopInit() {
    initTalons();
}

void ConveyorSubsystem::teleop(){
    if (driverJoystick->GetRisingEdge(CORE::COREJoystick::Y_BUTTON) && (m_conveyerAngleMotor.GetSelectedSensorPosition(0) < m_tiltAngleInTicks)) {
        m_tiltActivator = 1;
    } else if (m_conveyerAngleMotor.GetSelectedSensorPosition(0) >= m_tiltAngleInTicks) {
        m_tiltActivator = 0;
    } else if (driverJoystick->GetRisingEdge(CORE::COREJoystick::Y_BUTTON) && (m_conveyerAngleMotor.GetSelectedSensorPosition(0) >= m_tiltAngleInTicks)) {
        m_tiltActivator = 2;
    }

    if (m_tiltActivator == 1) {
        m_conveyerAngleMotor.Set(ControlMode::PercentOutput, -0.5);
        m_tiltActivated = true;
    } else if (m_tiltActivator == 0) {
        m_conveyerAngleMotor.Set(ControlMode::PercentOutput, 0);
    } else if (m_tiltActivator == 2) {
        m_conveyerAngleMotor.Set(ControlMode::PercentOutput, 0.5);
        m_tiltActivated = true;
    }


    if (operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::LEFT_TRIGGER)) {
        setMotor(conveyorSpeed.Get());
    } else if(operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::LEFT_BUTTON)) {
        setMotor(-conveyorSpeed.Get());
    } else {
        setMotor(0.0);
    }
   
}

void ConveyorSubsystem::initTalons(){
    m_conveyorMotor.Set(ControlMode::PercentOutput, 0);
    m_conveyorMotor.Set(ControlMode::PercentOutput, 0);
    m_conveyorMotor.SetInverted(true);
    m_conveyorMotor.SetInverted(true);
}

void ConveyorSubsystem::setMotor(double conveyorSpeed){
    m_conveyorMotor.Set(ControlMode::PercentOutput, conveyorSpeed); 
}

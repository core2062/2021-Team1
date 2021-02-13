#include "ConveyorSubsystem.h"

ConveyorSubsystem::ConveyorSubsystem() : conveyorSpeed("Conveyor Speed", 0.75),
                                         m_conveyorMotor(CONVEYOR_PORT_1) {
}

void ConveyorSubsystem::robotInit(){
    initTalons();
}

void ConveyorSubsystem::teleopInit() {
    initTalons();
}

void ConveyorSubsystem::teleop(){
    if (driverJoystick->GetRisingEdge(CORE::COREJoystick::Y_BUTTON) && (m_conveyerAngle.GetSelectedSensorPosition(0))) {
        tiltAngle();
        m_tiltActivated = !m_tiltActivated;
    } else if ()

    if(operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::LEFT_TRIGGER)) {
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

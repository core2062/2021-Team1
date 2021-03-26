#include "ConveyorSubsystem.h"

ConveyorSubsystem::ConveyorSubsystem() : conveyorSpeed(0.5),
                                         m_conveyorMotor(CONVEYOR_PORT_1) {
}

void ConveyorSubsystem::robotInit(){
    initTalons();
    
    operatorJoystick->RegisterButton(CORE::COREJoystick::LEFT_BUTTON);
    operatorJoystick->RegisterButton(CORE::COREJoystick::LEFT_TRIGGER);
}

void ConveyorSubsystem::teleopInit() {
    initTalons();
}

void ConveyorSubsystem::teleop(){
    frc::SmartDashboard::PutNumber("Conveyor In Speed",conveyorSpeed);
    if (operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::LEFT_BUTTON)) {
        setMotor(conveyorSpeed);
    } else if(operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::LEFT_TRIGGER)) {
        setMotor(-0.75);
    } else {
        setMotor(0.0);
    }
   
}

void ConveyorSubsystem::initTalons(){
    m_conveyorMotor.Set(ControlMode::PercentOutput, 0);
    m_conveyorMotor.SetInverted(true);
}

void ConveyorSubsystem::setMotor(double conveyorSpeed){
    m_conveyorMotor.Set(ControlMode::PercentOutput, conveyorSpeed); 
}

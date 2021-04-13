#include "ClimberSubsystem.h"

ClimberSubsystem::ClimberSubsystem() : m_stilt1(CLIMBER_1_PORT),
                                       m_stilt2(CLIMBER_2_PORT),
                                       m_encoderEndPosition("encoder position goal", 1000) {

                                      }

void ClimberSubsystem::robotInit() {
    initTalons();
}

void ClimberSubsystem::teleopInit() {
    
    driverJoystick->RegisterButton(CORE::COREJoystick::X_BUTTON);
    initTalons();
}

void ClimberSubsystem::teleop() {
    // Check for a request to switch position
    if (driverJoystick->GetRisingEdge(CORE::COREJoystick::X_BUTTON)) {
        m_stiltsEngaged = !m_stiltsEngaged;
    }

    // Get current encoder position
    double encoder1Position = m_stilt1.GetSelectedSensorPosition();
    double encoder2Position = m_stilt2.GetSelectedSensorPosition();

    // Calculate target encoder distance
    double encoder1Distance = encoder1Position - m_encoder1StartUpPosition;
    double encoder2Distance = encoder2Position - m_encoder2StartUpPosition;
    //TODO: move the motor to target the correct distance
    if(!(encoder1Distance == m_encoderEndPosition.Get() || encoder1Distance < m_encoderEndPosition.Get()) && m_stiltsEngaged){
        m_stilt1.Set(ControlMode::PercentOutput, 0.25);
        m_stilt2.Set(ControlMode::PercentOutput, 0.25);
    }else if (!((encoder1Distance == 0 || encoder1Distance < 0))){
        m_stilt1.Set(ControlMode::PercentOutput, -0.25);
        m_stilt2.Set(ControlMode::PercentOutput, -0.25);
    } else{
        m_stilt1.Set(ControlMode::PercentOutput, 0);
        m_stilt2.Set(ControlMode::PercentOutput, 0);  
    }
}

void ClimberSubsystem::initTalons(){
    m_stilt1.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 0);
    m_stilt2.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 0);

    m_encoder1StartUpPosition = m_stilt1.GetSelectedSensorPosition();
    m_encoder2StartUpPosition = m_stilt1.GetSelectedSensorPosition();
}

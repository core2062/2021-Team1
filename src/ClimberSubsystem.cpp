#include "ClimberSubsystem.h"

ClimberSubsystem::ClimberSubsystem() : m_stilt1(CLIMBER_1_PORT),
                                       m_stilt2(CLIMBER_2_PORT) {

                                      }

void ClimberSubsystem::robotInit() {
    initTalons();
}

void ClimberSubsystem::teleopInit() {
    
    driverJoystick->RegisterButton(STILT_ENGAGE_BUTTON);
    initTalons();
}

void ClimberSubsystem::teleop() {
    // Check for a request to switch position
    if (driverJoystick->GetRisingEdge(STILT_ENGAGE_BUTTON)) {
        m_stiltsEngaged = !m_stiltsEngaged;
    }

    // Get current encoder position
    double encoder1Position = m_stilt1.GetSelectedSensorPosition();
    double encoder2Position = m_stilt2.GetSelectedSensorPosition();

    // Calculate target encoder distance
    double encoder1Distance = encoder1Position - m_encoder1StartUpPosition;
    double encoder2Distance = encoder2Position - m_encoder2StartUpPosition;

    double targetDistance = m_stiltsEngaged ? STILT_RISE_DISTANCE : 0.0;

    //TODO: move the motor to target the correct distace
}

void ClimberSubsystem::initTalons(){
    m_stilt1.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 0);
    m_stilt2.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 0);

    m_encoder1StartUpPosition = m_stilt1.GetSelectedSensorPosition();
    m_encoder2StartUpPosition = m_stilt1.GetSelectedSensorPosition();
}

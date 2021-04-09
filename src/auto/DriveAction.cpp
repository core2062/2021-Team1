#include "DriveAction.h"
#include "Robot.h"

DriveAction::DriveAction(driveAction requestedDriveAction):
                                        m_distAutonMoveEncoderTicks("Auton Movement", 6000) {
                                        m_driveAction = requestedDriveAction;

}

void DriveAction::ActionInit() {
    DriveSubsystem* driveSubsystem = &Robot::GetInstance()->driveSubsystem;
    m_encoderStartUpPosition =  driveSubsystem->getRobotPosition();
}

CORE::COREAutonAction::actionStatus DriveAction::Action() {
    DriveSubsystem* driveSubsystem = &Robot::GetInstance()->driveSubsystem;
    double encoderValue = driveSubsystem->getRobotPosition();
    switch(m_driveAction) {
        case FORWARD:
            // Robot::GetInstance()->driveSubsystem.setMotorSpeed(0.5, DriveSide::BOTH);
            if(encoderValue < 7297 + m_encoderStartUpPosition){
                driveSubsystem->setMotorSpeed(0.5, DriveSide::BOTH);
                return COREAutonAction::actionStatus::CONTINUE;
            } else{
                driveSubsystem->setMotorSpeed(0.0, DriveSide::BOTH);
            }
            break;
        case BACKWARD:
            driveSubsystem->toggleGear();
            if(encoderValue > m_encoderStartUpPosition - 87573){
                driveSubsystem->setMotorSpeed(-0.90, DriveSide::BOTH);
                return COREAutonAction::actionStatus::CONTINUE;
            } else{
                driveSubsystem->setMotorSpeed(0.0, DriveSide::BOTH);
            }
            driveSubsystem->toggleGear();
            break;
    }
    return COREAutonAction::actionStatus::END;
}

void DriveAction::ActionEnd() {
}
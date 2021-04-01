#include "LaunchAction.h"
#include "Robot.h"

LaunchAction::LaunchAction(launchAction requestedLaunchAction) {
    m_launchAction = requestedLaunchAction;
}

void LaunchAction::ActionInit() {
}

CORE::COREAutonAction::actionStatus LaunchAction::Action() {
    switch(m_launchAction) {
        case LAUNCHER_ON:
            Robot::GetInstance()->launcherSubsystem.launcherTriggered(false);
            break;
        case LAUNCHER_OFF:
            Robot::GetInstance()->launcherSubsystem.launcherTriggered(true);
            break;
    }
    return COREAutonAction::actionStatus::END;
} 

void LaunchAction::ActionEnd() {

}

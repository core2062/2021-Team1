#pragma once

#include <CORERobotLib.h>
#include "LauncherSubsystem.h"

using namespace CORE;

enum launchAction {
    LAUNCHER_ON,
    LAUNCHER_OFF
};

class LaunchAction : public COREAutonAction {
public:
    LaunchAction(launchAction requestedLaunchAction);
    void ActionInit() override;
    CORE::COREAutonAction::actionStatus Action() override;
    void ActionEnd() override;
private:
    launchAction m_launchAction;
};